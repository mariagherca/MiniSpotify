#include "User.h"
#include "Playlist.h"
#include <algorithm>
#include <iostream>

User::User(const std::string& name) : username(name) {}

void User::addPlaylist(std::unique_ptr<Playlist> playlist) {
    playlists.push_back(std::move(playlist));
}

void User::createPlaylist(const std::string& name, const std::string& desc) {
    playlists.push_back(std::make_unique<Playlist>(name, username, desc));
}

void User::removePlaylist(const std::string& name) {
    auto it = std::remove_if(playlists.begin(), playlists.end(),
        [&name](const std::unique_ptr<Playlist>& p) {
            return p->getName() == name;
        });

    if (it == playlists.end()) {
        throw PlaylistException(name + " negasit");
    }
    playlists.erase(it, playlists.end());
}

void User::addToFavorites(Song* song) {
    favorites.push_back(song->clone());
}

void User::addFavoriteArtist(const std::string& artist) {
    if (std::find(favoriteArtists.begin(), favoriteArtists.end(), artist) == favoriteArtists.end()) {
        favoriteArtists.push_back(artist);
    }
}

void User::addToHistory(Song* song) {
    history.insert(history.begin(), song->clone());
    if (history.size() > 20) {
        history.pop_back();
    }
}

void User::addSongToLibrary(std::unique_ptr<Song> song) {
    artistLibrary[song->getArtist()].push_back(std::move(song));
}

void User::playSong(Song* song) {
    song->play();
    song->incrementPlays();
    addToHistory(song);
}

// ... (implementari pentru toate metodele de afisare)
void User::displayLibrary() const {
    std::cout << "\n Biblioteca muzicala (" << artistLibrary.size() << " artisti)\n";
    for (const auto& [artist, songs] : artistLibrary) {
        std::cout << " " << artist << ": " << songs.size() << " melodii\n";
    }
}

// Implementari similare pentru:
// - displayArtistSongs()
// - displayPlaylists()
// - displayFavorites()
// - displayHistory()
