#include "../includes/controller/controller.hpp"
#include <ncurses.h>
Controller::Controller(Model* modelPtr, View* viewPtr)
{
    model = modelPtr;
    view = viewPtr;
    state = new MenuState(this);
}

void Controller::handleInput()
{
    state->handleInput();
}
