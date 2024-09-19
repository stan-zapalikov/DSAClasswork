// Stanislav Zapalikov 06-17-24
// Lab 5
#include <iostream>
#include "HashTable.h"

int main() {
	HashTable table;

	double amounts[] = { 57.12,23.44,87.43,68.99,111.22,44.55,77.77,18.36,543.21,20.21,345.67,36.18,48.48,101.00,11.00,21.00,51.00,1.00,251.00,151.00 };

	// Populates the money array
	for (int i = 0; i < 20; i++) {
		table.insert(amounts[i]);
	}


	table.printTable();
	
	std::cout << "Collisions: " << table.getCollisions() << std::endl;
	std::cout << "Load factor: " << table.getLoadFactor() << std::endl;

	std::string input;

	while (input != "q") {
		std::cout << "Enter an amount to search for (q to quit): ";
		std::getline(std::cin, input);
		if (input == "q") {
			break;
		}

		try {
			double dollarAmount = stod(input);
			int foundAt = table.search(dollarAmount);
			if (foundAt != -1) {
				std::cout << "$" << dollarAmount << " was found at index " << foundAt;
			}
			else {
				std::cout << "$" << dollarAmount << " was not found";
			}
			std::cout << std::endl;
		}
		catch (...) {
			std::cout << "Invalid input..." << std::endl;
		}
	}

	std::cout << "\nPress enter to continue..." << std::endl;
	std::cin.get();
}