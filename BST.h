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
    void delete_element(const T&); 
    bool contain(const T&) const;
    T Min() const;
    T Max() const;

public:
    bool operator==(const BST<T>& obj) const;

private:
    TreeNode<T>* find(const T&) const;
    TreeNode<T>* Min_helper(TreeNode<T>*) const;
    TreeNode<T>* Max_helper(TreeNode<T>*) const;
    
    bool HelperOperator(TreeNode<T>* p1, TreeNode<T>* p2) const;
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
    if(this->m_root == nullptr)
    {
        this->m_root = new TreeNode<T>(d);
    }
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
        else
        {
            return;
        }
    }
    if(d < p->data)
    {
        p->left = new TreeNode<T>(d, p);
    }
    else if(d > p->data)
    {
        p->right = new TreeNode<T>(d, p);
    }
}

template <typename T>
bool BST<T>::contain(const T& d) const 
{
    return find(d) != nullptr;
}

template <typename T>
TreeNode<T>* BST<T>::find(const T& key) const
{
    if(this->m_root == nullptr)
    {
        return nullptr;
    }
    TreeNode<T>* r = this->m_root;
    while(r)
    {
        if(r->data == key)
        {
            return r;
        }
        else if(r->data > key)
        {
            r = r->left;
        }
        else
        {
            r = r->right;
        }
    }
    return nullptr;
}

template <typename T>
T BST<T>::Min() const 
{
    return Min_helper(this->m_root) != nullptr ? Min_helper(this->m_root)->data : NULL;
}

template <typename T>
T BST<T>::Max() const 
{
    return Max_helper(this->m_root) != nullptr ? Max_helper(this->m_root)->data : NULL;
}

template <typename T>
TreeNode<T>* BST<T>::Min_helper(TreeNode<T>* k) const
{
    if(k == nullptr)
        return nullptr;
    TreeNode<T>* p = k;
    while(p->left)
    {
        p = p->left;
    }
    return p;
}

template <typename T>
TreeNode<T>* BST<T>::Max_helper(TreeNode<T>* k) const
{
    if(k == nullptr)
        return nullptr;
    TreeNode<T>* p = k;
    while(p->right)
    {
        p = p->right;
    }
    return p;
}

template <typename T>
void BST<T>::delete_element(const T& el)
{
    if(this->m_root == nullptr) return;
    TreeNode<T>* ptr = find(el);
    if(ptr)
    {
        while(ptr->right || ptr->left)
        {
            if ((ptr->right && ptr->left) || (!ptr->left && ptr->right))
            {
                T tmp = ptr->data;
                ptr->data = Min_helper(ptr->right)->data;
                ptr = Min_helper(ptr->right);
                ptr->data = tmp;
            }
            else if(ptr->left && !ptr->right)
            {
                T tmp = ptr->data;
                ptr->data = Max_helper(ptr->left)->data;
                ptr = Max_helper(ptr->left);
                ptr->data = tmp;
            }
        }
        TreeNode<T>* p = ptr->parent;
        if(p->left == ptr)
        {
            p->left = nullptr;
            delete ptr;
        }
        else 
        {
            p->right = nullptr;
            delete ptr;
        }
        ptr = nullptr;
    }
}

template <typename T>
bool BST<T>::operator==(const BST<T>& obj) const
{
    if(this == &obj)
        return true;
    return HelperOperator(this->m_root, obj.m_root);
}

template <typename T>
bool BST<T>::HelperOperator(TreeNode<T>* p1, TreeNode<T>* p2) const 
{
    if(p1 == nullptr && p2 == nullptr)
        return true;
    if((p1 && !p2) || (!p1 && p2))
        return false;
    if(p1 && p2 && p1->data != p2->data)
        return false;
    return HelperOperator(p1->left, p2->left) && HelperOperator(p1->right, p2->right);
}
