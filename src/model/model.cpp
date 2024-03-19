#include "../includes/model/model.hpp"
#include <istream>
#include <ostream>
#include <utility>

std::pair<int, int> get_screen_size()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    return std::make_pair(max_y, max_x);
}

Model::Model(){
    board = new Board();
    player = new Player();
    errors = new Messeges();

    // this part is not connected with model but now it will be here.
    //TODO change this numbers to constants ----------
    std::pair<int, int> screen_size(0,0);
    screen_size = get_screen_size();

    board->mainWindow = newwin(BOARD_MAIN_WINDOW_H,
                        BOARD_MAIN_WINDOW_W,
                        (screen_size.first / 2) - (BOARD_MAIN_WINDOW_H / 2),
                        (screen_size.second / 2) - (BOARD_MAIN_WINDOW_W / 2));
    errors->mainWindow = newwin(ERROR_MAIN_WINDOW_H,
                        ERROR_MAIN_WINDOW_W,
                        (screen_size.first / 2) - (ERROR_MAIN_WINDOW_H / 2),
                        (screen_size.second / 2) - (ERROR_MAIN_WINDOW_W / 2));
    player->mainWindow = newwin(PLAYER_MAIN_WINDOW_H,
                        PLAYER_MAIN_WINDOW_W,
                        (screen_size.first / 2) - (PLAYER_MAIN_WINDOW_H / 2) + PLAYER_MAIN_WINDOW_H + 1,
                        (screen_size.second / 2) - (PLAYER_MAIN_WINDOW_W / 2));
    player->loginWiondow = newwin(PLAYER_LOGIN_WINDOW_H,
                        PLAYER_LOGIN_WINDOW_W,
                        (screen_size.first / 2) - (PLAYER_LOGIN_WINDOW_H / 2),
                        (screen_size.second / 2) - (PLAYER_LOGIN_WINDOW_W / 2));
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
