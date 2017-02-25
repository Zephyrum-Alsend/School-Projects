//Lucas Crockett
//Lab 2 - It Does a Thing, We Think
//Status: Working

#include <iostream>
using namespace std;

int main(){
	int *arr = new int [2];
	int min;
	int count = 0;

	//Asks for input and provides exit command.
	cout << "Enter integers, any integers. Enter -1 to stop." << endl;
	while(true){
		//Since min is used later and an int input would be used only here, min is reused.
		cin >> min;
		if (min == -1)
			break;
		arr[count] = min;
		count++;
		//Allocates more memory to the array if capacity is maxed.
		if (count % 2 == 0){
			int *arrg = new int [count + 2];
			for (int i = 0; i < count; i++){
				arrg[i] = arr[i];
			}
			delete[] arr;
			arr = arrg;
		}
	}

	//Min is used for its original purpose.
	min = arr[0];
	//Count has kept track of the array size, no need to find it.
	for (int i = 0; i < count; i++){
		if (min > arr[i])
			min = arr[i];
	}

	cout << "The differences from the smallest integer are as follows:\n";
	for (int i = 0; i < count; i++){
		cout << arr[i] << "\t+" << arr[i] - min << endl;
	}

	delete[] arr;
	return(0);
}