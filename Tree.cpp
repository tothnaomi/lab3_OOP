#include <iostream>
#include <vector>
#include "Tree.h"
#include "Node.h"
#include <vector>
using namespace std;

Node* Tree::FindMin(Node* node)
{
	//node is the right child of the node in which right subtree we are searching for minimum. 
	if (node->left_child == nullptr) return node;
	else return FindMin(node->left_child);
}


Node* Tree::get_node(int v)
{
	Node* new_node = new Node(v);
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;

	return new_node; // this is a pointer to the new node created in this function
}

void Tree::insert(int v, Node* root)
{
	if (root == nullptr)
	{
		root = get_node(v);
	}
	else
	{
		if (v <= root->value)
			//root->left_child = insert(v, root->left_child);
			insert(v, root->left_child);
		else
			//root->right_child = insert(v, root->right_child);
			insert(v, root->right_child);
	}
}

Node* Tree::search_node(int v, Node* root)
{
	if (root->value == v) return root;
	else
	{
		if (v < root->value) search_node(v, root->left_child);
		else search_node(v, root->right_child);
	}
	return nullptr; // if the node is not in the tree
}

void Tree::delete_node(int v, Node* root)
{
	Node* d_node = search_node(v, root);
	
	if (d_node->left_child == nullptr && d_node->right_child == nullptr)
	{
		delete d_node; // delete from heap memory
	}
	else if (d_node->left_child == nullptr)
	{
		Node* temp = d_node;
		d_node = d_node->right_child;
		delete temp;
	}
	else if (d_node->right_child == nullptr)
	{
		Node* temp = d_node;
		d_node = d_node->left_child;
		delete temp;
	}
	else
	{
		Node* temp = FindMin(d_node->right_child);
		d_node->value = temp->value;
		delete_node(temp->value, d_node->right_child);
	}
}


int Tree::count_edges()
{
	//TO IMPLEMENT
	return 0;
}

int Tree::height()
{
	//toooo implemeent
	return 0;
}