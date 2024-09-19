#pragma once

#include <string>

class Currency {
private:
	int whole;
	int fraction;
public:
	Currency();
	Currency(double amount);
	~Currency();

	void setWhole(int w);
	void setFrac(int f);

	int getWhole() const;
	int getFrac() const;

	void add(double amount);
	void subtract(double amount);

	virtual bool isEqual(Currency&) = 0;

	virtual bool isGreater(Currency&) = 0;
	virtual std::string toString() = 0;
	
	int calcWhole(double amount);
	int calcFrac(double amount);

};
