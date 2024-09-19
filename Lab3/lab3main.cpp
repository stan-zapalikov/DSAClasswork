// Stanislav Zapalikov
// Lab 3
// This program demonstrates the implementation of a linked list, a stack, and a queue
#include <iostream>
#include <string>
#include "Stack.h"
#include "SinglyLinkedList.h"
#include "LinkNode.h"
#include "dollar.h"
#include "pound.h"
#include "Queue.h"

int main() {

	std::cout << "Hello! This is Lab 3 and it shows the implementation of a linked list, a stack, and a queue." << std::endl;
	std::cout << "-Stanislav Zapalikov" << std::endl;
	std::cout << std::endl;

	Dollar* dollars[20];
	double prices[] = { 57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77,
						18.36, 543.21, 20.21, 345.67, 36.18, 48.48, 101.00,
						11.00, 21.00, 51.00, 1.0, 251.00, 151.00 };
	for (int i = 0; i < 20; i++) {
		dollars[i] = new Dollar(prices[i]);
	}

	SinglyLinkedList list;
	Stack stack;
	Queue queue;

	for (int i = 6; i >= 0; i--) {
		list.addCurrency(dollars[i], 0);
	}


	Dollar* placeholder = new Dollar(87.43);
	std::cout << "Looking for 87.53 : " << list.findCurrency(placeholder) << std::endl;
	delete placeholder;
	placeholder = new Dollar(44.56);

	std::cout << "Looking for 44.56 : " << list.findCurrency(placeholder) << std::endl;

	delete placeholder;
	placeholder = new Dollar(111.22);
	std::cout << "Removing 111.22" << std::endl;
	list.removeCurrency(placeholder);


	std::cout << "Removing item number 3" << std::endl;
	list.removeCurrency(2);


	for (int i = 9; i <= 12; i++) {
		list.addCurrency(dollars[i], (i%5));
	}

	list.removeCurrency(list.countCurrency() % 6);
	list.removeCurrency(list.countCurrency() / 7);

	std::cout << list.printList() << std::endl;

	std::cout << std::endl << "Stack" << std::endl;

	for (int i = 0; i < 7; i++) {
		stack.push(dollars[i+13]);
	}

	std::cout << "Peek: ";
	std::cout << stack.peek()->toString() << std::endl;

	stack.pop();
	stack.pop();
	stack.pop();

	std::cout << "Stack after 3 pops: " << std::endl;
	std::cout << stack.printStack() << std::endl;

	for (int i = 0; i < 7; i++) {
		stack.push(dollars[i]);
	}

	stack.pop();
	stack.pop();

	std::cout << "Final stack: " << std::endl;
	std::cout << stack.printStack() << std::endl;

	std::cout << std::endl << "Queue" << std::endl;

	for (int i = 5; i < 7; i++) {
		queue.enqueue(dollars[(i*2) + 5]);
	}

	std::cout << "Peek front: " << queue.peekFront()->toString() << std::endl;
	std::cout << "Peek rear: " << queue.peekRear()->toString() << std::endl;

	queue.dequeue();
	queue.dequeue();

	std::cout << "Queue after 2 dequeues: " << std::endl;
	std::cout << queue.printQueue() << std::endl;

	for (int i = 0; i < 5; i++) {
		queue.enqueue(dollars[i + 10]);
	}

	queue.dequeue();
	queue.dequeue();
	queue.dequeue();

	std::cout << "Final queue: " << std::endl;
	std::cout << queue.printQueue() << std::endl;

	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();


}