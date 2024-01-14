#include "../includes/controller/controller.hpp"
#include <ncurses.h>

LoginState::LoginState(Controller *controller)
{
    this->controller = controller;
}

void LoginState::draw(){
    controller->view->drawLoginBoard(controller->model->player);
}

void LoginState::handleInput()
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

void LoginState::changeState(){
    
}