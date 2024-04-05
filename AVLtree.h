#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

namespace AVLTree
{
    template <typename T>
    class AVLTree
    {
    private:
        AVLNode::AVLNode<T>* root;

        // Métodos privados para rotación y balanceo
        AVLNode<T>* rotateRight(AVLNode<T>* y) {
            AVLNode<T>* x = y->getLeft();
            AVLNode<T>* T2 = x->getRight();

            x->setRight(y);
            y->setLeft(T2);

            y->updateHeight();
            x->updateHeight();

            return x;
        }

        AVLNode<T>* rotateLeft(AVLNode<T>* x) {
            AVLNode<T>* y = x->getRight();
            AVLNode<T>* T2 = y->getLeft();

            y->setLeft(x);
            x->setRight(T2);

            x->updateHeight();
            y->updateHeight();

            return y;
        }

        AVLNode<T>* insert(AVLNode<T>* node, T key, const std::list<Song::Song>& songs) {
            if (node == nullptr) 
                return new AVLNode<T>(key, songs);

            if (key < node->getData()) 
                node->setLeft(insert(node->getLeft(), key, songs));
            else if (key > node->getData()) 
                node->setRight(insert(node->getRight(), key, songs));
            else 
                return node;

            node->updateHeight();
            int balance = node->getBalance();

            // Rotaciones para balancear el árbol
            if (balance > 1 && key < node->getLeft()->getData()) 
                return rotateRight(node);

            if (balance < -1 && key > node->getRight()->getData()) 
                return rotateLeft(node);

            if (balance > 1 && key > node->getLeft()->getData()) {
                node->setLeft(rotateLeft(node->getLeft()));
                return rotateRight(node);
            }

            if (balance < -1 && key < node->getRight()->getData()) {
                node->setRight(rotateRight(node->getRight()));
                return rotateLeft(node);
            }

            return node;
        }

    public:
        AVLTree() : root(nullptr) {}

        ~AVLTree() {
            delete root;
        }

        void insert(T key, const std::list<Song::Song>& songs) {
            root = insert(root, key, songs);
        }

       
    };
}

#endif // AVLTREE_H
