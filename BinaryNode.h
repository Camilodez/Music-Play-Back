#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "Song.h"

namespace BinaryNode
{
    template <typename T>
    class BinaryNode
    {
    private:
    T data;
    BinaryNode<T> *left;
    BinaryNode<T> *right;
    std::List<Song::Song> songs;
   
        
    public:
        BinaryNode(/* args */);
        ~BinaryNode();
    };
    
    
} // namespace BinaryNode






#endif // BINARYNODE_H