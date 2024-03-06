#ifndef STATSSTATE_HPP
#define STATSSTATE_HPP

#include "state.hpp"

class StatsState : public State {
private:
    Controller* controller;
    StatsState() = default;
protected:
    StatsState(Controller*);
public:
    void changeState() override;
    void draw() override;
    void handleInput() override;
    void countStats();
    void setMaxSpeed(int);
    static StatsState& getInstance(Controller*);
    StatsState(const Controller&) = delete;
    StatsState& operator=(const Controller&) = delete;
};

#endif
