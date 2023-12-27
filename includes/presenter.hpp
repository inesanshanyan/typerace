#ifndef GAMEPRESENTER_HPP
#define GAMEPRESENTER_HPP

#include "model/model.hpp"
#include "view/view.hpp"

class Presenter {
private:
    Model* model;
    View* view;
public:
    Presenter(Model* modelPtr, View* viewPtr);
    void handleInputAndUpdateGame();
};

#endif // GAMEPRESENTER_HPP
