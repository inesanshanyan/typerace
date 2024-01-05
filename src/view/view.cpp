#include "../includes/view/view.hpp"

#define _window_height 10
#define _window_width 30


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
    box(player->mainWindow, '*', '*');

    wrefresh(player->mainWindow);
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

void View::drawBoard(Board *board){
    box(board->mainWindow, 0, 0);
    int row = 1;
    int col = 1;
    for (const auto& word : board->content) {
        if (col + word.length() + 1 >= 70 - 2) {
            col = 1; 
            row++;
        }
        if (row >= 30 - 4) {
            break;
        }
        mvwprintw(board->mainWindow, row, col, "%s ", word.c_str());
        col += word.length() + 1;
    }
    wrefresh(board->mainWindow);
};