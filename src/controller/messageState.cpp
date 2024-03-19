#include "../includes/controller/controller.hpp"

MessageState* MessageState::instance = nullptr;

MessageState::MessageState(Controller *controller)
{
    this->controller = controller;
};

MessageState& MessageState::getInstance(Controller* controller) {
    if(instance == nullptr){
        instance = new MessageState(controller);
    }
    return *instance;
}

void MessageState::draw()
{
    controller->view->drawErrorWindow(controller->model->errors);
}

void MessageState::handleInput()
{
    draw();
    if(controller->view->getLetter() == 27){ // 27 is ESC
        controller->state = controller->prevState.back();
    };
}

void MessageState::changeState(){
    
};

Menu* MessageState::getMenu()
{
    
}