#pragma once

template <typename T>
struct TreeNode
{
    TreeNode(const T& d, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
        : data(d)
        , parent(p)
        , left(l)
        , right(r)
    {}
    ~TreeNode() {}
    
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};
