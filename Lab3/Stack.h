// Stanislav Zapalikov
// Lab 3
// This program demonstrates the implementation of a linked list, a stack, and a queue
#pragma once
#include "SinglyLinkedList.h"
#include "currency.h"
#include "LinkNode.h"

class Stack : SinglyLinkedList {
public:
	Stack() : SinglyLinkedList() {};
	void push(Currency*);
	Currency* pop();
	Currency* peek();
	std::string printStack();
	~Stack();
};
