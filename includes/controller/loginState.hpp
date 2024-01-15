#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include "state.hpp"

class LoginState : public State 
{
private:
    void enterLogin(Player *);
    void enterPassword(Player *);
public:
    LoginState(Controller *controller);
    void changeState() override;
    void draw() override;
    void handleInput() override;
};

#endif