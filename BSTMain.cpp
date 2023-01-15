#include <iostream>

#include "BST.h"

int main()
{
    BST<int> tree;
    tree.insert(7);
    tree.insert(56);
    tree.insert(5);
    tree.insert(100);
    tree.insert(1);
    tree.insert(6);
    tree.insert(47);
    
    tree.levelorder_iter();
    std::cout << std::endl;
    
    std::cout << "tree height is equal to: " << tree.height() << std::endl;
    std::cout << "tree width is equal to: " << tree.width() <<std::endl;
    
    
    return 0;
}
