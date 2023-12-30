#ifndef VIEW_H
#define VIEW_H

#include <ncurses.h>

class absView {
public:
    absView();
    virtual void initWindow() = 0;
    void setParameters(int, int);
    void exitGame();

    //void draw();

    virtual ~absView();

protected:
    WINDOW* window;
    int winHeight, winWidth;
    int maxHeight, maxWidth;
    int startX, startY;
};

#endif
