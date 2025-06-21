#include <ctype.h>
#include <locale.h>
#include <ncurses.h>

#include "stringUtils.h"
#include "tracker.h"

void draw(tracker *tracker) {
  for (size_t i = 0; i < tracker->count; ++i) {
    int col = (i + 1) * 5;
    mvprintw(0, col, "%s", tracker->tickers[i].name);
    mvprintw(1, col, "%s", getString(tracker->tickers[i].count));
  }
}

int main() {
  setlocale(LC_ALL, "");

  initscr();
  halfdelay(5);
  noecho();

  tracker tracker;
  if (!initTickers(&tracker)) {
    mvprintw(0, 0, "Intialising tracker failed. Exiting.");
    return 1;
  }

  if (!addTicker(&tracker)) {
    mvprintw(0, 0, "Couldn't add additional ticker. Exiting.");
    return 1;
  }

  int ret = 0;
  while (ret == 0) {
    draw(&tracker);
    char input = tolower(getch());

    updateTickers(&tracker);

    switch (input) {
    case 'a':
      addTicker(&tracker);
      break;
    case 'q':
      ret = 1;
      break;
    default:
      ret = 0;
      break;
    }

    refresh();
  }

  clear();
  mvprintw(0, 0, "Exiting...");
  endwin();

  clearTickers(&tracker);

  return 0;
}
