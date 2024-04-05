#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <list>
#include "Song.h" 

namespace BinaryNode
{
    template <typename T>
    class BinaryNode
    {
    private:
        T data; 
         std::list<Song::Song> songs;
        BinaryNode<T>* left; 
        BinaryNode<T>* right; 

    public:
        BinaryNode(T data, const std::list<Song::Song>& songs) 
        : data(data), songs(songs), left(nullptr), right(nullptr) {}

        ~BinaryNode() {
            delete left;
            delete right;
        }

       
        T getData() const { return data; }
        void setData(T newData) { data = newData; }

        std::list<Song::Song>& getSongs() { 
            return songs; }

        void setSongs(const std::list<Song::Song>& newSongs) { 
            
            songs = newSongs; }

        BinaryNode<T>* getLeft() const { 
            return left; }

        void setLeft(BinaryNode<T>* node) { 
            left = node; }

        BinaryNode<T>* getRight() const { 
            return right; }
        void setRight(BinaryNode<T>* node) { 
            right = node; }
    };

} // namespace BinaryNode

#endif // BINARYNODE_H
