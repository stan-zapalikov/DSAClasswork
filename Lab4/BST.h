// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#pragma once
#include "BSTNode.h"
#include "dollar.h"
#include "Queue.h"
#include <string>
#include <fstream>

class BST {
private:
	BSTNode* root;
	int numOfNodes;
public:
	BST();
	bool search(Dollar* temp);
	void insert(Currency*);
	void remove(Currency*);
	void print(std::ofstream&);
	std::string BFS(BSTNode* node);
	std::string preOrder(BSTNode* node);
	std::string inOrder(BSTNode* node);
	std::string postOrder(BSTNode* node);
	int count();
	bool isEmpty();
};
