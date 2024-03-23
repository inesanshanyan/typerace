#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include "../includes/model/model.hpp"
#include "../includes/model/menu.hpp"
#include "../includes/model/board.hpp"
#include "../includes/model/player.hpp"
#include "../includes/model/errors.hpp"
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
    void drawSelectable(WINDOW *, std::vector<std::string>, std::string );

    // it can be changeg, instaeda of model maybe some class(Messages).
    void drawErrorWindow(Messeges *);
    int getLetter();
    int getControlKey(); 
    void clear();

    void printPlayerInput(Player*);
    void clearWindow(WINDOW*);
};

#endif // GAMEVIEW_HPP
