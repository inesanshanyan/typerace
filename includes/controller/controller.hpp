#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "../model/model.hpp"
#include "../view/view.hpp"

class Controller {
private:
    Model* model;
    View* view;
public:
    Controller(Model* , View* );
    void changeController();
    void handleInputAndUpdateGame();
};

#endif // GAMEController_HPP
