#include "../includes/view/view.hpp"
#include <ncurses.h>

View::View()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

int View::getKey()
{
    int key = getch();
    return key;
}
