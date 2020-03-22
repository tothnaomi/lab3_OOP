#include <iostream>
#include <vector>
#include "Tree.h"
#include "Node.h"
#include <vector>
using namespace std;

Node* Tree::FindMin(Node* root)
{
	int min = root->right_child->value;
	if (root->right_child->left_child == nullptr) return root->right_child;
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
	if (root->value = v) return root;
	else
	{
		if (v < root->value) search_node(v, root->left_child);
		else search_node(v, root->right_child->right_child);
	}
}

void Tree::delete_node(int v, Node* root)
{
	Node* delete_node = search_node(v, root);
	// we found the node which we want to delete.
	if (delete_node->left_child == nullptr && delete_node->right_child == nullptr)
	{
		delete delete_node; // delete from heap memory
	}
	else if (delete_node->left_child == nullptr)
	{
		Node* temp = delete_node;
		delete_node = delete_node->right_child;
		delete temp;
	}
	else if (delete_node->right_child == nullptr)
	{
		Node* temp = delete_node;
		delete_node = delete_node->left_child;
		delete temp;
	}
	else
	{
		Node* temp = FindMin(delete_node->right_child);
		delete_node->value = temp->value;
		//delete_node(temp->value, delete_node->right_child);
	}
	
}


int Tree::count_edges()
{
	//TO IMPLEMENT
}

int Tree::height()
{
	//toooo implemeent
}