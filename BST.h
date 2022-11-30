#pragma once 

#include "Binary_tree.h"
#include "TreeNode.h"

#include <iostream>

template <typename T>
class BST: public BinaryTree<T>
{
public:
     ~BST();
    
public:
    void insert(const T&);
    void delete_node(const T&); //!!!! TODO !!!!!//
    void left_rotate(TreeNode<T>*);
    void right_rotate(TreeNode<T>*);
    void left_right_rotate(TreeNode<T>*);
    void right_left_rotate(TreeNode<T>*);
    
    TreeNode<T>* find(const T&) const;
};

template <typename T>
BST<T>::~BST()
{
    this->clear();
    std::cout << "BST dtor" << std::endl;
}

template <typename T>
void BST<T>::insert(const T& d)
{
    TreeNode<T>* r = this->m_root;
    TreeNode<T>* p = nullptr;
    while(r)
    {
        if(d > r->data)
        {
            p = r;
            r = r->right;
        }
        else if(d < r->data)
        {
            p = r;
            r = r->left;
        }
    }
    if(p == nullptr && r == nullptr)
    {
        this->m_root = new TreeNode<T>(d);
    }
    else
    {
        if(p->data > d)
        {
            p->left = new TreeNode<T>(d, p);
        }
        else if(p->data < d)
        {
            p->right = new TreeNode<T>(d, p);
        }
    }
}

template <typename T>
void BST<T>::left_rotate(TreeNode<T>* p) 
{
    TreeNode<T>* k = p->parent;
    TreeNode<T>* r = p->right;
    p->parent = r;
    if(r)
    {
    p->right = r->left;
    r->left = p;
    r->parent = k;
    }
    if(k && k->right == p)
    {
        k->right = r;
    }
    if(k && k->left == p)
    {
        k->left = r;
    }
}

template <typename T>
void BST<T>::right_rotate(TreeNode<T>* p)
{
    TreeNode<T>* k = p->parent;
    TreeNode<T>* l = p->left;
    p->parent = l;
    if(l)
    {
    p->left = l->right;
    l->parent = k;
    l->right = p;
    }
    if(k && k->left == p)
    {
        k->left = l;
    }
    if(k && k->right == p)
    {
        k->right = l;
    }
}

template <typename T>
void BST<T>::left_right_rotate(TreeNode<T>* p)
{
    left_rotate(p->left);
    right_rotate(p);
}

template <typename T>
void BST<T>::right_left_rotate(TreeNode<T>* p)
{
    right_rotate(p->right);
    left_rotate(p);
}
