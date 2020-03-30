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

	Tree tree = Tree(n1); // n1 is the root of this tree
	tree.insert(13);
	tree.insert(14);

	assert(tree.count_nodes(n1) == 3);

	tree.insert(5);
	tree.insert(20);

	assert(tree.count_nodes(n1) == 5);

	tree.delete_node(14, n1);
	assert(tree.count_nodes(n1) == 4);


	//setting the pointers
	/*n1->set_pointers(n2, n7);
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

	assert(tree.in_tree(13) == false);
	assert(tree.in_tree(20) == true);
	assert(tree.in_tree(8) == false);

	tree.insert(2);
	assert(tree.in_tree(2) == true);*/
}