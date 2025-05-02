#include "SpotifyApp.h"
#include <fstream>
#include <algorithm>
#include <ctime>

SpotifyApp::SpotifyApp(const std::string& username) : user(username) {
    std::srand(std::time(0));
    loadInitialData();
}

void SpotifyApp::loadInitialData() {
    try {
        user.addPlaylist(Playlist::createFromFile("Hituri Pop", "pop_songs.txt"));
        user.addPlaylist(Playlist::createFromFile("Clasice Rock", "rock_songs.txt"));

        auto loadSongs = [this](const std::string& filename) {
            auto playlist = Playlist::createFromFile("temp", filename);
            for (const auto& song : playlist->getSongs()) {
                allSongs.push_back(song->clone());
                user.addSongToLibrary(song->clone());
            }
        };

        loadSongs("pop_songs.txt");
        loadSongs("rock_songs.txt");

        user.addFavoriteArtist("The Weeknd");
        user.addFavoriteArtist("Queen");
    } catch (const std::exception& e) {
        std::cerr << " Eroare la incarcare date: " << e.what() << "\n";
    }
}

void SpotifyApp::run() {
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: browseLibrary(); break;
            case 2: managePlaylists(); break;
            // ... alte cases
            case 0: std::cout << "La revedere!\n"; break;
            default: std::cout << "Optiune invalida!\n";
        }
    } while (choice != 0);
}

// Implementări complete pentru:
// - displayMainMenu()
// - browseLibrary()
// - playSongFromLibrary()
// - managePlaylists()
// - showFavorites()
// - showHistory()
// - searchSongs()
