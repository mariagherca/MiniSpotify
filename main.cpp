#include "SpotifyApp.h"
#include <iostream>

int main() {
    try {
        std::cout << "Bine ai venit la MiniSpotify!\nIntrodu numele tau: ";
        std::string username;
        std::getline(std::cin, username);

        SpotifyApp app(username);
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
