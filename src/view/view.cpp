#include "../includes/view/view.hpp"

View::View()
{
    initscr();
    cbreak();
    start_color(); // Enable color support
    noecho();
    keypad(stdscr, TRUE);

    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_RED, COLOR_BLACK);
    init_pair(8, COLOR_GREEN, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_BLACK);
    init_pair(10, COLOR_BLACK, COLOR_RED);
}

int View::getKey()
{
    int key = getch();
    return key;
}

int View::getLetter(){
    int letter;
    do {
        letter = getch();
    } while ((letter < ' ' || letter > '~') &&
            letter != KEY_BACKSPACE &&
            letter != 27);
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
    wrefresh(menu->mainWindow);
    box(menu->mainWindow, 0, 0);
    for (int i = 0; i < menu->options.size(); ++i) {
        if (menu->options[i] == *menu->currentItem ) {
            mvwprintw(menu->mainWindow, (i + 0.5) * MENU_MAIN_WINDOW_H / menu->options.size(), 2, "----->");
            mvwprintw(menu->mainWindow, (i + 0.5) * MENU_MAIN_WINDOW_H / menu->options.size(), 9, "%s", menu->currentItem->c_str() );
        } else { 
            mvwprintw(menu->mainWindow, (i + 0.5) * MENU_MAIN_WINDOW_H / menu->options.size(), 2, "%s", menu->options[i].c_str());
        }
    }
    refresh();
    wrefresh(menu->mainWindow);
}

void View::clear()
{
    // wclear(stdscr);
}

void View::drawBoard(Board *board){
    //TODO change all this numbers with CONSTANTS
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

        if (board->activeWord == &word)
        {
            wattron(board->mainWindow, COLOR_PAIR(2));
            mvwprintw(board->mainWindow, row, col, "%s ", word.c_str());
            wattroff(board->mainWindow, COLOR_PAIR(2));
        } else {
            mvwprintw(board->mainWindow, row, col, "%s ", word.c_str());
        }
        col += word.length() + 1;
    }
    wrefresh(board->mainWindow);
};

void View::drawLoginBoard(Player *player) {
    wclear(player->loginWiondow);
    box(player->loginWiondow, '9', '4');

    mvwprintw(player->loginWiondow, 1, 2, "login - %s", player->login.c_str());
    mvwprintw(player->loginWiondow, 3, 2, "password - %s", player->password.c_str());

    wrefresh(player->loginWiondow);
}

void View::drawSelectable(WINDOW* window, std::vector<std::string> options, std::string selectedItem)
{
    wclear(window);
    wrefresh(window);
    box(window, 0, 0);
    for (int i = 0; i < options.size(); ++i) {
        if (options[i] == selectedItem) {
            mvwprintw(window, (i + 0.5) * MENU_MAIN_WINDOW_H / options.size(), 2, "cuurent - ");
            mvwprintw(window, (i + 0.5) * MENU_MAIN_WINDOW_H / options.size(), 11, "%s", selectedItem.c_str());
        } else {
            mvwprintw(window, (i + 0.5) * MENU_MAIN_WINDOW_H / options.size(), 2, "%s", options[i].c_str());
        }
    }
    wrefresh(window);
}

void View::printPlayerInput(Player *player)
{
    if (player->wordCheck == true) {
        wattron(player->mainWindow, COLOR_PAIR(8));
    }
    else {
        wattron(player->mainWindow, COLOR_PAIR(7));
    }
    wclear(player->mainWindow);

    mvwprintw(player->mainWindow, 1, 2, "%s", player->currentWord.c_str());

    wattr_off(player->mainWindow, A_COLOR, NULL);
    box(player->mainWindow, '*', '*');
    wrefresh(player->mainWindow);
}

void View::clearWindow(WINDOW* win) {
    wclear(win);
    refresh();
    wrefresh(win);
}

void View::drawErrorWindow(Messeges* errors){
    wclear(errors->mainWindow);
    box(errors->mainWindow, 'e', 'e');

    mvwprintw(errors->mainWindow, 1, 2, "last - %s", errors->lastError.c_str());

    wrefresh(errors->mainWindow);
};
