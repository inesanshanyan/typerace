#ifndef STATE_HPP
#define STATE_HPP

#include "controller.hpp"
class Controller;
class State {
private:
protected:
    Controller *controller;
public:
    virtual void draw() = 0;
    virtual void handleInput() = 0;
    virtual void changeState() = 0;
    virtual ~State(){};
};

#endif