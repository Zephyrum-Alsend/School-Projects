// To test the implementation of the ADT list using arrays.
#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
	ArrayList aaa;

	// Initialize the list.
	cout << "Array size = " << aaa.listSize() << endl;

	// Insert a lot of stuff;
	aaa.Insert(111, 0);
	aaa.Insert(222, 0);

	aaa.PrintList();
	cout << endl;

	aaa.Insert(333, 2);
	aaa.Insert(444, 1);
	aaa.Insert(555, 0);
	aaa.Delete(222);
	aaa.Insert(666, 0);
	aaa.Insert(555, 1);
	aaa.Replace(555, 666);

	aaa.PrintList();
	cout << endl << "Array size = " << aaa.listSize();
	cout << endl << "At position 4 is: " << aaa.FindKth(4);
	cout << endl << "At position 9 is: " << aaa.FindKth(9);
	cout << endl << "At position 0 is: " << aaa.FindKth(0);
}