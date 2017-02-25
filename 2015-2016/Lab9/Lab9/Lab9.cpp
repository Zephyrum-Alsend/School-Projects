//Lab 9 - Binary Search
//Lucas Crockett
//Status: Working

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;
template <class T>
int find(T array[], int size, T key){
	int beg = 0;
	int end = size - 1;
	int ind = size / 2;
	
	//A little extra overhead, using a For + If instead of a While, to eliminate the possibility of an infinite loop
	for (int i = 0; i < size; i++){
		if (array[ind] == key)
			return ind;
		if (array[ind] < key){
			beg = ind;
		}
		else{
			end = ind;
		}
		ind = (beg + end) / 2;
		//If beg and end are right next to each other (2 elements in partition)
		if (ind == beg){
			if (array[end] == key){
				return end;
			}
			else if (array[beg] == key){
				return beg;
			}
			else{
				return -1;
			}
		}
	}
	return -1;  //If the For loop is ever exhausted
}


int main(){
	srand(time(NULL));
	const int arrSize = 10;
	int randRange = 100;
	int arr[arrSize];

	for(int i = 0; i < 10; i++){
		//Populates array with random numbers
		for (int j = 0; j < arrSize; j++){
			arr[j] = (int)rand() % randRange;
		}
		sort(&arr[0], &arr[arrSize]);
		//Finds position and reports it
		for (int k = 0; k < arrSize; k++){
			cout << arr[k] << "\t" << find(arr, arrSize, arr[k]) << endl;
		}
		cout << endl;
	}
}