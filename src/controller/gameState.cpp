#include "../includes/controller/controller.hpp"
#include <ncurses.h>
GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    
}

void GameState::handleInput()
{
    printw("game han input"); // Print a string to the window

    this->controller->view->getLetter();
}

void GameState::changeState(){
    
};