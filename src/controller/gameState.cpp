#include "../includes/controller/controller.hpp"
#include <ncurses.h>
GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    controller->view->drawGame(controller->model->board, controller->model->player);
}

void GameState::handleInput()
{
    char key = controller->view->getLetter();
    draw();
}

void GameState::changeState(){
    
};