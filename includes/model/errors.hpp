#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>

class Errors
{
public:
    WINDOW *mainWindow;
    std::string lastError = "hello darkness my old firend.";
};
#endif