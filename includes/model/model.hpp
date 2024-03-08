#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "menu.hpp"
#include "board.hpp"
#include "player.hpp"
#include "errors.hpp"
#include "../json/single_include/nlohmann/json.hpp"
#include <fstream>

#define MENU_MAIN_WINDOW_H 15 
#define MENU_MAIN_WINDOW_W 20


#define BOARD_MAIN_WINDOW_H 30
#define BOARD_MAIN_WINDOW_W 70


#define ERROR_MAIN_WINDOW_H 15
#define ERROR_MAIN_WINDOW_W 70


#define PLAYER_MAIN_WINDOW_H 10
#define PLAYER_MAIN_WINDOW_W 70

#define PLAYER_LOGIN_WINDOW_H 15
#define PLAYER_LOGIN_WINDOW_W 70

using Json = nlohmann::json;

class Model {
public:
    Player* player;
    Board* board;
    Menu* menu;
    Messeges* errors;

    Model();
    Json getUsers();
    void setUsers(const Json& );
    Json getCurrentUser();
    std::vector<std::string> getContentFromFile(const std::string&);
};

#endif // GAMEMODEL_HPP
