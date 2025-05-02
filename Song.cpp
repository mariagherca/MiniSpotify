#include "Song.h"
#include "SpotifyExceptions.h"
#include <memory>
#include <stdexcept>

// Implementări pentru clasa de bază Song
Song::Song(const std::string& title, const std::string& artist,
           int duration, const std::string& genre)
    : title(title), artist(artist), duration(duration),
      genre(genre), plays(0) {}

// Implementări pentru metodele de bază...
