#pragma once

#include <iostream>
#include <stack>
#include <queue>

#include "TreeNode.h"

template <typename T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(TreeNode<T>*);
    BinaryTree(const BinaryTree<T>&);
    BinaryTree(const BinaryTree<T>&&);
    ~BinaryTree();
    
public:
    void preorder_rec() const;
    void inorder_rec() const;
    void postorder_rec() const;
    void levelorder_rec() const;
    
    void preorder_iter() const;
    void inorder_iter() const;
    void postorder_iter() const;
    void levelorder_iter() const;
    
    void insert(TreeNode<T>*);
    void clear();

private:
    void preorder_rec_helper(TreeNode<T>*) const;
    void inorder_rec_helper(TreeNode<T>*) const;
    void postorder_rec_helper(TreeNode<T>*) const;
    void levelorder_rec_helper(TreeNode<T>*) const;
    void clear_helper(TreeNode<T>*);
    
private:
    TreeNode<T>* m_root;
};

template <typename T>
BinaryTree<T>::BinaryTree()
    : m_root(nullptr)
{
    std::cout << "default ctor" << std::endl;
}

template <typename T>
BinaryTree<T>::BinaryTree(TreeNode<T>* root)
    : m_root(root)
{
    std::cout << "ctor with perimeters" << std::endl;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& obj)
    : m_root(nullptr)
{
    //TODO!!
    
    std::cout << "copy ctor" << std::endl;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>&& tmp)
    : m_root(tmp.m_root)
{
    tmp.m_root = nullptr;
    
    std::cout << "move ctor" << std::endl;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    clear();
    
    std::cout << "dtor" << std::endl;
}

template <typename T>
void BinaryTree<T>::preorder_rec() const 
{
    preorder_rec_helper(m_root);
}

template <typename T>
void BinaryTree<T>::inorder_rec() const 
{
    inorder_rec_helper(m_root);
}

template <typename T>
void BinaryTree<T>::postorder_rec() const 
{
    postorder_rec_helper(m_root);
}

template <typename T>
void BinaryTree<T>::levelorder_rec() const
{
    levelorder_rec_helper(m_root);
}

template <typename T>
void BinaryTree<T>::preorder_iter() const 
{
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* r = m_root;
    while(true)
    {
        while(r)
        {
            std::cout << r->data << " ";
            if(r->right)
            {
                s.push(r->right);
            }
            r = r->left;
        }
        if(s.empty())
            return
        r = s.top();
        s.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::inorder_iter() const 
{
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* r = m_root;
    while(true)
    {
        while(r)
        {
            s.push(r);
            r = r->left;
        }
        if(s.empty())
            return
        r = s.top();
        s.pop();
        std::cout << r->data << " ";
        r = r->right;
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::postorder_iter() const
{
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* r = m_root;
    while(true)
    {
        while(r)
        {
            if(r->right)
            {
                s.push(r->right);
            }
            s.push(r);
            r = r->left;
        }
        if(s.empty())
            return
        r = s.top();
        s.pop();
        if(r->right && !s.empty() && r->right == s.top())
        {
            s.pop();
            s.push(r);
            r = r->right;
        }
        else
        {
            std::cout << r->data << " ";
            r = nullptr;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::levelorder_iter() const
{
    std::queue<TreeNode<T>*> q;
    q.push(m_root);
    while(!q.empty())
    {
        TreeNode<T>* r = q.front();
        q.pop();
        std::cout << r->data << " ";
        if(r->left)
        {
            q.push(r->left);
        }
        if(r->right)
        {
            q.push(r->right);
        }
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::insert(TreeNode<T>* p)
{
    //TODO;
}


template <typename T>
void BinaryTree<T>::clear()
{
    clear_helper(m_root);
    m_root = nullptr;
}

template <typename T>
void BinaryTree<T>::preorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return
    std::cout << p->data << " ";
    preorder_rec_helper(p->left);
    preorder_rec_helper(p->right);
}

template <typename T>
void BinaryTree<T>::inorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return
    inorder_rec_helper(p->left);
    std::cout << p->data << " ";
    inorder_rec_helper(p->right);
}

template <typename T>
void BinaryTree<T>::postorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return
    postorder_rec_helper(p->left);
    postorder_rec_helper(p->right);
    std::cout << p->data << " ";
}

template <typename T>
void BinaryTree<T>::levelorder_rec_helper(TreeNode<T>* p)
{
    //TODO;
}


template <typename T>
void BinaryTree<T>::clear_helper(TreeNode<T>* p)
{
    if(p == nullptr)
        return
    clear_helper(p->left);
    clear_helper(p->right);
    delete p;
    p = nullptr;
}
