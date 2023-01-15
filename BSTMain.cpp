#include <iostream>

#include "BST.h"

int main()
{
    BST<int> tree;
    BST<int> tree1;
    tree.insert(7);
    tree.insert(56);
    tree.insert(5);
    tree.insert(100);
    tree.insert(1);
    tree.insert(6);
    tree.insert(48);
    
    tree1.insert(7);
    tree1.insert(56);
    tree1.insert(5);
    tree1.insert(100);
    tree1.insert(1);
    tree1.insert(6);
    tree1.insert(47);
    
    tree.levelorder_iter();
    std::cout << std::endl;
    
    std::cout << "tree height is equal to: " << tree.height() << std::endl;
    std::cout << "tree width is equal to: " << tree.width() <<std::endl;
    
    std:: << "two trees are equal: " << " ";
    if(tree == tree1)
        std::cout << "true" << std::endl;
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}
