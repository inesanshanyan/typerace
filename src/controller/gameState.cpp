#include "../includes/controller/controller.hpp"
#include <ncurses.h>
GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    controller->view->drawGame(controller->model->board, controller->model->player);
    controller->view->drawBoard(controller->model->board);
}

void GameState::handleInput()
{
    draw();
    char key = controller->view->getLetter();
    if(key == ' '){
        controller->model->board->changeCurrentWord(1);
    }else if (key == 'q')
    {
        controller->model->board->changeCurrentWord(0);
    }
}

void GameState::changeState(){
    
};