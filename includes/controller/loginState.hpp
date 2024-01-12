#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include "state.hpp"

class LoginState : public State 
{
private:
public:
    LoginState(Controller *controller);
    void changeState() override;
    void draw() override;
    void handleInput() override;
};

#endif