// Stanislav Zapalikov
// Lab 4
// This program implements a BST with various traversal methods
// and allows for user input
#pragma once
#include <iostream>
#include <string>

// LinkNode class for the queue (copied from lab 3)
template <typename T>
class LinkNode {
public:
    T* data;
    LinkNode* next;

    LinkNode(T* data) : data(data), next(nullptr) {}
};

// Queue class 
template <typename T>
class Queue {
private:
    LinkNode<T>* front;
    LinkNode<T>* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Add an element to the end of the queue
    void enqueue(T* addedData) {

        // Adds item to the end of the queue
        // Pre: addedData - template pointer with data to add to the queue
        // Post: item added to end of the queue
        // Return: NA

        LinkNode<T>* newNode = new LinkNode<T>(addedData);
        if (rear) {
            rear->next = newNode;
        }
        else {
            front = newNode;
        }
        rear = newNode;
        size++;
    }

    T* dequeue() {

        // Removes an item from the start of the queue
        // Pre: NA
        // Post: first queue item removed
        // Return: the item removed

        if (isListEmpty()) {
            return nullptr;
        }
        LinkNode<T>* nodeToRemove = front;
        T* data = nodeToRemove->data;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete nodeToRemove;
        size--;
        return data;
    }

    T* peekFront() {
        
        // Return the element at the front of the queue without removing it
        // Pre: NA
        // Post: NA
        // Return: T pointer

        if (isListEmpty()) {
            return nullptr;
        }
        return front->data;
    }

    T* peekRear() {

        // Return the element at the rear of the queue without removing it
        // Pre: NA
        // Post: NA
        // Return: T pointer

        if (isListEmpty()) {
            return nullptr;
        }
        return rear->data;
    }

    bool isListEmpty() const {

        // Check if list is empty
        // Pre: NA
        // Post: NA
        // Return: bool

        return size == 0;
    }

    std::string printQueue() const {
        
        // Return the list as a string
        // Pre: NA
        // Post: NA
        // Return: string

        std::string result;
        LinkNode<T>* current = front;
        while (current) {
            result += current->data->toString() + " "; // Assuming T has a toString() method
            current = current->next;
        }
        return result;
    }

    // Destructor
    ~Queue() {
        while (!isListEmpty()) {
            dequeue();
        }
    }
};
