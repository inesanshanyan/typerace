#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"

class Model {
private:
    Player player;
    Board board;
    Menu menu;
public:
    Model();
    void getDataFromFile();
};

#endif // GAMEMODEL_HPP
