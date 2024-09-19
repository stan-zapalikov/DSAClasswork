// Stanislav Zapalikov 06-17-24
// Lab 5
#include "HashTable.h"
#include "dollar.h"
#include <iostream>

HashTable::HashTable() {
    collisions = 0;
    items = 0;
    loadFactor = 0.0;
    for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

int HashTable::hash(Dollar* obj) {
    // Creates a hash for the given dollar amount
    // Pre: obj - dollar pointer to be hashed
    // Post: NA
    // Return: int - the hash for the dollar amount 
	return (2 * obj->getWhole() + 3 * obj->getFrac()) % size;
}

void HashTable::insert(double amount) {
    // Inserts a dollar into the table
    // Pre: double - dollar amount to be inserted
    // Post: the dollar amount is converted to a dollar object and inserted
    // Return: NA
    Dollar* obj = new Dollar(amount);
    int i = 0;
    int bucketsProbed = 0;
    int bucket = hash(obj);
    while (bucketsProbed < size) {
        // insert item in next empty bucket
        if (!table[bucket] || table[bucket] == obj) {
            table[bucket] = obj;
            items += 1;
            loadFactor = (double)items / size;
            return;
        }

        // increment i and recompute bucket index using quadratic probing
        i += 1;
        collisions += 1;
        bucket = (hash(obj) + i * i) % size;
        bucketsProbed += 1;
    }
}

int HashTable::search(double amount) {
    // Searches for the given amount in the table
    // Pre: double - dollar amount to be searched for
    // Post: the dollar amount is converted to a dollar object and hashed for search
    // Return: int - -1 if not found, >=0 if found
    Dollar* obj = new Dollar(amount);
    int i = 0;
    int bucketsProbed = 0;
    int bucket = hash(obj);
    while (bucketsProbed < size) {
        if (table[bucket] && 
            table[bucket]->getWhole() == obj->getWhole() &&
            table[bucket]->getFrac() == obj->getFrac()) 
        {
            return bucket;
        }

        // increment i and recompute bucket index using quadratic probing
        i += 1;
        collisions += 1;
        bucket = (hash(obj) + i * i) % size;
        bucketsProbed += 1;
    }
    return -1;
}

void HashTable::printTable() {
    // Prints the table with keys and values
    // Pre: NA
    // Post: NA
    // Return: NA
	for (int i = 0; i < size; i++) {
		if (table[i] != nullptr) {
			std::cout << i << ": " << table[i]->toString() << std::endl;
		}
		else {
			std::cout << i << ": " << "null" << std::endl;
		}
	}
	std::cout << std::endl;
}

int HashTable::getCollisions() {
    return collisions;
}

double HashTable::getLoadFactor() {
    return loadFactor;
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}
