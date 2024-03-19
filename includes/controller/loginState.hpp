#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include "state.hpp"

class LoginState : public State 
{
private:
    void enterLogin(Player *);
    void enterPassword(Player *);
    LoginState() = default;
    static LoginState* instance;
protected:
    LoginState(Controller *);
public:
    void changeState() override;
    void draw() override;
    void handleInput() override;
    virtual Menu& getMenu() override;

    static LoginState& getInstance(Controller*);
    LoginState(const Controller&) = delete;
    LoginState& operator=(const Controller&) = delete;
};

#endif