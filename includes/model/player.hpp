#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>
#include <ctime>
#include <chrono> 
#include "../../json/single_include/nlohmann/json.hpp"

class Player
{
public:
    WINDOW *mainWindow;
    WINDOW *loginWiondow;
    WINDOW *settingWindow;

    std::string login = "";
    std::string password = "";
    std::string currentWord;
    std::string speedType = "wpm";
    std::string difficultyMode = "medium";

    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::milliseconds game_duration;

    bool entered = false;    
    bool wordCheck = false;
    int speed = 0;
    int maxSpeed = 0;
    nlohmann::json currentUser;

    Player() : mainWindow(nullptr), currentWord("") {
        
    }
};

#endif