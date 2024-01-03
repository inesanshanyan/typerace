#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

class View {
public:
    View();
    int getKey();
    void drawGame();
    void drawMenu();
    char getLetter();
    char getControlKey();   
};

#endif // GAMEVIEW_HPP
