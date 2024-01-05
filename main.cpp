#include "includes/controller/controller.hpp"
int main()
{
    View view;
    Model model;
    Controller control(&model, &view);

    while (true)
    {
        control.handleInput();
    }
}