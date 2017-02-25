// Functions to support list operations on an array.
#include <iostream>
#include <assert.h>
#include "ArrayList.h"
using namespace std;

// Contructor sets valriables to indicate that we have an empty list.
ArrayList::ArrayList() {

	ArraySize = 0;
	nelts = 0;
	array = NULL;
}
// Destructor used to clean up allocated resources/
ArrayList::~ArrayList() {

	delete[] array;
}
// Delete all the elements from the list.
void ArrayList::MakeEmpty()
{
	delete[] array;
	nelts = 0;
	ArraySize = 0;
	array = NULL;	// Why do this?
}
// Tests to see if there are no elements in the array.
bool ArrayList::isEmpty()
{
	return nelts == 0;
}
// Return the index of the first occurrance of a specified list element.  Returns -1 if not found.
int ArrayList::Find(double y)
{
	for (int i = 0; i < nelts; i++) {
		if (array[i] == y) {

			// The user is considering the first element to be at position 1.
			return i;
		}
	}
	return -1;
}
// Insert the specied number in the list position.
void ArrayList::Insert(double y, int position)
{
	// Abort the program if a bad position is specified.
	assert(position >= 0 && position <= nelts);

	// Note the array position.  Recall that lists are numbered starting with 1.
	int ia = position;

	// Make sure there is space in the array for a new element.
	MakeSpace();

	// If we are adding a new element to the list, open up space if necessary.
	if (ia < nelts) {
		memmove(&array[ia + 1], &array[ia], (nelts - ia) * sizeof(double));
	}
	array[ia] = y;
	nelts++;
}
// Deletes first instance of a specified element in the array list.
void ArrayList::Delete(double y) {
	int ia = Find(y);
	if (ia != -1) {
		memmove(&array[ia], &array[ia + 1], (nelts - ia) * sizeof(double));
		nelts--;
	}
}
// Finds the Kth element in the list and returns it. Returns 0 if not found.
double ArrayList::FindKth(int position) {
	if (position < 0 || position > nelts) {
		return 0;
	}
	return array[position];
}
// Replaces all occurances of a with b and returns a count of the number of elements replaced.
int ArrayList::Replace(double a, double b) {
	int ia = Find(a);
	int count = 0;
	while (ia != -1) {
		count++;
		array[ia] = b;
		ia = Find(a);
	}
	return count;
}
// Display the elements of the list.
void ArrayList::PrintList()
{
	// Display the list.
	for (int i = 0; i < nelts; i++) {
		cout << i << ". " << array[i] << endl;
	}
}
void ArrayList::MakeSpace()
{
	// If there is space for another array element, return.
	if (nelts < ArraySize) return;

	// Create storage to make a larger array.
	double *tmp;
	tmp = new double[ArraySize + ArrayIncrement];

	// Note that exceptions now occur when new fails unless you tell the compiler otherwise.
	assert(tmp != NULL);

	// If the previous array was not empty, must copy its contents.
	if (nelts > 0) {
		memcpy(tmp, array, nelts * sizeof(double));
		delete[] array;
	}
	ArraySize += ArrayIncrement;
	array = tmp;
}
