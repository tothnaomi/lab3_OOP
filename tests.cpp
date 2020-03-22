#include <cassert>
#include <string>
#include "Node.h"
#include "Tree.h"
#include "tests.h"

using namespace std;

string inorder()
{

}

string preorder()
{

}

string postorder()
{

}

void testAll()
{

	/*
	
					12
                 /       \
                5        17
             /     \     /  \
			3		7   13   20
           /        \    \    /
          1         9     14  18
				   /  \
                 8      11
			
	*/

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

	// tests 
	tree.delete_node(14, &root);
	assert(tree.search_node(14, &root) == nullptr);
	tree.delete_node(20, &root);
	assert(tree.search_node(20, &root) == nullptr);

	tree.insert(20, &root);
}