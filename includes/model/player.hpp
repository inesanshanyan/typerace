#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>

class Player
{
public:
    WINDOW *mainWindow;
    std::vector<char>* currentWord;
    bool wordCheck;

    Player() : mainWindow(nullptr), currentWord(new std::vector<char>()) {
        // ...
    }

    ~Player() {
        delete currentWord; 
    }
};

#endif