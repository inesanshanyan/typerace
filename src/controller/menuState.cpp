#include "../includes/controller/controller.hpp"
#include <ncurses.h>
MenuState::MenuState(Controller *controller)
{
    printw("Menu stateee"); // Print a string to the window
    getch();
    this->controller = controller;
};

void MenuState::draw()
{
    
};

void MenuState::handleInput()
{
    printw("menu handle input !"); // Print a string to the window

    controller->view->getControlKey();
    changeState();
};

void MenuState::changeState(){
    controller->state = new GameState(controller);
};