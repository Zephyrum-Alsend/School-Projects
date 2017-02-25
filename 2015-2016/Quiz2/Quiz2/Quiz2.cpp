//Quiz 2
//Lucas Crockett

#include <iostream>
#include <string>
using namespace std;

int main(){

}

//Question 2
struct NODE2{
	string name;
	NODE2 *next;
};
int CircularList::Size(){
	//Returns 0 if handed an empty list.
	if (head == NULL){
		return 0;
	}
	NODE2 *node = head;
	int count = 1;	//We have the head already.
	while (node->next != head){
		*node = *node->next;
		count++;
	}
	return count;
}





//Question 3
struct NODE3{
	int value;
	NODE3 *next;
};

//Copy of Size() for use in DeleteTwo w/ minor edits.
int LinkedList::Size(){
	//Returns 0 if handed an empty list.
	if (head == NULL){
		return 0;
	}
	NODE3 *node = head;
	int count = 1;	//We have the head already.
	while (node->next != NULL){
		*node = *node->next;
		count++;
	}
	return count;
}
//Deletes last two nodes in a linked list. If list size <= 2, deletes entire list.
void LinkedList::DeleteTwo(){
	int ListSize = Size();
	if (ListSize > 2){
		NODE3 *pnode = head->next;		//Tracks the next to last node.
		NODE3 *lnode = pnode->next;		//Tracks last node in the list.
		NODE3 *enode = head;			//Tracks new end node.
		while (lnode->next != NULL){
			enode = pnode;
			pnode = lnode;
			lnode = lnode->next;
		}
		//Deletes last two nodes and sets new end.
		delete lnode;
		delete pnode;
		enode->next = NULL;
	}
	//If list size is 2.
	else if (ListSize == 2) {
		NODE3 *nnode = head->next;
		delete nnode;
		delete head;
		head = NULL;
	}
	//If list size is 1.
	else if (ListSize > 0){
		delete head;
		head = NULL;
	}
	//Does nothing if passed an empty list.
	
	return;
}