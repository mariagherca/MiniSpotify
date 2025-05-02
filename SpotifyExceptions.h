#ifndef SPOTIFYEXCEPTIONS_H
#define SPOTIFYEXCEPTIONS_H

#include <stdexcept>
#include <string>

class SpotifyException : public std::runtime_error {
public:
    explicit SpotifyException(const std::string& message);
};

class FileException : public SpotifyException {
public:
    explicit FileException(const std::string& filename);
};

class SongException : public SpotifyException {
public:
    explicit SongException(const std::string& title);
};

class PlaylistException : public SpotifyException {
public:
    explicit PlaylistException(const std::string& name);
};

#endif // SPOTIFYEXCEPTIONS_H
