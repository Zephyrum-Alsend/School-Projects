//Lucas Crockett
//Lab 1 - It Does a Thing
//Status: Working

#include <iostream>
using namespace std;

int main(){
	int size;
	int min;

	cout << "The size of the array is: ";
	cin >> size;
	
	int * arr = new int [size];
	
	cout << "Enter " << size << " integers." << endl;
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	}

	//Finds smallest value in array.
	min = arr[0];
	for (int i = 0; i < size; i++){
		if (min > arr[i])
			min = arr[i];
	}
	
	cout << "The differences from the smallest integer are as follows:\n";
	for (int i = 0; i < size; i++){
		cout << arr[i] << "\t+" << arr[i] - min << endl;
	}

	delete[] arr;
	return(0);
}