#include "../includes/model/model.hpp"
#include <istream>
#include <ostream>

Model::Model(){
    menu = new Menu();
    board = new Board();
    player = new Player();
    loginMenu = new LoginMenu();
    // this part is not connected with model but now it will be here.
    //TODO change this numbers to constants ----------
    menu->mainWindow = newwin(15, 20, 5, 5);
    loginMenu->mainWindow = newwin(15, 20, 5, 5);
    board->mainWindow = newwin(20, 70, 0, 40);
    player->mainWindow = newwin(4, 70, 20, 40);
    player->loginWiondow = newwin(15, 60, 2, 40);
    //------------------------------------------------
    board->content = getContentFromFile("other/test.php");
    board->activeWord = &board->content[0];
};

std::vector<std::string> Model::getContentFromFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "erorro" << filename << std::endl;
    }
    return words;
}