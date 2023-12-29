#include "../includes/controller/controller.hpp"

Controller::Controller(Model* modelPtr, View* viewPtr){
    this->model = modelPtr;
    this->view = viewPtr;
}

void Controller::handleInputAndUpdateGame(){
    if(view->getKey() == 'q')
    {
        abort();
    }
}