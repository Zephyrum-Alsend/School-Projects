// To test the implementation of the ADT list using linked lists
#include <iostream>
#include "DLList.h"
using namespace std;

int main()
{
//	DLinkedList aaa;
	DLinkedList bbb;

	// Insert a lot of stuff;
//	aaa.Insert(111, NULL);
//	aaa.Insert(222, NULL);
//	aaa.PrintList();
//	cout << endl;
//
//	aaa.Insert(333, NULL);
//	aaa.Insert(444, NULL);
//
//	DLinkedList::DLLNode *npt = aaa.Find(222);
//	aaa.Insert(555, npt);
//	aaa.appendList(789);
//	aaa.Delete(aaa.Find(789));
//	aaa.PrintList();
//
//	cout << endl;
//	aaa.reversePrintList();

	// Prompts user to enter numbers into a DLList and prints the DLL then prints DLL backwards.
	int x = 0;
	cout << "Enter a number. Enter -1 to stop." << endl;
	while (x != -1) {
		cin >> x;
		if (x != -1)
			bbb.appendList(x);
	}
	cout << endl;
	bbb.PrintList();
	cout << endl;
	bbb.reversePrintList();
	cout << endl;
}