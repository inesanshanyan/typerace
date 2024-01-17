#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>

class Player
{
public:
    WINDOW *mainWindow;
    WINDOW *loginWiondow;
    WINDOW *exceptionWindow;
    std::string login = "";
    std::string password = "";
    bool entered = false;
    std::string currentWord;
    bool wordCheck;

    Player() : mainWindow(nullptr), currentWord("") {
        // ...
    }
};

#endif