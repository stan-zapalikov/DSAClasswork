// Stanislav Zapalikov
// This program adds and subtracts money
#pragma once
#include <string>
#include <cmath>

class Currency {
protected:
	int whole;
	int fraction;
public:
	Currency();
	Currency(double amount);
	Currency& operator=(const Currency& right);

	int getWhole() const;
	int getFrac() const;
	void setWhole(int w);
	void setFrac(int f);

	int calcWhole(double amount);
	int calcFrac(double amount);

	void add(const Currency& right);
	void subtract(const Currency& right);
	bool isEqual(const Currency& right) const;
	bool isGreater(const Currency& right) const;

	virtual std::string toString() const = 0;
	virtual std::string getName() const = 0;
	virtual void print() const = 0;

	class InvalidAmount {};
	class InvalidAddition {};
	class InvalidSubtraction {};
	class InvalidAssignment {};
};
