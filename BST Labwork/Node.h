

#pragma once

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node: public NodeInterface {
private:
			int data;
			Node* left;
			Node* right;
			Node* parent;

public:

			Node(int data, Node* left = NULL, Node* right = NULL, Node* parent = NULL);
			~Node() {};
			int getData() const;
			Node* getLeftChild() const;
			Node* getRightChild() const;
			Node* getParent();
			void setLeft(Node* left);
			void setRight(Node* right);
			void setParent(Node* parent);


};

#endif