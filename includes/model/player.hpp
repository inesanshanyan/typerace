#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>
#include <ctime>
#include <chrono>

class Player
{
public:


    WINDOW *mainWindow;
    WINDOW *loginWiondow;

    std::string login = "";
    std::string password = "";
    std::string currentWord;

    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::milliseconds game_duration;

    bool entered = false;    
    bool wordCheck = false;
    int speed = 0;

    Player() : mainWindow(nullptr), currentWord("") {
        
    }
};

#endif