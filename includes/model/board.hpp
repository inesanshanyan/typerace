#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ncurses.h>

class Board
{
public:
    WINDOW *mainWindow;
    std::vector<std::string> content;
    std::string *activeWord;

    void changeCurrentWord(bool flag)
    {
        if (flag && activeWord != &content[content.size() - 1])
        {
            activeWord++;
        }else if (!flag && activeWord != &content[0])
        {
            activeWord--;
        }
    }
};
#endif