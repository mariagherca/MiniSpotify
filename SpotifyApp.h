#ifndef SPOTIFYAPP_H
#define SPOTIFYAPP_H

#include "User.h"

class SpotifyApp {
    User user;
    std::vector<std::unique_ptr<Song>> allSongs;

    void loadInitialData();
    void displayMainMenu();
    // ... (alte metode private)

public:
    SpotifyApp(const std::string& username);
    void run();
};

#endif // SPOTIFYAPP_H
