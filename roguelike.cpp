#include "PerlinNoise.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <vector>

class Map;
void draw_map(Map &map);
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
  char monster_char = '&';
  int x, y;
  int hp;
  int attack; 

  Monster(int x, int y): x(x), y(y) {
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
  char main_char = '@';
  std::vector<Monster> monsters;
  Map &map;
  int x, y;

  Game(Map &map, int x, int y): map(map), x(x), y(y) {}

  void generate_monsters() {
    for(int i = 0; i < 5; ++i) {
      int x, y;
      pick_monster_position(map, x, y);
      monsters.push_back(Monster(x, y));
    }
  }

  void draw_monsters() {
    for(Monster &monster: monsters) {
      mvaddch(monster.y, monster.x, monster.monster_char);
    }
  }

  void move_monsters() {
    for(Monster &monster: monsters) {
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

  void move_hero(int new_x, int new_y) {
    if (check_position(new_x, new_y)) {
      x = new_x;
      y = new_y;
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

  void move_monster(Monster &monster, int new_x, int new_y) {
    if(check_position(new_x, new_y)) {
      monster.x = new_x;
      monster.y = new_y;
    }

  }

  void game_loop(int ch) {

    if (ch == 'q' || ch == 'Q')
      return;

    mvaddch(y, x, main_char);
    refresh();

    for (;;) {
      redraw();

      ch = getch();

      if (ch == KEY_LEFT) {
        move_hero(x - 1, y);

      } else if (ch == KEY_RIGHT) {
        move_hero(x + 1, y);

      } else if (ch == KEY_UP) {
        move_hero(x, y - 1);


      } else if (ch == KEY_DOWN) {
        move_hero(x, y + 1);
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
    draw_player();
    refresh();
  }

  void draw_player() {
    mvaddch(y, x, main_char);
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
  Game game(map, x, y);
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

