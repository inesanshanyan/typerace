#include "menu.hpp"

class LoginMenu : public Menu
{
public:
    LoginMenu()
    {
        options = {"sign in", "sign up"};
        currentItem = options.begin();
    }
    ~LoginMenu();
};

