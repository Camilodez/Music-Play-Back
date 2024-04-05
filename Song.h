#ifndef SONG_H
#define SONG_H
#include <string>

namespace Song {

    class Song {
    private:
        static int nextId;
        int id;
        std::string name;
        std::string artist;
        std::string album;
        std::string genre;  
        int Listens;

    public:
        Song(const std::string& name, const std::string& artist, const std::string& album, const std::string& genre, int Listens)
        : id(nextId++), name(name), artist(artist), album(album), genre(genre), Listens(Listens) {}

        ~Song() {}

        static void initializeId(int StartingId) {
            nextId = StartingId;
        }

        void Play() {
            Listens++;
        }

        int GetPlayCount() const {
            return Listens;
        }
    };

    int Song::nextId = 1;

}

#endif // SONG_H
