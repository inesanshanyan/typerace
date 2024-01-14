#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"
#include <fstream>

class Model {
public:
    Player* player;
    Board* board;
    Menu* menu;
    Model();
    std::vector<std::string> getContentFromFile(const std::string&);
};

#endif // GAMEMODEL_HPP
