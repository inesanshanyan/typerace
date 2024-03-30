#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "state.hpp"

class GameState : public State 
{
private:
public:
    GameState(Controller *controller);
    void changeState() override;
    void draw() override;
    void handleInput() override;
    virtual Menu* getMenu() override;

    void checkWord();
    void setSpeed(int);
};



#endif