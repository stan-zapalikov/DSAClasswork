// Stanislav Zapalikov 06-17-24
// Lab 5
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
