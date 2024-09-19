// Stanislav Zapalikov
// Lab 3
// This program demonstrates the implementation of a linked list, a stack, and a queue
#pragma once
#include "LinkNode.h"
#include "currency.h"
#include <string>

class SinglyLinkedList {
private:
	int count;
	LinkNode* start;
	LinkNode* end;
public:
	SinglyLinkedList();
	void addCurrency(Currency*, int index);
	Currency* removeCurrency(Currency*);
	Currency* removeCurrency(int index);
	int findCurrency(Currency*);
	Currency* getCurrency(int index);
	std::string printList();
	bool isListEmpty();
	int countCurrency();
};
