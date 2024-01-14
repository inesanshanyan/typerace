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
            changeMenuState({"sign in", "sign up"});
        }else if(*controller->model->menu->currentItem == "results")
        {
            
        }
        else if(*controller->model->menu->currentItem == "sign in")
        {
            
        }
        else if(*controller->model->menu->currentItem == "sign up")
        {
            
        }
    }else if (key == KEY_UP){
        controller->model->menu->changeOption(0);
    }else if(key == KEY_DOWN){
        controller->model->menu->changeOption(1);
    }else if(key == KEY_LEFT){
        changeMenuState();
    }
};

void MenuState::changeMenuState(const std::vector<std::string> options)
{
    controller->model->menu->prevItems.push_back(options);
    controller->model->menu->options = controller->model->menu->prevItems.back();
    controller->model->menu->currentItem = controller->model->menu->options.begin();
}

void MenuState::changeMenuState()
{  
    controller->model->menu->prevItems.pop_back();
    controller->model->menu->options = controller->model->menu->prevItems.back();
    controller->model->menu->currentItem = controller->model->menu->options.begin();
}

void MenuState::changeState(){
    // con.begin()ller->state = new GameState(controller);
};