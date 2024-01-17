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
    int key = controller->view->getLetter();
    if (key == ' ' && controller->model->player->wordCheck) { // space key
        controller->model->board->changeCurrentWord(1);
        controller->view->clearWindow(controller->model->player->mainWindow);
        controller->model->player->currentWord.clear();
    }else if(key == KEY_BACKSPACE &&
        controller->model->player->currentWord.size() > 0){
        controller->model->player->currentWord.pop_back();
        checkWord();
    }
    else if(key != KEY_BACKSPACE){
        controller->model->player->currentWord.push_back(key);
        checkWord();
    }
    controller->view->printPlayerInput(controller->model->player);
}

void GameState::checkWord()
{
    bool checked = true;
    for (size_t i = 0; i < controller->model->player->currentWord.size(); i++)
    {   
        if (controller->model->player->currentWord[i] != controller->model->board->activeWord->c_str()[i])
        {
            checked = false;
        }
    }
    if (checked)
    {
        controller->model->player->wordCheck = true;
    }else{
        controller->model->player->wordCheck = false;
    }
}

void GameState::changeState(){
    
};