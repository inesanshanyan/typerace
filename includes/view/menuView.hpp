#ifndef MENUVIEW_H
#define MENUVIEW__H

#include "absView.hpp"

#include <string>

class menuView : public absView {
public:
    menuView();

    virtual void initWindow() override;
    void draw();
    virtual ~menuView() override;

    std::string chooseOption();
    void checkIndex(int&);

private:
    std::string title;
    static const int optionsNum = 3;
    std::string options[optionsNum];
    std::string activeOption;

};
#endif