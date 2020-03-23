#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"
#include "tests.h"

int main()
{
    /*std::cout << "\nInorder traversal of binary tree is \n";
    std::string inorder(Node * root);

    std::cout << "\nPreorder traversal of binary tree is \n";
    std::string preorder(Node * root);

    std::cout << "\nPostorder traversal of binary tree is \n";
    std::string postorder(Node * root);*/

	Node root = Node(12);
	// right subtree of the root 
	Node n1 = Node(17);
	Node n2 = Node(13);
	Node n3 = Node(14);
	Node n4 = Node(20);
	Node n5 = Node(18);

	// left subtree of the root
	Node n6 = Node(5);
	Node n7 = Node(7);
	Node n8 = Node(9);
	Node n9 = Node(11);
	Node n10 = Node(8);
	Node n11 = Node(3);
	Node n12 = Node(1);

	// setting the pointers to create the tree
	root.set_pointers(&n1, &n6);
	n1.set_pointers(&n4, &n2);
	n2.set_pointers(&n3, nullptr);
	n4.set_pointers(nullptr, &n5);
	n6.set_pointers(&n7, &n11);
	n11.set_pointers(nullptr, &n12);
	n7.set_pointers(&n8, nullptr);
	n8.set_pointers(&n9, &n10);

	// tree
	Tree tree = Tree(&root);
	cout << tree.count_nodes(&root)<<endl;



	return 0;
}