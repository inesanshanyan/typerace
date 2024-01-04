#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>

class Menu
{
public:
    WINDOW *mainWindow;
    std::string *currentItem;
    std::vector<std::string> options;
    Menu(){
        options = {"start","pause","end"};
        currentItem = &options[0];
    };

    void changeOption(int key)
    {
        // for down
        if ( key == 1 && currentItem != &options[options.size() - 1] ) {
            currentItem = currentItem + 1;
        } else if (key == 0 && currentItem != &options[0]) {
            // for up
            currentItem = currentItem - 1;
        }
    }
};

#endif