#include "../includes/controller/controller.hpp"

MessageState::MessageState(Controller *controller)
{
    this->controller = controller;
};

MessageState& MessageState::getInstance(Controller* controller) {
    static MessageState instance(controller);
    return instance;
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