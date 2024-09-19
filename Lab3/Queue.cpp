#include "Queue.h"

// add a currency to the end of the list
void Queue::enqueue(Currency* addedCurrency) {
	this->addCurrency(addedCurrency, this->countCurrency());
}

// remove a currency from the front of the list
Currency* Queue::dequeue() {
	return this->removeCurrency(0);
}

// return the currency at the front of the list
Currency* Queue::peekFront() {
	return this->getCurrency(0);
}

// return the currency at the rear of the list
Currency* Queue::peekRear() {
	return this->getCurrency(this->countCurrency() - 1);
}

// return the list as a string
std::string Queue::printQueue() {
	return this->printList();
}

// destructor
Queue::~Queue() {
	while (!this->isListEmpty()) {
		this->removeCurrency(0);
	}
}
