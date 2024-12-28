#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

// Node class for the doubly linked list
template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(T d) : data(d), next(nullptr), prev(nullptr) {}
};

// Template class Queue
template<typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	// Default constructor
	Queue();
	// Destructor
	~Queue();
	// Add element to the end of the queue
	void enqueue(T data);
	// Remove element from the front of the queue
	void dequeue();
	// Get the element from the front of the queue
	T front() const;
	// Check if the queue is empty
	bool isEmpty() const;
	// Get the size of the queue
	int getSize() const;
	// Display elements of the queue
	void display() const;
	// Method to swap head and tail
	void swapHeadTail();
};

// Default constructor
template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
template<typename T>
Queue<T>::~Queue() {
	while (head != nullptr) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

// Add element to the end of the queue
template<typename T>
void Queue<T>::enqueue(T data) {
	Node<T>* newNode = new Node<T>(data);
	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++size;
}

// Remove element from the front of the queue
template<typename T>
void Queue<T>::dequeue() {
	if (head == nullptr) return; // Queue is empty
	Node<T>* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	delete temp;
	--size;
}

// Get the element from the front of the queue
template<typename T>
T Queue<T>::front() const {
	if (head == nullptr) throw out_of_range("Queue is empty");
	return head->data;
}

// Check if the queue is empty
template<typename T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}

// Get the size of the queue
template<typename T>
int Queue<T>::getSize() const {
	return size;
}

// Display elements of the queue
template<typename T>
void Queue<T>::display() const {
	Node<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Method to swap head and tail
template<typename T>
void Queue<T>::swapHeadTail() {
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
	// Reconnecting nodes for the doubly linked list
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	// Swapping head and tail
	Node<T>* temp = head;
	head = tail;
	tail = temp;
}
