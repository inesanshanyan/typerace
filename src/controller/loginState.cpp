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
                controller->state = new GameState(controller);
            }
        }   
    }else if (*controller->model->menu->currentItem == "sign in")
    {
        controller->state = new MenuState(controller);
    }
}



void LoginState::enterLogin(Player *player)
{
    int key = 0;
    
    while(key != 10){//10 is enter
        draw();
        key = controller->view->getLetter();
        
        if(key == 7 && player->login.size() > 0)
        {
            player->login.pop_back();
        }else if (key != 7) // 7 is a backspace
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
        key = controller->view->getLetter();
        
        if(key == 7 && player->password.size() > 0)
        {
            player->password.pop_back();
        }else if (key != 7)
        {
            player->password.push_back(key);
        }
    }
}

void LoginState::changeState(){
    
}