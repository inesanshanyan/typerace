#include "../includes/controller/controller.hpp"
#include <ncurses.h>


MenuState* MenuState::instance = nullptr;

MenuState::MenuState(Controller *controller)
{
    this->controller = controller;

    //TODO make it global
    std::pair<int, int> screen_size(0,0);
    screen_size = get_screen_size();
    
    menu = new Menu({"start", "login", "pause", "stats", "settings","end"});
    menu->mainWindow = newwin(MENU_MAIN_WINDOW_H,
                    MENU_MAIN_WINDOW_W,
                    (screen_size.first / 2) - (MENU_MAIN_WINDOW_H / 2),
                    (screen_size.second / 2) - (MENU_MAIN_WINDOW_W / 2));
};

MenuState& MenuState::getInstance(Controller* controller) {
    if(instance == nullptr){
        instance =  new MenuState(controller);
    }
    return *instance;
}

void MenuState::draw()
{
    controller->view->drawMenu(menu);
};

void MenuState::handleInput()
{
    draw();
    int key = controller->view->getControlKey();
    if(key == 10){
        if (*menu->currentItem == "start")
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
        else if(*menu->currentItem == "login")
        {
            controller->state = &LoginState::getInstance(controller);
        }
        else if (*menu->currentItem == "stats") {
            controller->state = &StatsState::getInstance(controller);
        }
        else if (*menu->currentItem == "settings") {
            if (controller->model->player->entered)
            {
                controller->state = &SettingState::getInstance(controller);
            }
            else
            {
                controller->model->errors->lastError = "Login before setting a user.";
                controller->view->clear();
                controller->state = &MessageState::getInstance(controller);
            }
        }
    }else if (key == KEY_UP){
        menu->changeOption(0);
    }else if(key == KEY_DOWN){
        menu->changeOption(1);
    }else if(key == KEY_LEFT){
        changeMenuState();
    }
};

void MenuState::changeMenuState(const std::vector<std::string> options)
{
    menu->prevItems.push_back(options);
    menu->options = menu->prevItems.back();
    menu->currentItem = menu->options.begin();
}

void MenuState::changeMenuState()
{  
    if (menu->prevItems.size() > 1)
    {
        menu->prevItems.pop_back();
        menu->options = menu->prevItems.back();
        menu->currentItem = menu->options.begin();
    }   
}

void MenuState::changeState(){
    // con.begin()ller->state = new GameState(controller);
}

Menu* MenuState::getMenu()
{
    
}