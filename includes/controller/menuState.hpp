#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "state.hpp"

class MenuState : public State
{
public:
    void draw() override;
    void changeState() override;
    void handleInput() override;
    virtual Menu* getMenu() override;

    void changeMenuState(const std::vector<std::string> options);
    void changeMenuState();
    static MenuState& getInstance(Controller*);
    MenuState(const MenuState&) = delete;
    MenuState& operator=(const MenuState&) = delete;
protected:
    MenuState (Controller *);
private:
    MenuState() = default;

    static MenuState*   instance;
    Menu*               menu;
};

#endif