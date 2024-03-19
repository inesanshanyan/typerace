#include "../includes/controller/controller.hpp"
#include <ncurses.h>

SettingState* SettingState::instance = nullptr;

SettingState::SettingState(Controller *controller)
{
    this->controller = controller;
}
SettingState& SettingState::getInstance(Controller *controller) {
    if(instance == nullptr){
        instance = new SettingState(controller);
    }
    return *instance;
}

void SettingState::draw(){
    if (isMenuOn)
    {
        controller->view->drawMenu(controller->model->settingMenu);
    }
}

void SettingState::handleMenuInput(int key)
{
    if(key == 10){
        isMenuOn = false;
        if(*controller->model->settingMenu->currentItem == "speed type")
        {
            isTypeSpeed = true;
            isDifficultyMode = false;
        }
        else if(*controller->model->settingMenu->currentItem == "mode")
        {
            isDifficultyMode = true;
            isTypeSpeed = false;
        }
    }
    else if (key == KEY_UP){
        controller->model->settingMenu->changeOption(0);
    }
    else if(key == KEY_DOWN){
        controller->model->settingMenu->changeOption(1);
    }
    else if(key == KEY_LEFT){
        controller->state = &MenuState::getInstance(controller);
    }
}

void SettingState::handleSpeedTypeSelecting(int key)
{

}

void SettingState::handleDifficultyModeSelecting(int key)
{

}

void SettingState::handleInput()
{
    draw();
    int key = controller->view->getControlKey();
    if (isMenuOn) {
        handleMenuInput(key);
    } else {
        if(isTypeSpeed)
        {
            handleSpeedTypeSelecting(key);
        } else if (isDifficultyMode)
        {
            handleDifficultyModeSelecting(key);
        }
    }
}

void SettingState::changeState()
{

}

Menu& getMenu()
{

}