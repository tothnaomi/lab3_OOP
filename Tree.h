#pragma once
#include <vector>
#include "Node.h"
using namespace std;

/* We can use a vector to implement the class Tree. At the beginning the vector will be empty, 
because no node will be in the tree. */

class Tree
{
	/* I will use linked list and I will store the address of the root node because
	this way I will have access to the every element of the tree (we have pointrs to left and right 
	child). */
	Node* root;

public:

	Tree(Node* node)
	{
		this->root = node;
	}


	Node* FindMin(Node* root);
	
	/* inserts a node in the binary search tree so that the relation of it didn't change. 
	v is the value of the node and the tree is the node. 
	We have to be carefull with the pointers !!! */
	void insert(int v);

	/* deletes a node from a binary search tree.
	We have to be carefull with the pointers !!!
	3 cases: when we delete a leaf node(without child), when we are deleting a node with 1 child (practically we have
	2 cases here: when the node has left child and when the node has right child) and the last case is when we want 
	to delete a node with 2 children. 
	https://youtu.be/gcULXE7ViZw */
	void delete_node(int v, Node* root);

	/* returns true, if the node with the value v is in the tree or return false if the node is not in the tree. */
	bool in_tree(int v);

	/* counts how many nodes in a tree are. We can count how many elements in our vector are (this will be
	the number of nodes).
	If the tree is empty the number of nodes will be 0.*/
	int count_nodes(Node* root);

	/* counts how many edges in a tree are. We have to go along the vector and if none of the pointers of the current node
	are nullptr than we can increase the sum with 2 (because one node has 2 children -> 2 edges).
	If the tree is empty it will return 0.
	We can verify before we go along the vector if the binary tree is full (2^n - 1 = number of nodes), 
	because than the number of edges will be 2^n - 2 .*/
	int count_edges(Node* root);

	/* returns the height of the tree.
	If the tree is empty or it contains just one node (the root) it will return 0.
	The height is [log2(n)] (the int part of log2(n)) if the binary tree is complete (perfect) and has n nodes. 
	This Link should help: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/ */
	int height(Node* root);
};