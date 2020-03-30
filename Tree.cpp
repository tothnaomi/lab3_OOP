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


void Tree::insert(int v)
{

	Node* crt = this->root;
	Node* parent = this->root;
	bool exists = false;
	
	while (crt && !exists)
	{
		if (crt->value == v) exists = true;
		else
		{
			parent = crt;
			if (v < crt->value)
				crt = crt->left_child;
			else crt = crt->right_child;
		}
	}

	if (!exists)
	{
		Node* new_node = new Node(v);
		if (v < parent->value)
			parent->left_child = new_node;
		else
			parent->right_child = new_node;
	}
}

bool Tree::in_tree(int v)
{
	bool exists = false;
	while (exists == false && this->root)
	{
		if (this->root->value == v) exists = true;
		else if (v < this->root->value)
			this->root = this->root->left_child;
		else
			this->root = this->root->right_child;
	}
	return exists; 
}

void Tree::delete_node(int v, Node* node)
{
	Node* current = this->root;
	Node* parent = this->root;
	while (current != nullptr && current->value != v)
	{
		parent = current;
		if (current->value < v)
			current = current->right_child;
		else
		{
			current = current->left_child;
		}
	}

	if (current != nullptr)
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


int Tree::count_nodes(Node* node)
{
	int sum = 0;
	if (this->root != nullptr)
	{
		sum++;
		sum = sum + count_nodes(root->left_child);
		sum = sum + count_nodes(root->right_child);
	}
	return sum;
}

int Tree::count_edges(Node* root)
{
	int count = 0;
	int sum = 0;
	if (root != nullptr)
	{
		sum++;
		sum = sum + count_nodes(root->left_child);
		sum = sum + count_nodes(root->right_child);
	}
	count = sum - 1;
	return count;
}


int Tree::height(Node* root)
{
	int left_height, right_height;

	if (root = nullptr)

		return -1;

	
	left_height = height(root->left_child);

	right_height = height(root->right_child);

	

	if (left_height > right_height)

		return left_height+1;

	else

		return right_height+1;

	return 0;
}