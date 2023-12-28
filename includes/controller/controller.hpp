#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "../model/model.hpp"
#include "../view/view.hpp"
#include "absController.hpp"
#include "gameController.hpp"
#include "menuController.hpp"


class Controller {
private:
    Model* model;
    View* view;
    absController activeController;
public:
    Controller(Model* modelPtr, View* viewPtr);
    void handleInputAndUpdateGame();
};

// Controller::Controller(Model* modelPtr, View* viewPtr){
//     activeController = new 
// }

// void handleInputAndUpdateGame(){
//     activeController.handleInput();
// };


#endif // GAMEController_HPP
