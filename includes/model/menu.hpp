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
    std::vector<std::string>::iterator  currentItem;
    std::vector<std::string> options;
    std::vector<std::vector<std::string>> prevItems;

    Menu(std::vector<std::string> options)
    {
        this->options = options;
        prevItems.push_back(this->options);
        currentItem = this->options.begin();
    };

    //TODO WRITE THIS FUNCTION inside a cpp file
    void changeOption(int key)
    {
        // Check the value of key and update currentItem accordingly
        if (key == 1 && currentItem != options.end() - 1) {
            // Move to the next element if not already at the last one
            currentItem = currentItem + 1;
        } else if (key == 0 && currentItem != options.begin()) {
            // Move to the previous element if not already at the first one
            currentItem = currentItem - 1;
        }
    }
};

#endif