// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#pragma once
#include "Currency.h"
#include <string>
#include <iostream>

class Dollar : public Currency {
private:
	std::string name;
	bool isDigit;
public:
	Dollar() : Currency(), name("Dollar"), isDigit(true) {}
	Dollar(double amount) : Currency(amount), name("Dollar"), isDigit(true) {}

	void setIsDigit(bool alpha);
	bool getIsDigit();
	std::string getName() const override;
	std::string toString() const override;
	void print() const override;
};
