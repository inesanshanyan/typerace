#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"
#include "errors.hpp"
#include "../json/single_include/nlohmann/json.hpp"
#include <fstream>

using Json = nlohmann::json;

class Model {
public:
    Player* player;
    Board* board;
    Menu* menu;
    Errors* errors;

    Model();
    Json getUsers();
    void setUsers(const Json& );
    std::vector<std::string> getContentFromFile(const std::string&);
};

#endif // GAMEMODEL_HPP
