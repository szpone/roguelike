#include "PerlinNoise.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <vector>

class Map;
class Monster;
void draw_map(Map &map);
void draw_status(Monster &player);
void find_initial_position(Map &map, int &x, int &y);
void pick_monster_position(Map &map, int &x, int &y);

class Map {
public:
  int width;
  int height;
  std::vector<char> data;

  char getChar(int x, int y) {
    return data[y * width + x];
  }

  Map(int width, int height) {
    this->width = width;
    this->height = height;

    siv::PerlinNoise perlin(42);

    for(int y = 0; y < height; ++y) {
      for(int x = 0; x < width; ++x) {
        double val = perlin.octaveNoise0_1((0.5+x / (double)width) * 5, (0.5 + y / (double)height) * 5, 2);
        if(val < 0.333) {
          data.push_back('#');
        } else {
          data.push_back('.');
        }
      }
    }
  }
};

class Monster {
  public:
  char character;
  int x, y;
  int hp;
  int attack;

  Monster(int x, int y, char character): x(x), y(y), hp(10), attack(4), character(character) {}

  void brutal_attack(Monster &monster) { 
    monster.hp -= attack;
    if(monster.hp <= 0) {
      monster.die();
    } 
  }

  void die() {
    x = -1;
    y = -1;
  }

  bool isPlayer() {
    return character == '@';
  }
};


enum {
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3,
};


class Game {
public:
  std::vector<Monster> monsters;
  Map &map;

  Game(Map &map, Monster &player): map(map) {
    monsters.push_back(player);
  }

  Monster &getPlayer() {
    return monsters[0];
  }

  void generate_monsters() {
    for(int i = 0; i < 5; ++i) {
      int x, y;
      pick_monster_position(map, x, y);
      monsters.push_back(Monster(x, y, '&'));
    }
  }

  void draw_monsters() {
    for(Monster &monster: monsters) {
      mvaddch(monster.y, monster.x, monster.character);
    }
  }

  void move_monsters() {
    for(Monster &monster: monsters) {
      if (monster.isPlayer()) {
        continue;
      }

      int direction = rand() % 4;
      if(direction == UP) {
        move_monster(monster, monster.x, monster.y - 1);
      } else if(direction == DOWN) {
        move_monster(monster, monster.x, monster.y + 1);
      } else if(direction == LEFT) {
        move_monster(monster, monster.x - 1, monster.y);
      } else if(direction == RIGHT) {
        move_monster(monster, monster.x + 1, monster.y);
        }
    }
  }

  bool check_position(int new_x, int new_y) {
    if (map.getChar(new_x, new_y) == '.' && !has_monster(new_x, new_y) && 
        new_x < map.width && new_y < map.height && new_x >= 0 && new_y >= 0) {
      return true;
    }
    return false;
  }

  void move_monster(Monster &monster, int new_x, int new_y) {
    if (check_position(new_x, new_y)) {
      monster.x = new_x;
      monster.y = new_y;
    } else {
      Monster *pMonster;
      pMonster = find_monster(new_x, new_y);
      if (pMonster) {
        monster.brutal_attack(*pMonster);
      }
    }
  }

  bool has_monster(int x, int y) {
    for (Monster &monster : monsters) {
      if(monster.x == x && monster.y == y) {
        return true;
      }
    }
    return false;
  }

  Monster *find_monster(int x, int y) {
    for(Monster &monster : monsters) {
      if(monster.x == x && monster.y == y) {
        return &monster;
      }
    }
    return nullptr;
  }

  void game_loop(int ch) {
    Monster &player = getPlayer();

    if (ch == 'q' || ch == 'Q')
      return;

    for (;;) {
      redraw();

      ch = getch();

      if (ch == KEY_LEFT) {
        move_monster(player, player.x - 1, player.y);

      } else if (ch == KEY_RIGHT) {
        move_monster(player, player.x + 1, player.y);

      } else if (ch == KEY_UP) {
        move_monster(player, player.x, player.y - 1);

      } else if (ch == KEY_DOWN) {
        move_monster(player, player.x, player.y + 1);
      } else if (ch == 'q' || 'Q') {
        break;
      }
      move_monsters();
      draw_monsters();
    }
  }
  void erasing(int y, int x) { mvaddch(y, x, ' '); }

  void redraw() {
    clear();
    draw_map(map);
    draw_monsters();
    draw_status(getPlayer());
    refresh();
  }
};

int main() {
  initscr();
  clear();
  noecho();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
  printw("Welecome to awesome roguelike");
  initscr();
  
  int ch = getch();
  clear();
  int width, height;
  getmaxyx(stdscr, height, width);
  
  Map map(width, height);
  int y, x;
  find_initial_position(map, x, y);
  Monster player(x, y, '@');
  Game game(map, player);
  game.generate_monsters();
  game.game_loop(ch);
  endwin();
  return 0;

}

void find_initial_position(Map &map, int &xPos, int &yPos) {
  for(int x = 0; x < map.width; ++x) {
    for(int y = 0; y < map.height; ++y) {
      if(map.getChar(x, y) == '.') {
        xPos = x;
        yPos = y;
        return;
      }
    }
  }
}

void pick_monster_position(Map &map, int &xPos, int &yPos) {
  xPos = rand() % map.width;
  yPos = rand() % map.height;
}

void draw_map(Map &map) {
  for(int x = 0; x < map.width; x++) {
    for(int y = 0; y < map.height; y++) {
      mvaddch(y, x, map.getChar(x, y));
    }
  }
}

void draw_status(Monster &player) {
  mvprintw(0, 40, "HP: %d", player.hp);
}

