// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#pragma once
#include "dollar.h"

class BSTNode {
public:
	Currency* data;
	BSTNode* leftChild;
	BSTNode* rightChild;

	BSTNode() { 
		data = nullptr;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	BSTNode(Currency* newData) {
		data = newData;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	BSTNode* getLeftChild() {
		return leftChild;
	}
	BSTNode* getRightChild() {
		return rightChild;
	}
};
