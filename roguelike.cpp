#include "PerlinNoise.hpp"
#include <iostream>
#include <ncurses.h>
#include <vector>

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

    siv::PerlinNoise perlin(10);

    // data.resize(width * height);
    for(int y = 0; y < height; ++y) {
      for(int x = 0; x < width; ++x) {
        double val = perlin.octaveNoise0_1((0.5+x / (double)width) * 5, (0.5 + y / (double)height) * 5, 2);
        if(val < 0.5) {
          data.push_back('#');
        } else {
          data.push_back('.');
        }
      }
    }
  }
};

void game_loop(Map &map, char main_char, int y, int x, int ch);
void draw_map(Map &map);
void find_initial_position(Map &map, int &x, int &y);
void erasing(int y, int x);


int main() {
  initscr();
  clear();
  noecho();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
  char main_char = '@';
  printw("Welecome to awesome roguelike");
  initscr();
  
  int ch = getch();
  clear();
  int width, height;
  getmaxyx(stdscr, height, width);
  

  Map map(width, height);
  draw_map(map);
  int y, x;
  find_initial_position(map, x, y);
  game_loop(map, main_char, y, x, ch);
  endwin();
  return 0;


  /*
  Map map(width, height);
  Game game(map, '@');
  Game.loop();

  */
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

void draw_map(Map &map) {
  for(int x = 0; x < map.width; x++) {
    for(int y = 0; y < map.height; y++) {
      //mvaddch(j, i, map.data[j * map.width + i]);
      mvaddch(y, x, map.getChar(x, y));
    }
  }
}




void game_loop(Map &map, char main_char, int y, int x, int ch) {

  if (ch == 'q' || ch == 'Q')
    return;

  mvaddch(y, x, main_char);
  refresh();

  for (;;) {
    ch = getch();

    if (ch == KEY_LEFT) {
      erasing(y, x);
      if(map.getChar(x - 1, y) == '.') {
        x = x - 1;
      }
      mvaddch(y, x, main_char);
      refresh();
    } else if (ch == KEY_RIGHT) {
      erasing(y, x);
      if(map.getChar(x + 1, y) == '.') {
        x = x + 1;
      }
      mvaddch(y, x, main_char);
      refresh();
    } else if (ch == KEY_UP) {
      erasing(y, x);
      if(map.getChar(x, y - 1) == '.') {
        y = y - 1;
      }
      mvaddch(y, x, main_char);
      refresh();
    } else if (ch == KEY_DOWN) {
      erasing(y, x);
      if(map.getChar(x, y + 1) == '.') {
        y = y + 1;
      }
      mvaddch(y, x, main_char);
      refresh();
    } else if (ch == 'q' || 'Q') {
      break;
    }
  }
}

void erasing(int y, int x) { mvaddch(y, x, ' '); }