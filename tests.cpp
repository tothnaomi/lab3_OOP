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

}