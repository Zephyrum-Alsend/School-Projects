#pragma once
#include <iostream>
#include <string>
using namespace std;


class Problem2
{
public:
	Problem2(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~Problem2() {
		MakeEmpty();
	} 

	struct DLLNode {
		double value;
		DLLNode *next; 
		DLLNode *prev; 
	};
	
	//Empties out the table.
	void MakeEmpty(){
		DLLNode *cnode = head;
		DLLNode *nnode = NULL;

		for (; cnode != NULL; cnode = nnode) {
			nnode = cnode->next;
			delete cnode;
		}
		head = NULL;
		tail = NULL;
		size = 0;
	}

	//Tests to see if the table is empty.
	bool isEmpty(){
		return head == NULL;
	}

	//Finds a specified number in the table. Returns NULL if not found.
	DLLNode *Find(double x){
		DLLNode *cnode = tail;

		for (; cnode != NULL; cnode = cnode->prev) {

			if (cnode->value == x) {
				return cnode;
			}
		}

		return NULL;
	}

	//Deletes a number from the table.
	void DeleteNumberFromTable(double x){
		DLLNode *Position = Find(x);
		//If number not found.
		if (Position == NULL){
			return;
		}

		//If deleting the head of the list.
		if (Position == head) {
			Position->next->prev = NULL;
			head = Position->next;
		}
		//If deleting the tail of the list.
		else if (Position == tail) {
			Position->prev->next = NULL;
			tail = Position->prev;
		}
		//If deleting an element somewhere in the list.
		else {
			Position->prev->next = Position->next;
			Position->next->prev = Position->prev;
		}
		delete Position;
		size--;
	}
	
	//Adds a number to the tail of the table.
	void AddNumberToTable(double x){
		if (size >= 2000){
			cout << "\nMax size reached.\n";
			return;
		}
		
		DLLNode *tmp = new DLLNode;
		tmp->value = x;
		tmp->next = NULL;

		//If more than one element in table.
		if (tail != head){
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
		//If there is one element in table.
		else if (!isEmpty()){
			tail = tmp;
			tmp->prev = head;
			head->next = tmp;
		}
		//If table is empty.
		else{
			head = tmp;
			tmp->prev = NULL;
			tail = tmp;
		}
		size++;
		return;
	}

	//Returns true if a specified number is found and bumps it up the list. False if not found.
	bool isNumberInTable(double x){
		DLLNode *Position = Find(x);
		if (Position == NULL){
			return false;
		}
		MoveUp(Position);
		return true;
	}

	//Bumps a number up the table.
	void MoveUp(DLLNode *Position){
		//Number is already at the "top" of the table.
		if (Position == tail){
			return;
		}
		//Number is at the "bottom" of the table.
		if (Position == head){
			head = Position->next;
			head->prev = NULL;
			Position->next = head->next;
			Position->prev = head;
			head->next = Position;
			if (head == tail){		//If there are 2 elements in the table.
				tail = Position;
			}
			else{
				Position->next->prev = Position;
			}
		}
		//Number is somewhere else in the table.
		else{
			Position->prev->next = Position->next;
			Position->next->prev = Position->prev;
			Position->prev = Position->next;
			Position->next = Position->next->next;
			Position->prev->next = Position;
			if (Position->prev == tail){	//If the element after Position (originally) is the tail.
				tail = Position;
			}
			else{
				Position->next->prev = Position;
			}
		}
	}

private:
	DLLNode *head;
	DLLNode *tail;
	int size;
};

