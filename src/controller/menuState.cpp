#include "../includes/controller/controller.hpp"
#include <ncurses.h>
MenuState::MenuState(Controller *controller)
{
    this->controller = controller;
};

void MenuState::draw()
{
    controller->view->drawMenu(controller->model->menu);
};

void MenuState::handleInput()
{
    draw();
    int key = controller->view->getControlKey();
    if(key == 10){
        if (*controller->model->menu->currentItem == "start")
        {
            controller->view->clear();
            controller->state = new GameState(controller);
        }else if(*controller->model->menu->currentItem == "results")
        {
            // change to another state.
        }else if(*controller->model->menu->currentItem == "login")
        {
            controller->view->clear();
            controller->state = new LoginState(controller);
        }
    }else if (key == KEY_UP){
        controller->model->menu->changeOption(0);
    }else if(key == KEY_DOWN){
        controller->model->menu->changeOption(1);
    }
};

void MenuState::changeState(){
    controller->state = new GameState(controller);
};