#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>

class Messeges
{
public:
    WINDOW *mainWindow;
    std::string lastError = "";
};
#endif