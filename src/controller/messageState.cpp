#include "../includes/controller/controller.hpp"

MessageState::MessageState(Controller *controller)
{
    this->controller = controller;
};

void MessageState::draw()
{
    controller->view->drawErrorWindow(controller->model->errors);
}

void MessageState::handleInput()
{
    draw();
    if(controller->view->getLetter() == 'q'){
        controller->state = controller->prevState.back();
    };
}

void MessageState::changeState(){
    
};