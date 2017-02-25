// Implementation of Lists of doubles using a linked list structure.
#pragma once

class LinkedList {

public:

	LinkedList() {

		head = NULL;
	}
	~LinkedList() {

		MakeEmpty();
	}
	// The structure for a node of the linked list.  We will need to specify LinkedList::Node
	// if we reference "Node" outside of the class.  I left in code that will generate error
	// messages as a reminder.
	struct Node {
		double value; // The value element of the node
		Node *next; // Pointer to the next node.
	};
	// Empties out the linked list structure.
	void MakeEmpty();

	// Tests to see if the linked list structure is empty.
	bool isEmpty();

	// Finds a specifies element of the linked list. Returns NULL if not found.
	Node *Find(double y, Node *&PreNode);

	// Inserts an element at a specified position in the linked list.
	void Insert(double y, Node *PrePosition);

	// Deletes a specified element in the linked list.  YOU IMPLEMENT THIS ONE  I DID
	void Delete(Node *PrePosition);

	// Returns the kth element in the linked list. Returns -1 if not found.  YOU IMPLEMENT THIS ONE  I DID
	double FindKth(int position);

	// Replaces all specified instances of an element in the linked list. Returns number of instances replaced.
	int Replace(double y, double x);

	// Displays the list.
	void PrintList();

private:

	Node *head;     // Head of the linked list. 
};
