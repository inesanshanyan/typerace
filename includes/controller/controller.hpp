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
#include "settingState.hpp"
#include "abstractMenu.hpp"
#include "pauseState.hpp"
#include <vector>
std::pair<int, int> get_screen_size();

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
