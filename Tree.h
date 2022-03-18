//
//  Tree.h
//  AVL
//
//  Created by Prashanti Pokharel on 11/8/21.
//

#ifndef Tree_h
#define Tree_h

#include "Node.h"
#include <iostream>

template<typename T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void destroy();
    void insert(const T & item);

    void writeFile(std::ostream & File = std::cout) const;

    void inorder()const;
    void preorder()const;
    void postorder()const;

    int height() const;
    int max(int a, int b)const;

    void searchD(const T& item, bool& found, Node<T>*& locPtr, Node<T>*& parent) const;
    T* search(const T & item) const;

private:
    Node<T>* root;
    void destroy(Node<T> * & r);
    void insert(Node<T> * & r, const T & item);
    int height(Node<T>* root) const;

    void inorder(Node<T>*r) const;
    void preorder(Node<T>*r) const;
    void postorder(Node<T>*r) const;

    void writeFile(Node <T>*r, std::ostream &  File) const;
    T* search(Node<T>*r, const T& item) const;

    void rotateRight(Node<T>*& k1);
    void rotateLeft(Node<T>*& k1);
    void updatebFactors(Node <T>* r);
    int getBalance(Node <T> * r) const;

};
//************************************************************************************************
template<typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}
//************************************************************************************************
template<typename T>
AVLTree<T>::~AVLTree()
{
    destroy(root);
}
//************************************************************************************************
template<typename T>
void AVLTree<T>::destroy(Node<T> * & r)
{
    if (r != nullptr)
    {
        destroy(r->left);
        destroy(r->right);
        delete r;
        r = nullptr;
    }
}
//************************************************************************************************
template<typename T>
void AVLTree<T>::destroy()
{
    destroy(root);
}

//************************************************************************************************
template <typename T>
void AVLTree<T>::rotateLeft(Node<T>*& k1)
{
    Node<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}
//************************************************************************************************
template <typename T>
void AVLTree<T>::rotateRight(Node<T>*& k1)
{
    Node<T>* k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

//************************************************************************************************

template <typename T>
int AVLTree<T>::getBalance(Node <T>* r) const
{
    int balance;
    if (r == nullptr) {
        balance = 0;
    }
    else {
        balance = height(r->left) - height(r->right);
    }
    return balance;
}

//************************************************************************************************
template <typename T>
void AVLTree<T>::updatebFactors(Node<T>* r)
{
    if (r != nullptr) {
        r->bFactor = getBalance(r);
        updatebFactors(r->left);
        updatebFactors(r->right);
    }
}

//************************************************************************************************
template<typename T>
void AVLTree<T>::insert(Node<T>* & r, const T & item)
{
    if (r == nullptr)
    {
        r = new Node <T>;
        r->value = item;
        r->left = nullptr;
        r->right = nullptr;
    }

    else if (item < r->value)
    {
        insert(r->left, item);
    }

    else if (item > r->value)
    {
        insert(r->right, item);
    }

    else
    {
        std::cout << "Duplicate\n";
    }

    r->bFactor = getBalance(r);
    if (r->bFactor > 1) {
        if (r->left->bFactor > 0) {
            rotateRight(r);
        }
        else {
            rotateLeft(r->left);
            rotateRight(r);
        }
        updatebFactors(r);
    }
    else if (r->bFactor < -1) {
        if (r->right->bFactor < 0) {
            rotateLeft(r);
        }
        else {
            rotateRight(r->right);
            rotateLeft(r);
        }
        updatebFactors(r);
    }
}
//************************************************************************************************
template<typename T>
void AVLTree<T>::insert(const T & item)
{
    insert(root, item);
}
//************************************************************************************************
template<typename T>
void AVLTree<T>::searchD(const T & item, bool & found, Node<T>* & locPtr, Node<T>*& parent) const
{
    locPtr = root;
    parent = nullptr;
    found = false;

    while (!found && locPtr != nullptr)
    {

        if (item < locPtr->value)
        {
            parent = locPtr;
            locPtr = locPtr->left;
        }

        else if (locPtr->value < item)
        {
            parent = locPtr;
            locPtr = locPtr->right;
        }

        else
        {
            found = true;
        }
    }
}
//************************************************************************************************
template<typename T>
T* AVLTree<T>::search(Node<T>*r, const T& item) const
{
    T*result;

    if (r == nullptr)
        result = nullptr;

    else if (r->value > item)
        result = search(r->left, item);

    else if (r->value < item)
        result = search(r->right, item);

    else
        result = new T(r->value);

    return result;
}
//************************************************************************************************

//************************************************************************************************

template<typename T>
T* AVLTree<T>::search(const T & item) const
{
    T* result;
    result = search(root, item);

    return result;
}

//************************************************************************************************
template<typename T>
int AVLTree<T>::max(int a, int b) const
{
    return (a > b) ? a : b;
}
//************************************************************************************************
template<typename T>
int AVLTree<T>::height(Node<T>* root)const
{
    if (root == nullptr)
    {
        return 0;
    }

    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}
//************************************************************************************************
template<typename T>
int AVLTree<T>::height() const
{
    std::cout << height(root);
    return height(root);
}
//*****************************************************************************************************
template <typename T>
void AVLTree<T>::inorder()const
{
    inorder(root);
}
//************************************************************************************************
template <typename T>
void AVLTree<T>::inorder(Node <T>*r) const
{
    if (r != nullptr)
    {
        inorder(r->left);
        std::cout << r->value << "\t";
        inorder(r->right);
    }
}
//*****************************************************************************************************
template <typename T>
void AVLTree<T>::preorder()const
{
    preorder(root);
}
//************************************************************************************************
template <typename T>
void AVLTree<T>::preorder(Node <T>*r) const
{
    if (r != nullptr)
    {
        std::cout << r->value << "\t";
        preorder(r->left);
        preorder(r->right);
    }
}
//*****************************************************************************************************
template <typename T>
void AVLTree<T>::postorder()const
{
    postorder(root);
}
//************************************************************************************************
template <typename T>
void AVLTree<T>::postorder(Node <T>*r) const
{
    if (r != nullptr)
    {
        postorder(r->left);
        postorder(r->right);
        std::cout << r->value << "\t";
    }
}

//*****************************************************************************************************
template <typename T>
void AVLTree<T>::writeFile (std::ostream& File) const
{
    writeFile(root, File);
}
//************************************************************************************************
template <typename T>
void AVLTree<T>::writeFile (Node <T> * r, std::ostream &  File)  const
{
    if (r != nullptr)
    {
        writeFile(r->left, File);
        std::cout << "Balance Factor: " << r->bFactor <<"\n";
        File << r->value;
        std::cout << "\n";
        writeFile(r->right, File);
        
    }
}

#endif /* Tree_h */
