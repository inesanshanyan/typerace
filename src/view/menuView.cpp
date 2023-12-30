#include "../../includes/view/menuView.hpp"

#include <string>

menuView::menuView() {
	// ...
}

void menuView::initWindow() {
	absView::setParameters(12, 36);
	title = "MENU";
    options[0] = "Start";
    options[1] = "Statistics";
    options[2] = "Exit";

    window = newwin(winHeight, winWidth, startX, startY);    
    wbkgd(window, COLOR_PAIR(1));
    activeOption = options[0];
    wrefresh(window);
}


void menuView::draw() {
    box(window, 0, 0);
    mvwprintw(window, 2, (winWidth - title.size()) / 2, "%s", title.c_str());
    for (int index = 0; index < optionsNum; ++index) {
        if (options[index] == activeOption) {
            wattron(window, A_BOLD);
            mvwprintw(window, index + 4, 2, "%s", options[index].c_str());
            wattroff(window, A_BOLD);
        }
        else {
            mvwprintw(window, index + 4, 2, "%s", options[index].c_str());
        }
    }

    wrefresh(window);
}

std::string menuView::chooseOption() {
    int key;
    int index = 0;
    while (key != '\n') {
        switch (key) {
        case KEY_UP:
            ++index;
            checkIndex(index);
            break;
        case KEY_DOWN:
            --index;
            checkIndex(index);
            break;
        }
        draw();
    }
    return activeOption;
}

void menuView::checkIndex(int& index) {
    if (index < 0) {
        index = optionsNum - 1;
    }
    else if (index > optionsNum - 1) {
        index = 0;
    }
}
menuView::~menuView() {}
