#include <iostream>
#include "Node.h"

Node::Node(int val)
{
	value = val;
	left_child = nullptr;
	right_child = nullptr; 
}

int Node::get_value()
{
	return this->value;
}

void Node::set_pointers(Node* right_ptr, Node* left_ptr)
{
	this->right_child = right_ptr;
	this->left_child = left_ptr;
}