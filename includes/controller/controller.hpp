#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../model/model.hpp"
#include "../view/view.hpp"
#include "state.hpp"
#include "menuState.hpp"
#include "gameState.hpp"
#include "loginState.hpp"
#include "messageState.hpp"
#include "statsState.hpp"
#include <vector>

class Controller {
public:
    Model* model;
    View* view;
    State* state;
    std::vector<State*> prevState; 
    Controller(Model* , View* );
    void handleInput();
};

#endif // GAMEController_HPP
