#pragma once

class Node
{
	/* A binary search tree is like a binary tree, but it also has a relation between the nodes and their children.
	A node has 3 attributes: the value, a pointer to the left child (which is a node) and a pointer to the right child 
	(which is also a node). When a node does not have a right or a left child than the pointer will be NULL.
	A node which has 0 child is named leaf. The left and the right pointer of a leaf will be NULL. */
	int value;
	Node* left_child;
	Node* right_child;

public:

	/* the constructor of the class Node. At the beginning the two pointer will be nullptr because this way it 
	will be easier for us to create the Tree class. */
	Node(int val);

	/* getter for the value attribute */
	int get_value();

	/* setter for the value */
	void set_value(int val);

	/* setter for the pointers of an Object */
	void set_pointers(Node* right_ptr, Node* left_ptr);

};