#pragma once
#include <string>

class Node
{
	/* A binary search tree is like a binary tree, but it also has a relation between the nodes and their children.
	A node has 3 attributes: the value, a pointer to the left child (which is a node) and a pointer to the right child 
	(which is also a node). When a node does not have a right or a left child than the pointer will be NULL.
	A node which has 0 child is named leaf. The left and the right pointer of a leaf will be NULL. */
public:
	int value;
	Node* left_child;
	Node* right_child;
	Node* n;

public:

	/* the constructor of the class Node. At the beginning the two pointer will be nullptr because this way it 
	will be easier for us to create the Tree class. */
	Node(int val);

	/* getter for the value attribute */
	int get_value(Node* node);

	/* setter for the pointers of an Object */

	/*Traverse the tree in an inorder way:
	The inorder traversal of a binary search tree involves visiting each of the nodes in the tree in the order:
	Traverse the left subtree -> Visit the root -> Traverse the right subtree*/
	void inorder(Node* n);

	/*Traverse the tree in a preorder way:
	The inorder traversal of a binary search tree involves visiting each of the nodes in the tree in the order:
	Visit the root -> Traverse the left subtree -> Traverse the right subtree */
	void preorder(Node* n);

	/*Traverse the tree in a postorder way:
	The inorder traversal of a binary search tree involves visiting each of the nodes in the tree in the order:
	Traverse the left subtree -> Traverse the right subtree -> Visit the root */
	void postorder(Node* n);


};