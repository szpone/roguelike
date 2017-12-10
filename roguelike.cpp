#include <iostream>
#include <ncurses.h>

void game_loop(char main_char, int row, int col, int ch);
void erasing(int y, int x);

int main() {
  initscr();
  clear();
  noecho();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
  int row = 10, col = 10;
  char main_char = '@';
  printw("Welecome to awesome roguelike");
  initscr();
  int ch = getch();
  clear();
  game_loop(main_char, row, col, ch);
  endwin();
  return 0;
}

void game_loop(char main_char, int row, int col, int ch) {
  if (ch == 'q' || ch == 'Q')
    return;

  mvaddch(row, col, main_char);
  refresh();

  for (;;) {
    ch = getch();

    if (ch == KEY_LEFT) {
      erasing(row, col);
      col = col - 1;
      mvaddch(row, col, main_char);
      refresh();
    } else if (ch == KEY_RIGHT) {
      erasing(row, col);
      col = col + 1;
      mvaddch(row, col, main_char);
      refresh();
    } else if (ch == KEY_UP) {
      erasing(row, col);
      row = row - 1;
      mvaddch(row, col, main_char);
      refresh();
    } else if (ch == KEY_DOWN) {
      erasing(row, col);
      row = row + 1;
      mvaddch(row, col, main_char);
      refresh();
    } else if (ch == 'q' || 'Q') {
      break;
    }
  }
}

void erasing(int y, int x) { mvaddch(y, x, '#'); }