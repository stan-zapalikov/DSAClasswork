// Stanislav Zapalikov 06-17-24
// Lab 5
#pragma once
#include "dollar.h"
#include <iostream>

class HashTable {
private:
	int size = 29;
	int collisions;
	int items;
	double loadFactor;
	Dollar* table[29];
	int hash(Dollar* obj);
public:
	HashTable();
	void insert(double amount);
	void printTable();
	int getCollisions();
	int search(double amount);
	double getLoadFactor();
	~HashTable();
};
