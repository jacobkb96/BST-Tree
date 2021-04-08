#include <iostream>
#include "NodeInterface.h"
#include "Node.h"



Node::Node(int data, Node *left, Node *right, Node *parent){
	this->data = data;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
	return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node* Node::getLeftChild() const{
	return left;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node* Node::getRightChild() const{
	return right;
}

// returns the parent of the node! Very useful for replacing 
Node* Node::getParent(){
	return parent;
}

//set child to the left for adding
void Node::setLeft(Node *left){
	this->left = left;
}

//set child to the right for adding
void Node::setRight(Node *right){
	this->right = right;
}

//set parent for replacing
void Node::setParent(Node *parent){
	this->parent = parent;
}


