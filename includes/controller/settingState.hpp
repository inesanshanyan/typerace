#ifndef SETTINGSTATE_HPP
#define SETTINGSTATE_HPP

#include "state.hpp"

class SettingState : public State 
{
private:
    SettingState() = default;
    static  SettingState*       instance;
    Menu*                       menu;
    bool                        isMenuOn = true; // for checkint if drawing item is menu or selecting part. (not only drawing but also hadled key).
    bool                        isTypeSpeed = false;
    bool                        isDifficultyMode = false;
    std::vector<std::string>    speedTypeItems = {"wpm", "cpm"};
    std::vector<std::string>    difficultyModeItems = {"easy", "medium", "difficult", "insane"};

    void handleMenuInput(int key);
    void handleSpeedTypeSelecting(int key);
    void handleDifficultyModeSelecting(int key);
protected:
    SettingState(Controller *);
public:
    void changeState() override;
    void draw() override;
    void handleInput() override;
    virtual Menu* getMenu() override;

    static SettingState& getInstance(Controller*);
    SettingState(const Controller&) = delete;
    SettingState& operator=(const Controller&) = delete;
};

#endif