#include "../includes/controller/controller.hpp"
#include <ncurses.h>

LoginState* LoginState::instance = nullptr;

LoginState::LoginState(Controller *controller)
{
    this->controller = controller;
}
LoginState& LoginState::getInstance(Controller* controller) {
    if(instance == nullptr){
        instance = new LoginState(controller);
    }
    return *instance;
}


void LoginState::draw(){
    controller->view->drawLoginBoard(controller->model->player);
}

void LoginState::handleInput()
{
    draw();
    enterLogin(controller->model->player);
    enterPassword(controller->model->player);
    if (*controller->model->menu->currentItem == "sign up")
    {
        Json users = controller->model->getUsers();
        for (const auto& user : users) {
            if (user["login"] == controller->model->player->login &&
                user["password"] == controller->model->player->password)
            {
                controller->model->player->entered = true;
                controller->state = controller->prevState[0];
            }
        }
        if (!controller->model->player->entered)
        {
            controller->model->player->login = "";
            controller->model->player->password = "";
            controller->model->errors->lastError = "You entered a wrong Login or password.";
            controller->state = &MessageState::getInstance(controller);
        }
    }else if (*controller->model->menu->currentItem == "sign in")
    {
        Json users = controller->model->getUsers();
        bool flag = true;

        for (const auto& user : users) {
            if (user["login"] == controller->model->player->login)
            {
                flag = false;
            }
        }
        if (flag)
        {
            Json newUser;
            newUser["login"] = controller->model->player->login;
            newUser["password"] = controller->model->player->password;
            users.push_back(newUser);
            controller->model->setUsers(users);
            controller->model->player->login = "";
            controller->model->player->password = "";
        } else{
            
        }
        controller->state = &MenuState::getInstance(controller);
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

Menu& getMenu()
{
    
}