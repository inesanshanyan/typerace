#include "../includes/controller/controller.hpp"
#include <ncurses.h>

StatsState::StatsState(Controller* controller)
{
    this->controller = controller;
    currentUser = controller->model->getCurrentUser();
    //check if there is a currentUser if not open the "you need to login" window
}

void StatsState::draw(){
    countStats();
    controller->view->drawErrorWindow(controller->model->errors);
}

void StatsState::changeState() {
    //...
}

void StatsState::handleInput(){
    draw();
}

void StatsState::countStats() {
    std::vector<int> speeds = currentUser["speed"].get<std::vector<int>>();
    controller->model->player->maxSpeed = *std::max_element(speeds.begin(), speeds.end());
    controller->model->errors->lastError = currentUser["login"].get<std::string>() + "\n max speed = " + std::to_string(controller->model->player->maxSpeed);
}

