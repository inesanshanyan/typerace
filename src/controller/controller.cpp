#include "../includes/controller/controller.hpp"
#include <ncurses.h>
Controller::Controller(Model* modelPtr, View* viewPtr)
{
    model = modelPtr;
    view = viewPtr;
    state = &MenuState::getInstance(this);
    prevState.push_back(state);
}

void Controller::handleInput()
{
    state->handleInput();
}
