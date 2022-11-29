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
    
    int height() const;
    int width() const; 
    int count_of_leaves() const;
    int count_of_nodes() const;
    
    void clear();

private:
    void preorder_rec_helper(TreeNode<T>*) const;
    void inorder_rec_helper(TreeNode<T>*) const;
    void postorder_rec_helper(TreeNode<T>*) const;
    void levelorder_rec_helper(TreeNode<T>*) const;
    void printCurrentLevel(TreeNode<T>*, int) const;
    void clear_helper(TreeNode<T>*);
    
    int height_helper(TreeNode<T>*) const;
    
protected:
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
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::inorder_rec() const 
{
    inorder_rec_helper(m_root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::postorder_rec() const 
{
    postorder_rec_helper(m_root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::levelorder_rec() const
{
    levelorder_rec_helper(m_root);
    std::cout << std::endl;
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
            return;
        r = s.top();
        s.pop();
    }
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
            return;
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
            return;
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
int BinaryTree<T>::height() const
{
    return height_helper(m_root) - 1;
}

template <typename T>
void BinaryTree<T>::clear()
{
    clear_helper(m_root);
    m_root = nullptr;
}

template <typename T>
int BinaryTree<T>::width() const
{
    if(m_root == nullptr)
        return 0;
    std::queue<TreeNode<T>*> q;
    q.push(m_root);
    int w = 1;
    while(!q.empty())
    {
        const int count = q.size();
        if(count > w)
        {
            w = count;
        }
        for(int i = 0; i < count; ++i)
        {
            TreeNode<T>* p = q.front();
            q.pop();
            if(p->left)
            {
                q.push(p->left);
            }
            if(p->right)
            {
                q.push(p->right);
            }
        }
    }
    return w;
}

template <typename T>
int BinaryTree<T>::count_of_leaves() const
{
    int count = 0;
    std::queue<TreeNode<T>*> q;
    q.push(m_root);
    while(!q.empty())
    {
        TreeNode<T>* r = q.front();
        q.pop();
        if(r->left == nullptr && r->right == nullptr)
        {
            ++count;
        }
        if(r->left)
        {
            q.push(r->left);
        }
        if(r->right)
        {
            q.push(r->right);
        }
    }
    return count;
}

template <typename T>
int BinaryTree<T>::count_of_nodes() const
{
    int count = 0;
    std::queue<TreeNode<T>*> q;
    q.push(m_root);
    while(!q.empty())
    {
        TreeNode<T>* r = q.front();
        q.pop();
        ++count;
        if(r->left)
        {
            q.push(r->left);
        }
        if(r->right)
        {
            q.push(r->right);
        }
    }
    return count;
}

template <typename T>
void BinaryTree<T>::preorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return;
    std::cout << p->data << " ";
    preorder_rec_helper(p->left);
    preorder_rec_helper(p->right);
}

template <typename T>
void BinaryTree<T>::inorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return;
    inorder_rec_helper(p->left);
    std::cout << p->data << " ";
    inorder_rec_helper(p->right);
}

template <typename T>
void BinaryTree<T>::postorder_rec_helper(TreeNode<T>* p) const
{
    if(p == nullptr)
        return;
    postorder_rec_helper(p->left);
    postorder_rec_helper(p->right);
    std::cout << p->data << " ";
}

template <typename T>
void BinaryTree<T>::levelorder_rec_helper(TreeNode<T>* p) const
{
    int h = height();
    for(int i = 0; i <= h; ++i)
    {
        printCurrentLevel(p, i);
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printCurrentLevel(TreeNode<T>* r, int level) const
{
    if(r == nullptr)
        return;
    if(level == 0)
        std::cout << r->data << " ";
    else if(level > 0)
    {
        printCurrentLevel(r->left, level - 1);
        printCurrentLevel(r->right, level - 1);
    }
}

template <typename T>
void BinaryTree<T>::clear_helper(TreeNode<T>* p)
{
    if(p == nullptr)
        return;
    clear_helper(p->left);
    clear_helper(p->right);
    delete p;
    p = nullptr;
}

template <typename T>
int BinaryTree<T>::height_helper(TreeNode<T>* r) const
{
    if(r == nullptr)
        return 0;
    return 1 + std::max(height_helper(r->right), height_helper(r->left));
}
