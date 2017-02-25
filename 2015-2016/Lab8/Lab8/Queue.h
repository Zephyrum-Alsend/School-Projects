#pragma once
#include <iostream>

class Queue
{
public:
	Queue(){
		head = NULL;
		tail = NULL;	
	}
	~Queue(){
		MakeEmpty();
	}

	struct Node{
		double value;
		Node *next;
	};
	
	//Deletes all elements, setting head and tail to NULL.
	void MakeEmpty();

	//Checks if queue is empty and returns true or false.
	bool isEmpty();
	
	//Appends a specified value to the tail of the queue.
	void enqueue(double x);
	
	//Returns and deletes the head of the queue. Returns -1 if queue is empty.
	double dequeue();
	
	//Prints the entire queue via dequeue. !!Empties entire queue!!
	void PrintQueue();
	
	//Deletes the head of the queue and sets next element to head.
	void DeleteHead();

private:
	Node *head;		//First element in the queue.
	Node *tail;		//Last element in the queue.
};

