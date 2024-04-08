#include "../includes/controller/controller.hpp"
#include <ncurses.h>

PauseState* PauseState::instance = nullptr;

PauseState::PauseState(Controller *controller) {
    this->controller = controller;
    std::pair<int, int> screen_size(0,0);
    screen_size = get_screen_size();

    menu = new Menu({"Resume","Restart", "Main Menu"});
    menu->mainWindow = newwin(MENU_MAIN_WINDOW_H,
                            MENU_MAIN_WINDOW_W,
                    (screen_size.first / 2) - (MENU_MAIN_WINDOW_H / 2),
                    (screen_size.second / 2) - (MENU_MAIN_WINDOW_W / 2));
}

PauseState& PauseState::getInstance(Controller *controller) {
    if(instance == nullptr){
        instance = new PauseState(controller);
    }
    return *instance;
}

void PauseState::draw() {
    if (isMenuOn) {
        controller->view->drawMenu(menu);
    }
}

void::PauseState::handleInput(){
    if (*menu->currentItem == "Resume") {
        controller->state = controller->prevState.back();
    }
    else if(*menu->currentItem == "Restart") {
        controller->state = new GameState(controller);
    }
    else if(*menu->currentItem == "Main Menu") { 
        controller->state = &MenuState::getInstance(controller);
    }
    
}
void PauseState::handleMenuInput(int key) {
    if(key == 10){
        isMenuOn = false;
    }
    else if (key == KEY_UP){
        menu->changeOption(0);
    }
    else if(key == KEY_DOWN){
        menu->changeOption(1);
    }
}

void PauseState::changeState(){
    
}

Menu* PauseState::getMenu(){
    return menu;
}