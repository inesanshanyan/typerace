#include "../includes/model/model.hpp"
#include <istream>
#include <ostream>

Model::Model(){
    menu = new Menu();
    board = new Board();
    player = new Player();
    errors = new Messeges();

    // this part is not connected with model but now it will be here.
    //TODO change this numbers to constants ----------
    menu->mainWindow = newwin(15, 20, 5, 5);
    board->mainWindow = newwin(20, 70, 0, 40);
    errors->mainWindow = newwin(10, 40, 0, 30);
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
Json Model::getUsers()
{
    std::ifstream file("userdata/users.json");
    if (!file.is_open()) {
        abort();
    }
    Json jsonArray;
    try {
        file >> jsonArray; 
    } catch (const Json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }
    file.close(); 
    return jsonArray;
}

void Model::setUsers(const Json& users)
{
    std::ofstream file("userdata/users.json");
    if (!file.is_open()) {
        abort();
    }
    try {
        file << std::setw(4) << users << std::endl;
    } catch (const Json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }
    file.close(); 
}

Json Model::getCurrentUser()
{
    std::ifstream file("userdata/users.json");
    if (!file.is_open()) {
        abort();
    }
    Json users = getUsers();  
    Json currentUser;

    for (const auto& user : users) {
        if (user["login"].get<std::string>() == player->login) {
            currentUser = user;
            break;      
        }
    }
    file.close();
    return currentUser;
}
