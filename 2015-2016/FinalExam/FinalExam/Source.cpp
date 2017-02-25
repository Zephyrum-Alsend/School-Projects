//Final [s]Examination[/s] Countdown
//Lucas Crockett
//Status:
//Problem 1: Duck.
//Problem 2: No Syntax Errors.
//Problem 3: Working.

#include <iostream>
#include <string>
using namespace std;
int hashf(string name);
void DeleteHashTable(string name);

struct hnode{
	string name;
	hnode *next;
};
hnode *ht[5003];

//Problem 1
//a) The C++ library sort function was created and refined by many programmers over many years
//	with far more experience than us. Their sort function has all the kinks ironed out that any
//	sort function we write will have to deal with. It's basically the fastest known algorithm for the job.
//
//b) 10x as many elements for O(N^3) means 10^3 as long, so 1000x as long as 5 seconds. 5000 seconds.
//
//c) SSD's are flash based memory, so they have a limited number of writes before they burn out, becoming inoperable.
//
//d) Vectors from STL keep track of things such as size for the user and dynamically reallocate memory.
//	They basically do the house keeping for us.
//
//e) Deleting an element from a linear hash table will take as long as it does to search for that same element.
//	If there are 0 collisions, then the delete is super fast.  If there are collisions, or if the element is not
//	actually in the hash table, then deleting boils down to an inefficient linear search for the element.
//	This also throws off the rest of the table, as to find other collided elements, the initial index must be
//	filled. But now it's empty. So the search will yield "not in table" even though it is.
//
//f) It is as important to know how a tool does it's job as it is to know that tools exists. If the tool ever breaks,
//	ever needs modifications, we need to know how it works in order to change it.
//
//g) A linked list, depending if singly or doubly linked, has access points only at the head and tail.
//	Finding the midpoint to begin a binary search would require a linear search through the list.
//	If the list is singly linked, then another linear search is required every time the binary search goes
//	towards the head. A single linear search would be far more efficient for linked list data types.
//
//h) #include<algorithm>
//
//	sort(&x[0], &x[2100]);

//Problem 3
int main(){
	struct Node {
		double value;
		Node *next;
	};
	Node *head = new Node;	//Insert linked list here.
	Node *nex1 = new Node;
	Node *nex2 = new Node;
	Node *nex3 = new Node;
	head->value = 5;
	nex1->value = 3;
	nex2->value = 8;
	nex3->value = 2;
	head->next = nex1;
	nex1->next = nex2;
	nex2->next = nex3;
	nex3->next = NULL;

	double arr[1000];	//array for storing each value as we go through the list. 
						//Arbitrarily large size so it can fit all values in the linked list.
						//If we knew what size the linked list was, arr's size would match it.
	int arrSize = -1;	//Tracks total size of the linked list and acts as an index for cout loop.
	Node *cnode = head; //Entry point to the linked list.
	//Copies all values in the linked list to the array while also counting the number of elements in the list.
	for (int i = 0; i < 1000; i++){
		arr[i] = cnode->value;
		cnode = cnode->next;
		arrSize++;
		if (cnode == NULL){
			break;
		}
	}
	//Outputs what was stored in the linked list in reverse order.
	for (; arrSize > -1; arrSize--){
		cout << arr[arrSize] << endl;
	}
}

//Problem 2
void DeleteHashTable(string name){
	int ind = hashf(name); //error LNK2019 and LNK1120 are due to hashf(name) function being undefined.
	hnode *cnode = ht[ind];
	//Checks if the name is at the head of the list and handles this case.
	if (cnode->name == name){
		ht[ind] = cnode->next;
		delete cnode;
		return;
	}
	//Name not at the head so we need to keep track of the previous node.
	hnode *pnode = cnode;
	//Keeps going until the end of the linked list or the name is found.
	while (cnode != NULL){
		if (cnode->name == name){
			pnode->next = cnode->next;
			delete cnode;
			return;
		}
		pnode = cnode;
		cnode = cnode->next;
	}
	return;
}