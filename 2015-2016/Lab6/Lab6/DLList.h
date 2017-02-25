#pragma once
// Implementation of Lists of doubles using a linked list structure.

class DLinkedList {

public:

	DLinkedList() {

		head = NULL;
		tail = NULL;
	}
	~DLinkedList() {

		MakeEmpty();
	}
	// Structure of a node in the linked list.  
	struct DLLNode {
		double value;
		DLLNode *nextnode; // Pointer to next node.
		DLLNode *prenode; // Pointer to the previous node.
	};
	// Empties out the linked list structure.
	void MakeEmpty();

	// Tests to see if the linked list structure is empty.
	bool isEmpty();

	// Finds a specifies element of the linked list. Returns NULL if not found.
	DLLNode *Find(double y);

	// Inserts an element at a specified position in the linked list.
	void Insert(double y, DLLNode *PrePosition);

	// Deletes a specified element in the linked list.
	void Delete(DLLNode *Position);

	// Returns the kth element in the linked list. Returns -1 if not found.
	double FindKth(int position);

	// Displays the list.
	void PrintList();

	// Display the list in reverse order.
	void reversePrintList();

	// Append to list.
	void appendList(double x);


private:

	DLLNode *head;      // The head of the linked list.
	DLLNode *tail;      // The tail of the linked list.
};
