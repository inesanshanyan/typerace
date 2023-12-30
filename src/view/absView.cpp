#include "../../includes/view/absView.hpp"

#include <iostream>
#include <ncurses.h>

absView::absView() {
    initscr();
    cbreak();
    refresh();
    start_color();
    getmaxyx(stdscr, maxHeight, maxWidth);
    keypad(stdscr, TRUE);
}

void absView::setParameters(int height, int width) {
    winWidth = width;
    winHeight = height;
    startX = (maxWidth - winWidth) / 2;
    startY = (maxHeight - winHeight) / 2;
    
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
}
void absView::exitGame() {
    endwin();
    exit(0);
}
absView::~absView() {
    // ..
}
