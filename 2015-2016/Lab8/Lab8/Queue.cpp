#include <iostream>
#include "Queue.h"
#include <string>
using namespace std;

//Deletes all elements, setting head and tail to NULL.
void Queue::MakeEmpty(){
	for (; tail != NULL;){
		DeleteHead();
	}
}

//Checks if queue is empty and returns true or false.
bool Queue::isEmpty(){
	return head == NULL;
}

//Appends a specified value to the tail of the queue.
void Queue::enqueue(double x){
	Node *tmp = new Node;

	tmp->value = x;
	tmp->next = NULL;
	if (isEmpty()){
		head = tmp;
		tail = tmp;
	}
	else{
		tail->next = tmp;
		tail = tmp;
	}
	return;
}

//Returns and deletes the head of the queue. Returns -1 if queue is empty.
double Queue::dequeue(){
	if (isEmpty()){
		return -1;
	}
	double tmp = head->value;
	DeleteHead();
	return tmp;
}

//Prints the entire queue via dequeue. !!Empties entire queue!!
void Queue::PrintQueue(){
	cout << endl << "The Queue is:\n";
	if (isEmpty()){
		cout << dequeue() << endl;
	}
	else{
		for (; tail != NULL;){
			cout << dequeue() << endl;
		}
	}
	cout << endl;
}

//Deletes the head of the queue and sets next element to head.
void Queue::DeleteHead(){
	Node *newHead = head->next;
	delete head;
	head = newHead;
	if (isEmpty()){
		tail = NULL;
	}
	return;
}