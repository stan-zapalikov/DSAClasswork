// Stanislav Zapalikov
// Lab 3
// This program demonstrates the implementation of a linked list, a stack, and a queue
#pragma once
#include "SinglyLinkedList.h"
#include "currency.h"
#include "LinkNode.h"

class Queue : SinglyLinkedList {
public:
	Queue() : SinglyLinkedList() {};
	void enqueue(Currency*);
	Currency* dequeue();
	Currency* peekFront();
	Currency* peekRear();
	std::string printQueue();
	~Queue();
};
