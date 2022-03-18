//
//  Node.h
//  AVL
//
//  Created by Prashanti Pokharel on 11/8/21.
//

#ifndef Node_h
#define Node_h

template<typename T>
struct Node
{
    Node<T>* left;
    Node <T>*right;
    T value;
    int bFactor;
};
#endif /* Node_h */
