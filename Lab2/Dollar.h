#pragma once
#include <string>
#include "Currency.h"

class Dollar : Currency {
private:
	std::string name;
public:
	Dollar() : Currency(), name("Dollar") {}
	Dollar(double amount) : Currency(amount), name("Dollar") {}

	virtual bool isEqual(Currency&);

	virtual bool isGreater(Currency&);
	virtual std::string toString();
	std::string getName();
};
