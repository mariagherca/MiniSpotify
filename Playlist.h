#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>
#include <memory>
#include <string>

class Playlist {
    std::string name;
    std::vector<std::unique_ptr<Song>> songs;
    std::string creator;
    std::string description;

public:
    Playlist(const std::string& name,
             const std::string& creator = "Utilizator",
             const std::string& desc = "");

    // Regula celor 5
    Playlist(const Playlist& other);
    Playlist& operator=(Playlist other);
    ~Playlist();

    void swap(Playlist& other) noexcept;
    void addSong(std::unique_ptr<Song> song);
    void removeSong(const std::string& title);
    void playAll() const;
    void display(bool detailed = false) const;

    const std::vector<std::unique_ptr<Song>>& getSongs() const;
    const std::string& getName() const;
    size_t getSongCount() const;

    static std::unique_ptr<Playlist> createFromFile(const std::string& name,
                                                   const std::string& filename);
};

#endif // PLAYLIST_H
