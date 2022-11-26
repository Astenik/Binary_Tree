#pragma once

template <typename T>
struck TreeNode
{
    TreeNode(const T& d, TreeNode<T>* l, TreeNode<T>* r)
        : data(d)
        , left(l)
        , right(r)
    {}
    ~TreeNode() {}
    
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};
