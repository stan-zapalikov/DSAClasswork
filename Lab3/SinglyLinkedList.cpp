#include "SinglyLinkedList.h"
#include "currency.h"
#include <string>

// default constructor
SinglyLinkedList::SinglyLinkedList() {
	count = 0;
	start = nullptr;
	end = nullptr;
}

// add a currency to the list at a specified index
void SinglyLinkedList::addCurrency(Currency* addedMoney, int index) {
	LinkNode* newNode = new LinkNode;
	newNode->setData(addedMoney);
	if (start == nullptr) {
		start = newNode;
		end = newNode;
		newNode->setNext(nullptr);
	}
	else if (index == 0) {
		newNode->setNext(start);
		start = newNode;
	}
	else if (index == count) {
		newNode->setNext(nullptr);
		end->setNext(newNode);
		end = newNode;
	}
	else {
		LinkNode* currNode = start;
		for (int i = 0; i < index - 1; i++) {
			currNode = currNode->getNext();
		}
		newNode->setNext(currNode->getNext());
		currNode->setNext(newNode);
	}
	count++;
}

// remove a currency from the list
Currency* SinglyLinkedList::removeCurrency(Currency* removedCurrency) {
	if (start == nullptr) {
		return nullptr;
	}

	LinkNode* currNode = start;
	LinkNode* prevNode = nullptr;

	while (currNode != nullptr) {
		if (currNode->getData()->getWhole() == removedCurrency->getWhole() &&
			currNode->getData()->getFrac() == removedCurrency->getFrac()) {
			if (prevNode == nullptr) {
				start = currNode->getNext();
			}
			else {
				prevNode->setNext(currNode->getNext());
			}

			if (currNode == end) {
				end = prevNode;
			}

			count--;
			return currNode->getData();
		}

		prevNode = currNode;
		currNode = currNode->getNext();
	}

	return nullptr;
}

// remove a currency from the list at a specified index
Currency* SinglyLinkedList::removeCurrency(int index) {
	if (start == nullptr || index >= count || index < 0) {
		return nullptr;
	}

	LinkNode* currNode = start;
	LinkNode* prevNode = nullptr;

	for (int i = 0; i < index; i++) {
		prevNode = currNode;
		currNode = currNode->getNext();
	}

	if (prevNode == nullptr) {
		start = currNode->getNext();
	}
	else {
		prevNode->setNext(currNode->getNext());
	}

	if (currNode == end) {
		end = prevNode;
	}

	count--;
	return currNode->getData();
}

// find a currency in the list
int SinglyLinkedList::findCurrency(Currency* targetCurrency) {
	LinkNode* currNode = new LinkNode;
    currNode = start;
	for (int i = 0; i < count; i++) {
		if (currNode->getData()->getWhole() == targetCurrency->getWhole() &&
			currNode->getData()->getFrac() == targetCurrency->getFrac()) {
			return i;
		}
		else {
			currNode = currNode->getNext();
		}
	}
	return -1;
}

// get a currency from the list at a specified index
Currency* SinglyLinkedList::getCurrency(int index) {
	LinkNode* currNode = new LinkNode;
	currNode = start;
	for (int i = 0; i < index; i++) {
		currNode = currNode->getNext();
	}
	return currNode->getData();
}

// return the list as a string
std::string SinglyLinkedList::printList() {
	LinkNode* currNode = new LinkNode;
	currNode = start;
	std::string list = "";
	for (int i = 0; i < count; i++) {
		list += currNode->getData()->toString() + "\n";
		currNode = currNode->getNext();
	}
	return list;
}

// check if the list is empty
bool SinglyLinkedList::isListEmpty() {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

// return the number of currencies in the list
int SinglyLinkedList::countCurrency() {
	return count;
}

