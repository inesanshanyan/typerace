#ifndef MESSAGESTATE_H
#define MESSAGESTATE_H

#include "state.hpp"

class MessageState : public State 
{
public:
    void changeState() override;
    void draw() override;
    void handleInput() override;
    virtual Menu& getMenu() override;

    static MessageState& getInstance(Controller *);
    MessageState(const Controller&) = delete;
    MessageState& operator=(const Controller&) = delete;
protected:
    MessageState(Controller *controller);
private:
    MessageState() = default;
    static MessageState* instance;

};

#endif