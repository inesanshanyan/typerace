#include "../includes/controller/controller.hpp"
#include <ncurses.h>
 

GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    controller->view->drawGame(controller->model->board, controller->model->player);
    controller->view->drawBoard(controller->model->board);
}

void GameState::handleInput()
{
    draw();
    static int letterIndex = 0;
    static int wordIndex = 0;

    char key = controller->view->getKey();

    if (key == 32) { // space key
        controller->model->board->changeCurrentWord(1);
        letterIndex = 0;
        controller->view->clearWindow(controller->model->player->mainWindow);
        controller->model->player->currentWord->clear();
    }
    
    else {
        /*if (key == 8 && letterIndex != 0) { // backspace key
            controller->model->player->currentWord->erase(letterIndex, 1);
            --letterIndex;
        }*/
        if (letterIndex < controller->model->board->activeWord->length() && key == controller->model->board->activeWord->at(letterIndex)) {
            controller->model->player->wordCheck = true;
        }
        else {
            controller->model->player->wordCheck = false;
        }
        ++letterIndex;
        if (controller->model->player->currentWord != nullptr) {
            controller->model->player->currentWord->push_back(key);
        }
        else {
            std::cerr << "nullptr smth" << std::endl;
        }

    }
    controller->view->printPlayerInput(controller->model->player);
    
}

void GameState::changeState(){
    
};