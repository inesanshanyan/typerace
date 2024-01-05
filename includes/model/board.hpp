#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <list>
class Board
{
public:
    WINDOW *mainWindow;
    std::vector<std::string> content;
    std::string *activeWord;
};
#endif