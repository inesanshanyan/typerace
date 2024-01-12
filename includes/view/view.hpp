#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include "../includes/model/menu.hpp"
#include "../includes/model/board.hpp"
#include "../includes/model/player.hpp"
#include <ncurses.h>
#include <iostream>
#include <vector>

class View {
public:
    View();
    int getKey();
    void drawGame(Board *, Player *);
    void drawBoard(Board *);
    void drawMenu(Menu *);
    void drawLoginBoard(Player *);
    char getLetter();
    int getControlKey(); 
    void clear();
    void printPlayerInput(Player* player); 

};

#endif // GAMEVIEW_HPP
