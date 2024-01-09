#include "../includes/view/view.hpp"

#define _window_height 10
#define _window_width 30


View::View()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
}

int View::getKey()
{
    int key = getch();
    return key;
}

char View::getLetter(){
    char letter;
    do {
        letter = getch();
    } while ((letter < 'a' || letter > 'z') && letter != ' ' && letter != 27);
    return letter;
}

int View::getControlKey(){    
    int key = getch();
    if ( key == KEY_UP 
        || key == KEY_DOWN 
        || key == KEY_LEFT 
        || key == KEY_RIGHT
        || key == 10
        || key == 'q'
        ) {
        return key;
    }
    return 0;
}

void View::drawGame(Board *board, Player * player)
{
    box(board->mainWindow, 0, 0);
    box(player->mainWindow, '*', '*');

    wrefresh(player->mainWindow);
    wrefresh(board->mainWindow);
}

void View::drawMenu(Menu *menu)
{
    wclear(menu->mainWindow);
    box(menu->mainWindow, 0, 0);
    for (int i = 0; i < menu->options.size(); ++i) {
        if ( &menu->options[i] == menu->currentItem ) {
            mvwprintw(menu->mainWindow, (i + 0.5) * _window_height / menu->options.size(), 2, "----->");
            mvwprintw(menu->mainWindow, (i + 0.5) * _window_height / menu->options.size(), 9, "%s", menu->currentItem->c_str() );
        } else {
            mvwprintw(menu->mainWindow, (i + 0.5) * _window_height / menu->options.size(), 2, "%s", menu->options[i].c_str());
        }
    }
    wrefresh(menu->mainWindow);
}

void View::clear()
{
    wclear(stdscr);
}

char View::playerInput(bool check, std::vector<char>* currentWord, Player* player) {
 
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    if (check == true) {
        wattron(player->mainWindow, COLOR_PAIR(1));
    }
    else {
        wattron(player->mainWindow, COLOR_PAIR(2));
    }
    wclear(player->mainWindow);
    wmove(player->mainWindow, 24, 48); // model player window coords

    for (char c : *currentWord) {
        waddch(player->mainWindow, c);
    }
    wattr_off(player->mainWindow, A_COLOR, NULL);
    box(player->mainWindow, '*', '*'); // for not disappearing
    wrefresh(player->mainWindow);
    char key = getch();
    return key;
}


