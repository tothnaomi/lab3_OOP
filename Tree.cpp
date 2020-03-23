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


/*Node* Tree::get_node(int v)
{
	Node* new_node = new Node(v);
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;

	return new_node; // this is a pointer to the new node created in this function
}*/

void Tree::insert(int v, Node* root)
{
	Node* crt = root;
	Node* parent = root;
	bool is_in_tree = false;
	while(not is_in_tree && crt != nullptr)
	{
		if (crt->value == v)
			is_in_tree = true;
		else
		{
			parent = crt;
			if (v < crt->value)
			{
				crt = crt->left_child;
			}
			else crt = crt->right_child;
		}
	}
	if (not is_in_tree)
	{
		Node* new_node = new Node(v);
		if (crt->value < v) new_node->left_child = crt;
		else new_node->right_child = crt;
		if (v < parent->value) parent->left_child = crt;
		else parent->right_child = crt; 
	}
}

bool Tree::in_tree(int v, Node* root)
{
	bool exists = false;
	while (exists && root != nullptr)
	{
		if (root->value == v) exists = true;
		else if (v < root->value)
			root = root->left_child;
		else
			root = root->right_child;
	}
	return exists; 
}

void Tree::delete_node(int v, Node* root)
{
	Node* current = root;
	Node* parent = root;
	while (current && current->value != v)
	{
		parent = current;
		if (current->value < v)
			current = current->left_child;
		else
		{
			current = current->right_child;
		}
	}

	if (current)
	{
		//case 1
		if (current->right_child == nullptr && current->left_child == nullptr)
		{
			if (parent->left_child == current)
				parent->left_child = nullptr;
			else
				parent->right_child = nullptr;
			delete current;
		}
		//case 2
		else if (current->left_child != nullptr && current->right_child == nullptr)
		{
			if (parent->left_child == current)
				parent->left_child = current->left_child;
			else
				parent->right_child = current->left_child;
			delete current;
		}
		else if (current->left_child == nullptr && current->right_child != nullptr)
		{
			if (parent->left_child == current)
				parent->left_child = current->right_child;
			else
				parent->right_child = current->right_child;
			delete current;
		}
		//case 3
		else if (current->left_child != nullptr && current->right_child != nullptr)
		{
			Node* min = FindMin(current->right_child);
			current->value = min->value;
			delete_node(current->value, current->right_child);
		}
	}
}


int Tree::count_nodes(Node* root)
{
	int sum = 0;
	if (root != nullptr)
	{
		sum++;
		sum = sum + count_nodes(root->left_child);
		sum = sum + count_nodes(root->right_child);
	}
	return sum;
}

int Tree::height()
{
	// TO DO 
	return 0;
}