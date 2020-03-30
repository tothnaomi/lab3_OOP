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


int Node::get_value(Node* node)
{
	return node->value;
}


void Node::inorder(Node* n) /* Given a binary tree, print its nodes in inorder traversal*/
{

	if (n != nullptr)

		inorder(n->left_child);
		cout << n;
		inorder(n->right_child);

}

void Node::preorder(Node* n) /* Given a binary tree, print its nodes in preorder traversal. */
{

	if (n != nullptr)

		cout<<n;
		preorder(n->left_child);
		preorder(n->right_child);
	
	
}

void Node::postorder(Node* n)  /* Given a binary tree, print its nodes in postorder traversal*/
{
	if (n != nullptr)

		postorder(n->left_child);
		postorder(n->right_child);
		cout << n;

}

