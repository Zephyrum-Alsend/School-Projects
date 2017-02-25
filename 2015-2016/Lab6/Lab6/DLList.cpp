// Functions to support list operations on an array.
#include <iostream>
#include <string>
#include "DLList.h"
using namespace std;


// Tests to see if the linked list structure is empty.
bool DLinkedList::isEmpty()
{
	return head == NULL;
}

// Empties out the linked list structure.
void DLinkedList::MakeEmpty()
{
	DLLNode *cnode = head; // Points to the node we are processing.
	DLLNode *nnode = NULL; // Points to next node

						   // Scan through the list freeing all the nodes.
	for (; cnode != NULL; cnode = nnode) {
		nnode = cnode->nextnode;
		delete cnode;
	}
	head = NULL;
	tail = NULL;
}

// Finds a specifies element of the linked list. Returns NULL if not found.
DLinkedList::DLLNode *DLinkedList::Find(double y)
{
	DLLNode *cnode = head;

	// Search each element of the linked list for y.
	for (; cnode != NULL; cnode = cnode->nextnode) {

		if (cnode->value == y) {
			return cnode;
		}
	}
	// Node not found.
	return NULL;
}

// Inserts an element at a specified position in the linked list.
void DLinkedList::Insert(double y, DLLNode *PrePosition)
{
	DLLNode *tmp = new DLLNode; // The new node to be added.

								// Record y in the new node.
	tmp->value = y;
	tmp->nextnode = NULL;
	tmp->prenode = NULL;

	// Update the tail if we are adding to the tail.
	if (tail == PrePosition) {

		tail = tmp;
	}
	// If this new node is at the head, treat this as a special case.
	if (PrePosition == NULL) {
		tmp->nextnode = head;

		if (head != NULL) {

			head->prenode = tmp;
		}
		head = tmp;
		return;
	}
	// We are adding the new node after the head.
	DLLNode *nextPrePos = PrePosition->nextnode;
	tmp->nextnode = nextPrePos;
	tmp->prenode = PrePosition;

	PrePosition->nextnode = tmp;
	if (nextPrePos != NULL) {

		nextPrePos->prenode = tmp;
	}
}
// Deletes a specified element in the list.
void DLinkedList::Delete(DLLNode *Position) {
	// We are deleting the head of the list.
	if (Position == head) {
		Position->nextnode->prenode = NULL;
		head = Position->nextnode;
	}
	// We are deleting the tail of the list.
	else if (Position == tail) {
		Position->prenode->nextnode = NULL;
		tail = Position->prenode;
	}
	// We are deleting an element somewhere in the list.
	else {
		Position->prenode->nextnode = Position->nextnode;
		Position->nextnode->prenode = Position->prenode;
	}
	delete Position;
}
//
double DLinkedList::FindKth(int position) {
	// Saves time if we are asked to find a nonexistent index.
	if (position < 1)
		return -1;

	DLLNode *cnode = head;
	for (int i = 1; cnode != NULL && i != position; cnode = cnode->nextnode) {
		i++;
	}
	// Returns -1 if the for loop was terminated by cnode == NULL (reached end of list).
	if (cnode == NULL)
		return -1;
	return cnode->value;
}
// Displays the list.
void DLinkedList::PrintList()
{
	int ill = 1; // Position in linked list.

				 // Display the list.
	for (DLLNode *cnode = head; cnode != NULL; cnode = cnode->nextnode) {
		cout << ill++ << ". " << cnode->value << endl;
	}
}
// Displays the list in reverse.
void DLinkedList::reversePrintList() {
	int ill = 0; // Position in linked list.
	for (DLLNode *cnode = head; cnode != NULL; cnode = cnode->nextnode)
		ill++;
				 // Display the list in reverse.
	for (DLLNode *cnode = tail; cnode != NULL; cnode = cnode->prenode) {
		cout << ill-- << ". " << cnode->value << endl;
	}
}
// Inserts an element at the end of the list.
void DLinkedList::appendList(double x) {
	Insert(x, tail);
}