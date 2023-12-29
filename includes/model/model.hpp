#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <iostream>
#include <vector>
#include <list>

struct Player
{
    
};

struct Board
{
    
};

struct Menu
{
    std::string *currentItem;
    
};
class Model {
private:
    Player player;
    Board board;
    Menu menu;
public:
    Model();
};

#endif // GAMEMODEL_HPP
