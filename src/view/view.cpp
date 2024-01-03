#include "../includes/view/view.hpp"
#include <ncurses.h>

View::View()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    printw("Hello, ncurses!"); // Print a string to the window

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

char View::getControlKey(){    
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
    // delete below
    else if(key == 'q')
    {
        exit_curses(TRUE);
    }
    return 0;
}

void View::drawGame()
{

}

void View::drawMenu()
{

}