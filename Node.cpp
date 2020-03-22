#include <iostream>
#include "Node.h"
#include <string.h>
#include <string>
#include "Tree.h"


Node::Node(int val)
{
	value = val;
	left_child = nullptr;
	right_child = nullptr;

}


//std::string Node::inorder(Node* n) /* Given a binary tree, print its nodes in inorder*/
/*{

    if (n == NULL)
        return 0;

	std::string inorder(n -> Node::left_child);
	
	std::cout << n->Node * root << " ";

	std::string inorder(n  -> Node::right_child);
	
}*/

//std::string Node::preorder(Node* n) /* Given a binary tree, print its nodes in postorder traversal. */
/*{
	if (n == NULL)
		return 0;

	std::cout << n->Node * root << " ";

	std::string inorder(n->Node::left_child);

	std::string inorder(n->Node::right_child);

}*/

//std::string Node::postorder(Node* n)  /* Given a binary tree, print its nodes in preorder*/
/*{
	if (n == NULL)
		return 0;

	std::string inorder(n->Node::left_child);

	std::string inorder(n->Node::right_child);

	std::cout << n->Node * root << " ";

}*/


int Node::get_value(Node* node)
{
	return node->value;
}


void Node::set_pointers(Node* right_ptr, Node* left_ptr)
{
	this->right_child = right_ptr;
	this->left_child = left_ptr;
}

