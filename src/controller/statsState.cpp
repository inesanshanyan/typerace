#include "../includes/controller/controller.hpp"
#include <ncurses.h>

StatsState* StatsState::instance = nullptr;

StatsState::StatsState(Controller* controller)
{
    this->controller = controller;
    controller->model->player->currentUser = controller->model->getCurrentUser();
    //check if there is a currentUser if not open the "you need to login" window
}

StatsState& StatsState::getInstance(Controller* controller){
    if(instance == nullptr){
        instance = new StatsState(controller);
    }
    return *instance;
}

void StatsState::draw(){
    if (controller->model->player->currentUser.empty()) {
        controller->model->errors->lastError = "log in to view stats";
    }
    else {
        countStats();
    }
    controller->state = controller->prevState[0];
    controller->state = &MessageState::getInstance(controller);
    //controller->view->drawErrorWindow(controller->model->errors);

}

void StatsState::changeState() {
    //...
}

void StatsState::handleInput(){
    draw();
}

void StatsState::countStats() {
    std::vector<int> speeds = controller->model->player->currentUser["speed"].get<std::vector<int>>();
    if (!speeds.empty()) {
        controller->model->player->maxSpeed = *std::max_element(speeds.begin(), speeds.end());
    }
    setMaxSpeed(controller->model->player->maxSpeed);
    controller->model->errors->lastError = controller->model->player->currentUser["login"].get<std::string>() +
        "\n max speed = " + std::to_string(controller->model->player->maxSpeed);
}

void StatsState::setMaxSpeed(int speed) {
    controller->model->player->currentUser["best_speed"] = speed;
    Json users = controller->model->getUsers();
    for (auto& user : users) {
        if (user["login"].get<std::string>() == controller->model->player->login) {
            user = controller->model->player->currentUser;
            break;
        }
    }
    controller->model->setUsers(users);
}

