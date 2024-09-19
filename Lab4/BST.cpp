// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#include "BST.h"
#include "BSTNode.h"
#include "dollar.h"
#include "Queue.h"

BST::BST() {
	root = nullptr;
	numOfNodes = 0;
}

bool BST::search(Dollar* temp) {

	// Searches for a node in the BST that contains the given dollar amount
	// Pre: temp - a pointer to a Dollar object to be searched for
	// Post: NA
	// Return: true or false

	BSTNode* cur = root;
	while (cur) {
		if (temp->isEqual(*cur->data)) {
			return true;
		}
		else if (cur->data->isGreater(*temp)) {
			cur = cur->getLeftChild();
		}
		else {
			cur = cur->getRightChild();
		}
	}
	return false;
}

void BST::insert(Currency* dollars) {

	// Inserts a new node with the given dollar amount in the correct position in the BST
	// Pre: dollars - a pointer to a currency object to insert
	// Post: A new node containing the given dollar amount is added to the BST
	//		-numOfNodes incremented after node is inserted
	// Return: NA
	
	BSTNode* node = new BSTNode(dollars);
	if (isEmpty()) {
		root = node;
	}
	else {
		BSTNode* currNode = root;
		while (currNode) {
			if (currNode->data->isGreater(*node->data)) {
				if (!currNode->getLeftChild()) {
					currNode->leftChild = node;
					currNode = nullptr;
				}
				else {
					currNode = currNode->getLeftChild();
				}
			}
			else {
				if (!currNode->getRightChild()) {
					currNode->rightChild = node;
					currNode = nullptr;
				}
				else {
					currNode = currNode->getRightChild();
				}
			}
		}
	}
	numOfNodes++;
}

void BST::remove(Currency* dollars) {

	// Removes a node from the BST that contains the given dollar amount
	// Pre: Currency object pointer
	// Post: if the object is found in the BST it gets removed
	//		-numOfNodes decremented if the node is removed
	// Return: NA

	BSTNode* par = nullptr; // parent
	BSTNode* cur = root; // current

	while (cur) { // Search for node
		if (cur->data->isEqual(*dollars)) { // Node found
			if (!cur->getLeftChild() && !cur->getRightChild()) { // Remove leaf
				if (!par) {
					root = nullptr;
				}
				else if (par->getLeftChild() == cur) {
					par->leftChild = nullptr;
				}
				else {
					par->rightChild = nullptr;
				}
			}
			else if (!cur->getRightChild()) { // Remove node with only left child
				if (!par) {
					root = cur->getLeftChild();
				}
				else if (par->getLeftChild() == cur) {
					par->leftChild = cur->getLeftChild();
				}
				else {
					par->rightChild = cur->getLeftChild();
				}
			}
			else if (!cur->getLeftChild()) { // Remove node with only right child
				if (!par) {
					root = cur->getRightChild();
				}
				else if (par->getLeftChild() == cur) {
					par->leftChild = cur->getRightChild();
				}
				else {
					par->rightChild = cur->getRightChild();
				}
			}
			else { // Remove node with two children
				// Find successor (leftmost child of right subtree)
				BSTNode* suc = cur->getRightChild();
				while (suc->getLeftChild()) {
					suc = suc->getLeftChild();
				}
				Currency* successorData = suc->data;
				remove(successorData); // Remove successor
				cur->data = successorData;
			}
			numOfNodes--;
			return; // Node found and removed
		}
		else if (dollars->isGreater(*cur->data)) {
			par = cur;
			cur = cur->getRightChild();
		}
		else {
			par = cur;
			cur = cur->getLeftChild();
		}
	}
	return; // Node not found
}

std::string BST::BFS(BSTNode* node) {

	// Traverses the tree using BFS and returns a string with all the nodes visited
	// Pre: node - BSTNode pointer for the starting node (root)
	// Post: NA
	// Return: String

	std::string out = "";
	if (isEmpty()) {
		return out;
	}
	Queue<BSTNode> visited;
	visited.enqueue(node);

	while (!visited.isListEmpty()) {
		BSTNode* temp = visited.dequeue();
		out += temp->data->toString() + " ";

		if (temp->getLeftChild())
			visited.enqueue(temp->getLeftChild());
		if (temp->getRightChild())
			visited.enqueue(temp->getRightChild());
	}
	return out;
}


std::string BST::inOrder(BSTNode* node) {

	// Traverses the tree using in-order traversal and returns a string with all the nodes visited
	// Pre: node - BSTNode pointer for the starting node (root)
	// Post: NA
	// Return: String

	std::string out = "";
	if (!node) {
		return "";
	}
	out = inOrder(node->getLeftChild());
	out += node->data->toString() += " ";
	out += inOrder(node->getRightChild());
	return out;

}

std::string BST::postOrder(BSTNode* node) {

	// Traverses the tree using post-order traversal and returns a string with all the nodes visited
	// Pre: node - BSTNode pointer for the starting node (root)
	// Post: NA
	// Return: String

	std::string out = "";
	if (!node) {
		return "";
	}

	out += postOrder(node->getLeftChild());
	out += postOrder(node->getRightChild());
	out += node->data->toString() += " ";
	return out;
}

std::string BST::preOrder(BSTNode* node) {

	// Traverses the tree using pre-order traversal and returns a string with all the nodes visited
	// Pre: node - BSTNode pointer for the starting node (root)
	// Post: NA
	// Return: String

	std::string out = "";
	if (!node) {
		return "";
	}
	out += node->data->toString() += " ";
	out += preOrder(node->getLeftChild());
	out += preOrder(node->getRightChild());

	return out;
}

void BST::print(std::ofstream& file) {
	
	// Prints all the traversal methods to console and outputs them to a given ofstream file
	// Pre: file - ofstream instance passed by reference for outputting the data
	// Post: NA
	// Return: NA

	std::string output = "";
	output += "BFS: " + BFS(root) + "\n";
	output += "In order: " + inOrder(root) + "\n";
	output += "Pre order: " + preOrder(root) + "\n";
	output += "Post order: " + postOrder(root) + "\n";

	file << output << std::endl;
	std::cout << output << std::endl;
}

int BST::count() {

	// Returns the amount of nodes in the tree
	// Pre: NA
	// Post: NA
	// Return: int

	return numOfNodes;
}

bool BST::isEmpty() {

	// Checks if the tree is empty by seeing if the root is empty
	// Pre: NA
	// Post: NA
	// Return: bool

	if (root) {
		return false;
	}
	else {
		return true;
	}
}