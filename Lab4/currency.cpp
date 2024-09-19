// Stanislav Zapalikov
// This program adds and subtracts money
#include "Currency.h"
#include <cmath>
#include <iostream>

Currency::Currency() {
	whole = 0;
	fraction = 0;
}

Currency::Currency(double amount) {
	if (amount < 0) {
		
		throw InvalidAmount();
	}
	else {
		whole = this->calcWhole(amount);
		fraction = this->calcFrac(amount);
	}
}

// Overloads the = operator
Currency& Currency::operator=(const Currency& right) {
	if (this->getName() != right.getName()) {
		throw InvalidAssignment();
	}
	whole = right.getWhole();
	fraction = right.getFrac();
	return *this;
}

// GET
int Currency::getWhole() const {
	return whole;
}

int Currency::getFrac() const {
	return fraction;
}

void Currency::setWhole(int w) {
	whole = w;
}

// SET
void Currency::setFrac(int f) {
	fraction = f;
}

// Calculates whole and fracton for the constructor
int Currency::calcWhole(double amount) {
	return static_cast<int>(amount);
}

int Currency::calcFrac(double amount) {
	return round((amount - this->calcWhole(amount)) * 100);
}

// Adds the values from an inputted Currency class 
// Input: Currency object
void Currency::add(const Currency& right) {
	if (right.getWhole() < 0 || right.getFrac() < 0
		|| this->getName() != right.getName()) 
	{
		throw InvalidAddition();
	}
	int tempWhole = (this->getWhole() + right.getWhole());
	int tempFrac = (this->getFrac() + right.getFrac());
	tempWhole += (tempFrac / 100);
	tempFrac %= 100;
	whole = tempWhole;
	fraction = tempFrac;
}

// Subtracts inputted object's values from this object
// Input: Currency object
void Currency::subtract(const Currency& right) {
	if (right.isGreater(*this) 
		|| this->getName() != right.getName()) {
		throw InvalidSubtraction();
	}
	else {
		int tempWhole = (this->getWhole() - right.getWhole());
		int tempFrac = (this->getFrac() - right.getFrac());
		if (tempFrac < 0) {
			tempWhole--;
			tempFrac += 100;
		}
		whole = tempWhole;
		fraction = tempFrac;
	}
}

// Returns true if this object is equal to the inputted one
// Input: Currecy object
// Output: Boolean
bool Currency::isEqual(const Currency& right) const {
	if (this->getWhole() == right.getWhole() && this->getFrac() == right.getFrac()) {
		return true;
	}
	else {
		return false;
	}
}

// Returns true if this object is greater than the inputted one
// Input: Currency object
// Output: Boolean
bool Currency::isGreater(const Currency& right) const {
	if (this->getWhole() > right.getWhole()) {
		return true;
	}
	if (this->getWhole() == right.getWhole() && this->getFrac() > right.getFrac()) {
		return true;
	}
	if (this->getWhole() < right.getWhole()) {
		return false;
	}
	if (this->getWhole() == right.getWhole() && this->getFrac() < right.getFrac()) {
		return false;
	}
	if (this->isEqual(right)) {
		return false;
	}
}