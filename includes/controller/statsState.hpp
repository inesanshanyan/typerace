#ifndef STATSSTATE_HPP
#define STATSSTATE_HPP

#include "state.hpp"

class StatsState : public State {
private:
    Controller* controller;

public:
    StatsState(Controller* controller);
    void changeState() override;
    void draw() override;
    void handleInput() override;
    void countStats();
    void setMaxSpeed(int);
};

#endif
