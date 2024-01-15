#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"
#include "../json/single_include/nlohmann/json.hpp"
#include <fstream>

using Json = nlohmann::json;

class Model {
public:
    Player* player;
    Board* board;
    Menu* menu;
    Model();
    std::vector<std::string> getContentFromFile(const std::string&);
    Json getUsers();
    void setUsers(const Json& );
};

#endif // GAMEMODEL_HPP
