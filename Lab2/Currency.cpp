#include "Currency.h"

Currency::Currency() {
	whole = 0;
	fraction = 0;
}

Currency::Currency(double amount) {
	whole = calcWhole(amount);
	fraction = calcFrac(amount);
}

Currency::~Currency() {
	//
}

void Currency::setWhole(int w) {
	whole = w;
}

void Currency::setFrac(int f) {
	fraction = f;
}

int Currency::getWhole() const {
	return whole;
}

int Currency::getFrac() const {
	return fraction;
}

void Currency::add(Currency& right) {
	//TODO check for negative numbers and bad input
	whole += right.getWhole();
	fraction += right.getFrac();
}

void Currency::subtract(Currency& right) {
	// TODO check for negative
	whole -= right.getWhole();
	fraction -= right.getFrac();
}

int Currency::calcWhole(double amount) {
	if (amount < 0)
		return 0;
	return static_cast<int>(amount);
}

int Currency::calcFrac(double amount) {
	if (amount < 0)
		return 0;
	return amount - calcWhole(amount);
}
