// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#include <string>
#include <iostream>
#include "Currency.h"
#include "Dollar.h"

void Dollar::setIsDigit(bool alpha) {
	isDigit = alpha;
}

bool Dollar::getIsDigit() {
	return isDigit;
}

std::string Dollar::getName() const {
	return name;
}

// Converts whole and fraction and returns a string
std::string Dollar::toString() const {
	if (isDigit) {
		std::string wholeString = std::to_string(this->getWhole());
		std::string fractionString = std::to_string(this->getFrac());
		return "$" + wholeString + "." + fractionString;
	}
	else {
		return "NaN";
	}
}

// Calls toString and prints the output
void Dollar::print() const {
	std::cout << this->toString() << std::endl;
}