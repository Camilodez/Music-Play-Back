#ifndef BINARYTHREE_H
#define BINARYTHREE_H

#include "BinaryNode.h"

namespace BinaryThree
{
    template <typename T>
    class BinaryThree
    {
    private:
    BinaryNode::BinaryNode<T> root;
       
    public:
        BinaryThree() : root(nullptr) {}
        ~BinaryThree(){
            delete root;
        }

        BinaryNode::BinaryNode<T>* getRoot() const { return root; }
        void setRoot(BinaryNode::BinaryNode<T>* node) { root = node; }


    };
    
} // namespace BinaryThree



#endif // BINARYTHREE_H