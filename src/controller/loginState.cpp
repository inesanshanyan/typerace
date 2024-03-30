#include "../includes/controller/controller.hpp"
#include <ncurses.h>

LoginState* LoginState::instance = nullptr;

LoginState::LoginState(Controller *controller)
{
    this->controller = controller;

    //TODO make it global
    std::pair<int, int> screen_size(0,0);
    screen_size = get_screen_size();
    
    menu = new Menu({"sign in","sign up"});
    menu->mainWindow = newwin(MENU_MAIN_WINDOW_H,
                    MENU_MAIN_WINDOW_W,
                    (screen_size.first / 2) - (MENU_MAIN_WINDOW_H / 2),
                    (screen_size.second / 2) - (MENU_MAIN_WINDOW_W / 2));
}
LoginState& LoginState::getInstance(Controller* controller) {
    if(instance == nullptr){
        instance = new LoginState(controller);
    }
    return *instance;
}


void LoginState::draw(){
    if (isMenuOn)
    {
        controller->view->drawMenu(menu);
    } else 
    {
        controller->view->drawLoginBoard(controller->model->player);
    }
}

void LoginState::handleMenuInput(int key)
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


void LoginState::handleSignUp()
{
    Player *player = controller->model->player;
    enterLogin(player);
    enterPassword(player);

    Json users = controller->model->getUsers();
    for (const auto& user : users) {
        if (user["login"] == player->login &&
            user["password"] == player->password)
        {
            player->entered = true;
            player->currentUser = user;
            controller->state = controller->prevState[0];
        }
    }
    if (!player->entered)
    {
        player->login = "";
        player->password = "";
        controller->model->errors->lastError = "You entered a wrong Login or password.";
        controller->state = &MessageState::getInstance(controller);
    } else {
        player->start_time = std::chrono::high_resolution_clock::now();
        controller->view->clear();
        controller->state = new GameState(controller);
    }
    isMenuOn = true;
};

void LoginState::handleSignIn()
{
    Player *player = controller->model->player;
    enterLogin(player);
    enterPassword(player);

    bool flag = true;
    Json users = controller->model->getUsers();
    for (const auto& user : users) {
        if (user["login"] == player->login)
        {
            flag = false;
        }
    }
    if (flag)
    {
        //TODO move this part inside a model (createUser) for example (if checked let me know).
        Json newUser;
        newUser["login"] = player->login;
        newUser["password"] = player->password;
        // i think below to line hould be inside a setSettings function. what you think?
        newUser["difficulty_mode"] = "easy";
        newUser["speed_type"] = "wpm";
        users.push_back(newUser);
        controller->model->setUsers(users);
        player->login = "";
        player->password = "";
    } else{
        
    }
    controller->state = &MenuState::getInstance(controller);
    isMenuOn = true;
};

void LoginState::handleInput()
{
    draw();
    int key = controller->view->getControlKey();
    if (isMenuOn) {
        handleMenuInput(key);
    } else {
        if (*menu->currentItem == "sign in")
        {
            handleSignIn();
        }
        else if(*menu->currentItem == "sign up")
        {
            handleSignUp();
        }
    }
}

void LoginState::enterLogin(Player *player)
{
    int key = 0;
    
    while(key != 10){//10 is enter
        draw();
        key = controller->view->getKey();
        
        if(key == KEY_BACKSPACE && player->login.size() > 0)
        {
            player->login.pop_back();
        }else if (key != KEY_BACKSPACE && key != 10) // 7 is a backspace
        {
            player->login.push_back(key);
        }
    }
}

void LoginState::enterPassword(Player *player)
{
    int key = 0;
    
    while(key != 10){
        draw();
        key = controller->view->getKey();
        
        if(key == KEY_BACKSPACE && player->password.size() > 0)
        {
            player->password.pop_back();
        }else if (key != KEY_BACKSPACE && key != 10)
        {
            player->password.push_back(key);
        }
    }
}

void LoginState::changeState(){
    
}

Menu* LoginState::getMenu()
{
    return menu;
}