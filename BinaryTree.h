#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h" // Asegúrate de que este archivo esté correctamente implementado

namespace BinaryTree
{
    template <typename T>
    class BinaryTree
    {
    private:
        BinaryNode::BinaryNode<T>* root; 
       
    public:
        BinaryTree() : root(nullptr) {} 
        ~BinaryTree() {
            deleteTree(root); 
        }

        BinaryNode::BinaryNode<T>* getRoot() const { return root; }
        void setRoot(BinaryNode::BinaryNode<T>* node) { root = node; }

    
        void deleteTree(BinaryNode::BinaryNode<T>* node) {
            if (node != nullptr) {
                deleteTree(node->getLeft());
                deleteTree(node->getRight());
                delete node;
            }
        }
    };
    
} // namespace BinaryTree

#endif // BINARYTREE_H
