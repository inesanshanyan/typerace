#include "../includes/model/model.hpp"

Model::Model(){
    menu = new Menu();
    board = new Board();
    player = new Player();
    // this part is not connected with model but now it will be here.
    //TODO change this numbers to constants
    menu->mainWindow = newwin(15, 20, 5, 5);
    board->mainWindow = newwin(10, 70, 10, 40);
    player->mainWindow = newwin(5, 70, 21, 40);
};