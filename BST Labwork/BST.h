#pragma once
#include "BSTInterface.h"
#include "Node.h"


using namespace std;

class BST : public BSTInterface {
	protected:
		Node *root;
		int size;

	public:
		BST();
		~BST();
		
		Node* getRootNode() const;

		bool add(int data);

		bool remove(int data);
		//Need replace when removing stuff in the middle of the tree
		void replace(Node* oldStuff, Node* newStuff);

		Node* search(Node* root, int data);

		//Needed something that accepts an argument for clearing the tree
		void destroy(Node* root);
		
		void clear();
};