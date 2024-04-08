#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "state.hpp"

class PauseState : public State 
{
private:
    PauseState() = default;
    static  PauseState* instance;
    Menu* menu;
    bool isMenuOn = true; 
    
    void handleMenuInput(int key);
protected:
    PauseState(Controller *);
public:
    void changeState() override;
    void draw() override;
    void handleInput() override;
    virtual Menu* getMenu() override;

    static PauseState& getInstance(Controller*);
    PauseState(const Controller&) = delete;
    PauseState& operator=(const Controller&) = delete;
};

#endif