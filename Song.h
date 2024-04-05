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


       // Getters y Setters
        int getId() const {
            return id;
        }

        std::string getName() const {
            return name;
        }

        void setName(const std::string& newName) {
            name = newName;
        }

        std::string getArtist() const {
            return artist;
        }

        void setArtist(const std::string& newArtist) {
            artist = newArtist;
        }

        std::string getAlbum() const {
            return album;
        }

        void setAlbum(const std::string& newAlbum) {
            album = newAlbum;
        }

        std::string getGenre() const {
            return genre;
        }

        void setGenre(const std::string& newGenre) {
            genre = newGenre;
        }

        int getListens() const {
            return Listens;
        }

        void setListens(int newListenCount) {
            Listens = newListenCount;
        }

        void setId(int newId) {
            id = newId;
        }


    };

    int Song::nextId = 1;

}

#endif // SONG_H
