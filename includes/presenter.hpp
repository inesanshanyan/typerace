#ifndef GAMEPRESENTER_HPP
#define GAMEPRESENTER_HPP

#include "model.hpp"
#include "view.hpp"

class GamePresenter {
private:
    GameModel* model;
    GameView* view;

public:
    GamePresenter(GameModel* modelPtr, GameView* viewPtr);

    void handleInputAndUpdateGame();

};

#endif // GAMEPRESENTER_HPP
