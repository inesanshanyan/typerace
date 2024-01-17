#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "state.hpp"

class MenuState : public State 
{
public:
    MenuState (Controller *);
    void draw() override;
    void changeState() override;
    void handleInput() override;
    void changeMenuState(const std::vector<std::string> options);
    void changeMenuState();
};

#endif