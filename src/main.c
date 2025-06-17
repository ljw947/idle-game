#include <locale.h>
#include <ncurses.h>

int main() {
    setlocale(LC_ALL, "");

    initscr();
    printw("Hello World");
    refresh();
    getch();

    endwin();

    return 0;
}
