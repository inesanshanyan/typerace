#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"

class Model {
public:
    Player* player;
    Board* board;
    Menu* menu;
    Model();
};

#endif // GAMEMODEL_HPP
