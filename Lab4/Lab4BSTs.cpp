// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#include <iostream>
#include "BST.h"
#include <string>
#include "dollar.h"
#include <fstream>

Dollar* newDollarPtr() {

	// This function expects the user to enter a dollar amount
	// to convert to a Dollar object pointer
	// Pre: user input
	// Post: validate input and convert it to dollar object
	// Return: pointer to dollar object

	Dollar* newDollar;
	try {
		std::cout << "Enter a dollar amount: ";
		std::string tempNumber;
		std::getline(std::cin, tempNumber);

		double dollarAmount = stod(tempNumber);
		newDollar = new Dollar(dollarAmount);
		return newDollar;
	}
	catch (...) {
		newDollar = new Dollar(0);
		newDollar->setIsDigit(false);
		return newDollar;
	}
}

int main() {
	BST tree;
	std::ofstream outFile;
	outFile.open("output.txt");


	double amounts[] = { 57.12,23.44,87.43,68.99,111.22,44.55,77.77,18.36,543.21,20.21,345.67,36.18,48.48,101.00,11.00,21.00,51.00,1.00,251.00,151.00 };
	Dollar* money[20];

	// Populates the money array
	for (int i = 0; i < 20; i++) {
		money[i] = new Dollar(amounts[i]);
		tree.insert(money[i]);
	}

	tree.print(outFile);

	std::string command;

	while (command != "quit") {
		std::cout << std::endl;
		std::cout << "add/search/delete/print/quit: ";
		std::getline(std::cin, command);
		
		if (command == "add") {

			// validate input and add the item to the tree
			Dollar* tempDollar = newDollarPtr();
			if (tempDollar->getIsDigit()) {
				tree.insert(tempDollar);

				std::cout << tempDollar->toString() << " added!" << std::endl;
				outFile << tempDollar->toString() << " added!" << std::endl;
			}
			else {
				std::cout << tempDollar->toString() << " not added..." << std::endl;
				outFile << tempDollar->toString() << " not added..." << std::endl;

			}
		}
		else if (command == "search") {

			// validate input and search for the item in the tree
			if (Dollar* tempDollar = newDollarPtr()) {
				if (tree.search(tempDollar)) {
					std::cout << "Item found!" << std::endl;
					outFile << "Item " << tempDollar->toString() << " found!" << std::endl;
				}
				else {
					std::cout << tempDollar->toString() << " not found..." << std::endl;
					outFile << tempDollar->toString() << " not found..." << std::endl;
				}
			}
		}
		else if (command == "delete") {

			// validate input and remove item from the tree
			Dollar* tempDollar = newDollarPtr();

			if (tempDollar && tree.search(tempDollar)) {
				tree.remove(tempDollar);

				std::cout << tempDollar->toString() << " has been removed!" << std::endl;
				outFile << tempDollar->toString() << " has been removed!" << std::endl;
			}
			else {
				std::cout << tempDollar->toString() << " not found..." << std::endl;
				outFile << tempDollar->toString() << " not found..." << std::endl;
			}
		}
		else if (command == "print") {

			// prints item to console and file
			tree.print(outFile);
		}
		else if (command == "quit") {

			// exit and print
			tree.print(outFile);
		}
		else {

			// input validation
			std::cout << "Invalid command..." << std::endl;
		}
	}

	outFile.close();

	std::cout << "\nPress enter to continue..." << std::endl;
	std::cin.get();

}