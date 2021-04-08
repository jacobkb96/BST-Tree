
#include "BST.h"
#include "Node.h"
#include "NodeInterface.h"

using namespace std;


//Implementing the constructor and destructor
BST::BST() {
	this->root = NULL;
	this->size = 0;
}
BST::~BST() {
	this->clear();
}
//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node* BST::getRootNode() const{
	return this->root;
}


/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
		if (this->size == 0){
			this->root = new Node(data);
			this->size++;
			return true;
		}
		Node* tracker = this->root;   //pointer that moves around the tree
		while(tracker != NULL){
			
			if(tracker->getData() > data){ //traverse the left tree
				if(tracker->getLeftChild() == NULL){  //found the spot!!
					tracker->setLeft(new Node(data,NULL,NULL,tracker));
					this->size++;
					return true;
				} else {  //Didn't find the spot so set tracker to the next lower child
					tracker = tracker->getLeftChild();
				}
			}
			else if (tracker->getData() < data){  //traverse the right tree
				if(tracker->getRightChild() == NULL){  //found the spot!!
					tracker->setRight(new Node(data,NULL,NULL,tracker));
					this->size++;
					return true;
				} else {  //Didn't find the spot so set tracker to the next higher child
					tracker = tracker->getRightChild();
				}
			}
			else {  //The data value was already in the tree!!!!!!!!!!!
						return false;
			}
		}
		// If the code gets to here the tree must have been empty but size wasn't zero for some reason
		this->root = new Node(data);
		this->size++;
		return true;
}

//Gives the location of the data that is being looked for
Node* BST::search(Node *root, int data){
	if(root == NULL){											//This will return if the data is not in the tree
		return NULL;
	}
	else if(root->getData() < data){				//Searches through recursively to find the match
		return search(root->getRightChild(),data);
	}
	else if(root->getData() >data){
		return search(root->getLeftChild(),data);
	}
	else{						//It found the match!! This is base case, always returned if data is matched
		return root;
	}
}

/*This crazy function was tough. I had to get some help from some friends.
Arguments are the value being replaced and the value it is being replaced with. 
This function does the swapping while the remove function works out which value should be the new one */
void BST::replace(Node* oldStuff, Node* newStuff){
	
	/* Starts by checking if the old value is the root. Then makes the parent point to new value based on if the old value was the right or left child of the parent */
	if (oldStuff->getParent() != NULL){			
		if(oldStuff->getParent()->getLeftChild()==oldStuff){
			oldStuff->getParent()->setLeft(newStuff);
		}
		else{
			oldStuff->getParent()->setRight(newStuff);
		}
	}
	else{						//The thing being replaced is the root.
		this->root = newStuff;
	}

	/* If the new value isn't NULL lots of fun switching is required. Set new value's parent to old value's parent for bookkeeping. The new value then gets the children of the old value and those children are assigned the new value as their parent. */
	if(newStuff != NULL){
		newStuff->setParent(oldStuff->getParent());
		if(oldStuff->getLeftChild()!= newStuff && oldStuff->getRightChild()!=newStuff){
			newStuff->setLeft(oldStuff->getLeftChild());
			if(newStuff->getLeftChild()!=NULL){
				newStuff->getLeftChild()->setParent(newStuff);
			}
			newStuff->setRight(oldStuff->getRightChild());
			if(newStuff->getRightChild()!=NULL){
				newStuff->getRightChild()->setParent(newStuff);
			}
		}
	}
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
	Node* tracker = search(this->root, data);
	if (tracker==NULL){   //tracker set to NULL by search function if no match is found
		return false;
	}
	if(tracker->getRightChild()==NULL){
		replace(tracker, tracker->getLeftChild());
		delete tracker;
		this->size--;
		return true;
	}
	if(tracker->getLeftChild() == NULL){
		replace(tracker,tracker->getRightChild());
		delete tracker;
		this->size--;
		return true;
	}
	/* This part is for finding the rightmost value in the left sub tree of the value being removed. Then puts its left child in its place and then moves up to replace the value being removed */
	else{
		Node* track2 = tracker -> getLeftChild();
		while(track2->getRightChild()!= NULL){
			track2 = track2->getRightChild();
		}
		replace(track2,track2->getLeftChild());
		replace(tracker,track2);
		delete tracker;
		return true;
	}
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::destroy(Node *root){
	if(root!=NULL){
		destroy(root->getLeftChild()); 	// recursively go through tree until end is found
		destroy(root->getRightChild());
		delete root;
	}
}

void BST::clear(){
	destroy(this->root);
	this->root = NULL;
	this->size = 0;

}