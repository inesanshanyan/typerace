#include "../includes/controller/controller.hpp"
#include <ncurses.h>

MenuState* MenuState::instance = nullptr;

MenuState::MenuState(Controller *controller)
{
    this->controller = controller;
};

MenuState& MenuState::getInstance(Controller* controller) {
    if(instance == nullptr){
        instance =  new MenuState(controller);
    }
    return *instance;
}

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
            if (controller->model->player->entered)
            {
                controller->model->player->start_time = std::chrono::high_resolution_clock::now();
                controller->view->clear();
                controller->state = new GameState(controller);
                controller->prevState.push_back(controller->state);
            }else{
                controller->model->errors->lastError = "Login before start Game.\n Press Esc for back go.";
                controller->view->clear();
                controller->state = &MessageState::getInstance(controller);
            }
            
        }
        else if(*controller->model->menu->currentItem == "results")
        {
            // change to another state.
        }else if(*controller->model->menu->currentItem == "login")
        {
            changeMenuState({"sign in", "sign up"});
        }else if(*controller->model->menu->currentItem == "results")
        {
            
        }
        else if(*controller->model->menu->currentItem == "sign up" || 
                *controller->model->menu->currentItem == "sign in")
        {
            controller->state = &LoginState::getInstance(controller);
        }
        else if (*controller->model->menu->currentItem == "stats") {
            controller->state = &StatsState::getInstance(controller);
        }
        else if (*controller->model->menu->currentItem == "settings") {
            controller->state = &SettingState::getInstance(controller);
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
    if (controller->model->menu->prevItems.size() > 1)
    {
        controller->model->menu->prevItems.pop_back();
        controller->model->menu->options = controller->model->menu->prevItems.back();
        controller->model->menu->currentItem = controller->model->menu->options.begin();
    }   
}

void MenuState::changeState(){
    // con.begin()ller->state = new GameState(controller);
}