#ifndef MESSAGESTATE_H
#define MESSAGESTATE_H

#include "state.hpp"

class MessageState : public State 
{
public:
    MessageState(Controller *controller);
    void changeState() override;
    void draw() override;
    void handleInput() override;
};

#endif