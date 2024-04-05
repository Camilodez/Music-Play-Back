#ifndef AVLNODE_H
#define AVLNODE_H

#include <list>
#include <algorithm> // Para std::max
#include "Song.h"

namespace AVLNode
{
    template <typename T>
    class AVLNode
    {
    private:
        T data;
        std::list<Song::Song> songs;
        AVLNode<T>* left;
        AVLNode<T>* right;
        int height;  // Altura del nodo para el balanceo AVL

    public:
        // Constructor
        AVLNode(T data, const std::list<Song::Song>& songs)
            : data(data), songs(songs), left(nullptr), right(nullptr), height(1) {}

        // Destructor
        ~AVLNode() {
            delete left;
            delete right;
        }

        // Getters y setters adicionales
        T getData() const { return data; }
        void setData(T newData) { data = newData; }

        std::list<Song::Song>& getSongs() { return songs; }
        void setSongs(const std::list<Song::Song>& newSongs) { songs = newSongs; }

        AVLNode<T>* getLeft() const { return left; }
        void setLeft(AVLNode<T>* node) { left = node; }

        AVLNode<T>* getRight() const { return right; }
        void setRight(AVLNode<T>* node) { right = node; }

        int getHeight() const { return height; }
        void setHeight(int newHeight) { height = newHeight; }

        int getBalance() const {
            int leftHeight = left ? left->getHeight() : 0;
            int rightHeight = right ? right->getHeight() : 0;
            return leftHeight - rightHeight;
        }

        void updateHeight() {
            int leftHeight = left ? left->getHeight() : 0;
            int rightHeight = right ? right->getHeight() : 0;
            height = 1 + std::max(leftHeight, rightHeight);
        }
    };

} // namespace AVLTree

#endif // AVLNODE_H
