#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <list>
class Board
{
private:
    std::vector<std::string> content;
    std::string *activeWord;
};
#endif