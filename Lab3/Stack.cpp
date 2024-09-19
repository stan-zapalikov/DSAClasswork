// Stanislav Zapalikov
// Lab 3
// This program demonstrates the implementation of a linked list, a stack, and a queue
#include "Stack.h"

// pushes a currency to the top of the stack
void Stack::push(Currency* addedCurrency) {
	this->addCurrency(addedCurrency, 0);
}

// pops a currency from the top of the stack
Currency* Stack::pop() {
	return this->removeCurrency(0);
}

// returns the currency at the top of the stack
Currency* Stack::peek() {
	return this->getCurrency(0);
}

// prints the stack
std::string Stack::printStack() {
	return this->printList();
}

// destructor
Stack::~Stack() {
	while (!this->isListEmpty()) {
		this->removeCurrency(0);
	}
}
