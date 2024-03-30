#include "../includes/controller/controller.hpp"
#include <ncurses.h>

SettingState* SettingState::instance = nullptr;

SettingState::SettingState(Controller *controller)
{
    this->controller = controller;

    //TODO make it globla
    std::pair<int, int> screen_size(0,0);
    screen_size = get_screen_size();

    menu = new Menu({"speed type","mode"});
    menu->mainWindow = newwin(MENU_MAIN_WINDOW_H,
                            MENU_MAIN_WINDOW_W,
                    (screen_size.first / 2) - (MENU_MAIN_WINDOW_H / 2),
                    (screen_size.second / 2) - (MENU_MAIN_WINDOW_W / 2));
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
        controller->view->drawMenu(menu);
    } else {
        if (*menu->currentItem == "speed type")
        {
            controller->view->drawSelectable(this->menu->mainWindow, this->speedTypeItems, controller->model->player->speedType);
        }
        else if(*menu->currentItem == "mode")
        {
            controller->view->drawSelectable(this->menu->mainWindow, this->difficultyModeItems, controller->model->player->difficultyMode);
        }
    }
}

void SettingState::handleMenuInput(int key)
{
    if(key == 10){
        isMenuOn = false;
    }
    else if (key == KEY_UP){
        menu->changeOption(0);
    }
    else if(key == KEY_DOWN){
        menu->changeOption(1);
    }
    else if(key == KEY_LEFT){
        controller->state = &MenuState::getInstance(controller);
    }
}

void SettingState::handleSpeedTypeSelecting(int key)
{  
    Player *player = controller->model->player;
    auto it = std::find(speedTypeItems.begin(), speedTypeItems.end(), player->speedType);
    if(key == 10){
        isMenuOn = true;
        player->currentUser["speed_type"] = *it;
        controller->model->setUserSettings(player->currentUser);
    } else if (key == KEY_UP){
        if (it != speedTypeItems.end() && (it - speedTypeItems.begin()) > 0) {
            it--;
            player->speedType = *it;
        }
    } else if(key == KEY_DOWN){
        if (it != speedTypeItems.end() - 1) {
            it++;
            player->speedType = *it;
        }
    }

}

void SettingState::handleDifficultyModeSelecting(int key)
{
    Player *player = controller->model->player;
    auto it = std::find(difficultyModeItems.begin(), difficultyModeItems.end(), player->difficultyMode);
    if(key == 10){
        isMenuOn = true;
        player->currentUser["difficulty_mode"] = *it;
        controller->model->setUserSettings(player->currentUser);
    } else if (key == KEY_UP){
        if (it != difficultyModeItems.end() && (it - difficultyModeItems.begin()) > 0) {
            it--;
            player->difficultyMode = *it;
        }
    } else if(key == KEY_DOWN){
        if (it != difficultyModeItems.end() - 1) {
            it++;
            player->difficultyMode = *it;
        }
    }

}

void SettingState::handleInput()
{
    draw();
    int key = controller->view->getControlKey();
    if (isMenuOn) {
        handleMenuInput(key);
    } else {
        if (*menu->currentItem == "speed type")
        {
            handleSpeedTypeSelecting(key);
        }
        else if(*menu->currentItem == "mode")
        {
            handleDifficultyModeSelecting(key);
        }
    }
}

void SettingState::changeState()
{
}

Menu* SettingState::getMenu()
{
    return menu;
}