#include "../includes/controller/controller.hpp"
#include <ncurses.h>

#include <cstdlib> // for random bool
#include <ctime>   

GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    controller->view->drawGame(controller->model->board, controller->model->player);
}

void GameState::handleInput()
{
    draw();
    //char key = controller->view->getLetter();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    controller->model->player->wordCheck = rand() % 2;

    controller->view->printPlayerInput(controller->model->player);
    char key = controller->view->getKey();
        

    if (controller->model->player->currentWord != nullptr) {
        controller->model->player->currentWord->push_back(key); 
    }
    else {
        std::cerr << "nullptr smth" << std::endl;
    }

}

void GameState::changeState(){
    
};