// To test the implementation of the ADT list using linked lists
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList aaa;

	// Insert a lot of stuff;
	aaa.Insert(111, NULL);
	aaa.Insert(222, NULL);
	aaa.PrintList();
	cout << endl;

	aaa.Insert(333, NULL);
	aaa.Insert(444, NULL);

	LinkedList::Node *pnpt;
	LinkedList::Node *npt = aaa.Find(222, pnpt);
	aaa.Insert(555, npt);
	aaa.Insert(666, pnpt);
	aaa.Insert(666, pnpt);
	aaa.Insert(666, pnpt);
	aaa.Insert(666, pnpt);
	aaa.Insert(222, NULL);
	aaa.PrintList();
	cout << endl;
	aaa.Delete(npt);
	aaa.Replace(666, 777);
	aaa.PrintList();
	cout << endl << aaa.FindKth(3);
	cout << endl << aaa.FindKth(9);
}