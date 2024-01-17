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
                controller->state = new GameState(controller);
            }
        }
        if (!controller->model->player->entered)
        {
            controller->state = new MessageState(controller);
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
        controller->state = new MenuState(controller);
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