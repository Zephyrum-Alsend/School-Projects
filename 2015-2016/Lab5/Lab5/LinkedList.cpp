// Functions to support list operations on an array.
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;


// Tests to see if the linked list structure is empty.
bool LinkedList::isEmpty()
{
	return head == NULL;
}

// Empties out the linked list structure.  This is certainlymore difficult than the
// ArrayList implementation. 
void LinkedList::MakeEmpty()
{
	Node *cnode = head; // Points to the node we are processing.
	Node *nnode = NULL; // Points to next node
						// Scan through the list freeing all the nodes.
	for (; cnode != NULL; cnode = nnode) {
		nnode = cnode->next;
		delete cnode;
	}
	head = NULL;
}

// Finds a specifies element of the linked list. Returns NULL if not found.
LinkedList::Node *LinkedList::Find(double y, Node *&PreNode)
{
	Node *cnode = head;
	Node *pnode = NULL;
	// Search each element of the linked list for y.
	for (; cnode != NULL; pnode = cnode, cnode = cnode->next) {
		if (cnode->value == y) {
			PreNode = pnode;
			return cnode;
		}
	}
	// Node not found.
	return NULL;
}

// Inserts an element at a specified position in the linked list.
void LinkedList::Insert(double y, Node *PrePosition)
{
	Node *tmp = new Node; // The new node to be added.

						  // Record y in the new node.
	tmp->value = y;

	// If this new node is at the head, treat this as a special case.
	if (PrePosition == NULL) {
		tmp->next = head;
		head = tmp;
		return;
	}
	// We are adding the new node after the head.
	tmp->next = PrePosition->next;
	PrePosition->next = tmp;
	return;
}


// Deletes the specified node.
void LinkedList::Delete(Node *PrePosition) {
	// Checks to see if deleting head first. Short circuits if so.
	if (PrePosition == NULL) {
		Node *tmp = head->next;
		delete head;
		head = tmp;
		return;
	}
	//Does nothing if PrePosition is end of list.
	if (PrePosition->next != NULL) {
		Node *tmp2 = PrePosition->next;
		PrePosition->next = tmp2->next;
		delete tmp2;
	}
	return;
}
// Finds the Kth node and returns its value. Returns -1 if position is invalid.
double LinkedList::FindKth(int position) {
	Node *cnode = head;
	for (int i = 0; cnode->next != NULL; i++, cnode = cnode->next) {
		if (i == position) {
			return cnode->value;
		}
	}
	return (-1);
}
// Replaces all instances of a specified value with another specified value. 
// Returns number of instances replaced.
int LinkedList::Replace(double y, double x) {
	Node *cnode = head;
	int RepCount = 0;
	for (; cnode->next != NULL; cnode = cnode->next) {
		if (cnode->value == y) {
			cnode->value = x;
			RepCount++;
		}
	}
	return RepCount;
}


// Displays the list.
void LinkedList::PrintList()
{
	int ill = 0; // Position in linked list.

				 // Display the list.
	for (Node *cnode = head; cnode != NULL; cnode = cnode->next) {
		cout << ill++ << ". " << cnode->value << endl;
	}
}