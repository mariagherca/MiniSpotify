#ifndef USER_H
#define USER_H

#include "Playlist.h"
#include <map>
#include <vector>
#include <string>

class User {
    std::string username;
    std::vector<std::unique_ptr<Playlist>> playlists;
    std::vector<std::unique_ptr<Song>> favorites;
    std::vector<std::string> favoriteArtists;
    std::vector<std::unique_ptr<Song>> history;
    std::map<std::string, std::vector<std::unique_ptr<Song>>> artistLibrary;

public:
    User(const std::string& name);

    void addPlaylist(std::unique_ptr<Playlist> playlist);
    void createPlaylist(const std::string& name, const std::string& desc = "");
    void removePlaylist(const std::string& name);

    // ... (alte metode)
};

#endif // USER_H
