#include "../includes/controller/controller.hpp"
#include <ncurses.h>
#include <chrono>
#include <ctime>

GameState::GameState(Controller *controller)
{
    this->controller = controller;
};

void GameState::draw()
{
    controller->view->drawGame(controller->model->board, controller->model->player);
    controller->view->drawBoard(controller->model->board);
    controller->view->printPlayerInput(controller->model->player);
}

void GameState::handleInput()
{

    draw();
    int key = controller->view->getLetter();
    if (key == ' ' && controller->model->player->wordCheck) {
        if (controller->model->board->activeWord == &controller->model->board->content[controller->model->board->content.size() - 1])
        {
            auto end_time = std::chrono::high_resolution_clock::now();
            controller->model->player->game_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - controller->model->player->start_time);

            controller->model->errors->lastError = "you have typein in  " + std::to_string(controller->model->player->game_duration.count())  + " milliseconds.";
            setSpeed(controller->model->player->game_duration.count());
            //controller->state = new MessageState(controller);
            controller->state = &MenuState::getInstance(controller);
        }
        controller->model->board->changeCurrentWord(1);
        controller->view->clearWindow(controller->model->player->mainWindow);
        controller->model->player->currentWord.clear();
    }else if(key == KEY_BACKSPACE &&
        controller->model->player->currentWord.size() > 0){
        controller->model->player->currentWord.pop_back();
        checkWord();
    }
    else if(key != KEY_BACKSPACE && key != 27){
        controller->model->player->currentWord.push_back(key);
        checkWord();
    }
    else if (key == 27){// ESC
        auto it = std::find_if(controller->prevState.begin(), controller->prevState.end(), [](State* s) {
            // Replace MenuState with the actual class name you are looking for
            return dynamic_cast<MenuState*>(s) != nullptr;
        });
        // controller->state = controller->prevState[0];// TODO change it in the future.
    }
}

void GameState::checkWord()
{
    bool checked = true;
    for (size_t i = 0; i < controller->model->player->currentWord.size(); i++)
    {   
        if (controller->model->player->currentWord[i] != controller->model->board->activeWord->c_str()[i])
            checked = false;
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

void GameState::setSpeed(int time) {
    // controller->model->player->currentUser = controller->model->getCurrentUser(); //I move it into loginstate.
    double currentSpeed = controller->model->board->content.size() * (60 / (double)(time / 1000));
    controller->model->player->currentUser["speed"].push_back(currentSpeed);
    Json users = controller->model->getUsers();
    for (auto& user : users) {
        if (user["login"].get<std::string>() == controller->model->player->login) {
            user = controller->model->player->currentUser;
            break;
        }
    }
    controller->model->setUsers(users);
}

Menu* GameState::getMenu()
{
    return nullptr;
}