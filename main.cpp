#include <iostream>

#include "Binary_tree.h"
#include "TreeNode.h"

int main()
{
    TreeNode<char>* g = new TreeNode<char>('g');
	TreeNode<char>* h = new TreeNode<char>('h');
	TreeNode<char>* d = new TreeNode<char>('d', g, h);
	TreeNode<char>* b = new TreeNode<char>('b', nullptr, d);

	TreeNode<char>* i = new TreeNode<char>('i');
	TreeNode<char>* f = new TreeNode<char>('f', i);
	TreeNode<char>* e = new TreeNode<char>('e');
	TreeNode<char>* c = new TreeNode<char>('c', e, f);

	TreeNode<char>* a = new TreeNode<char>('a', b, c);

	BinaryTree<char> t(a);

	std::cout << "preorder: " << std::endl;
	t.preorder_rec();

	std::cout << "preorderI: " << std::endl;
	t.preorder_iter();

	std::cout << "inorder: " << std::endl;
	t.inorder_rec();

	std::cout << "inorderI: " << std::endl;
	t.inorder_iter();

	std::cout << "postorder: " << std::endl;
	t.postorder_rec();

	std::cout << "postorderI: " << std::endl;
	t.postorder_iter();

	std::cout << "levelorderI" << std::endl;
	t.levelorder_iter();
	
	std::cout << "levelorderRec" << std::endl;
	t.levelorder_rec();
	
    std::cout << t.high() << std::endl;
	
	return 0;
}
