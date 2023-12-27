#include "src/presenter.cpp"

int main()
{
    View view;
    Model model;
    Presenter* control = new Presenter(&model, &view);

}