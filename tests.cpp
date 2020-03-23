#include <cassert>
#include <string>
#include "Node.h"
#include "Tree.h"
#include "tests.h"

using namespace std;

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
	
	Node* n1 = new Node(12); // this is the root 
	Node* n2 = new Node(17);
	Node* n3 = new Node(13);
	Node* n4 = new Node(14);
	Node* n5 = new Node(20);
	Node* n6 = new Node(18);
	Node* n7 = new Node(5);
	Node* n8 = new Node(3);
	Node* n9 = new Node(1);
	Node* n10 = new Node(7);
	Node* n11 = new Node(9);
	Node* n12 = new Node(8);
	Node* n13 = new Node(11);

	//setting the pointers
	n1->set_pointers(n2, n7);
	n2->set_pointers(n5, n3);
	n3->set_pointers(n4, nullptr);
	n5->set_pointers(nullptr, n6);
	n7->set_pointers(n10, n8);
	n8->set_pointers(nullptr, n9);
	n10->set_pointers(n11, nullptr);
	n11->set_pointers(n13, n12);

	n9->set_pointers(nullptr, nullptr); 
	n12->set_pointers(nullptr, nullptr);
	n13->set_pointers(nullptr, nullptr);
	n4->set_pointers(nullptr, nullptr);
	n6->set_pointers(nullptr, nullptr);

	Tree tree = Tree(n1);

	assert(tree.count_nodes(n1) == 13);

	tree.delete_node(13, n1);
	tree.delete_node(8, n1);

	assert(tree.in_tree(13, n1) == false);
	assert(tree.in_tree(20, n1) == true);
	assert(tree.in_tree(8, n1) == false);

	tree.insert(2, n1);
	assert(tree.in_tree(2, n1) == true);
}