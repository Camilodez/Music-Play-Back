#ifndef SONG_H
#define SONG_H
#include <string>

namespace Song{

    class Song
    {
    private:

    static int countId;
    int id;
    std::string name;
    std::string artist;
    std::string album;
    std::string genre;  
    int Listens;

      
    public:

     Song(int id, const std::string& name, const std::string& artist, const std::string& album, const std::string& genre, int Listens)
        : id(id), name(name), artist(artist), album(album), genre(genre), Listens(Listens) {}

        ~Song() {}

        static int initializeId(int StartingId){
            countId=StartingId;

        } 

         int Song::nextId = 1;


         void Play(){
             Listens++;
         }

         int GetPlayCount() const{
             return Listens;
         }

    };
    
    
}

#endif // SONG_H