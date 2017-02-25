#include <iostream>
#include <fstream>
using namespace std;
void insertionsort(int A[]);
void quicksort(int A[], int P, int r);
int partition(int A[], int P, int r);
void swap(int A[], int x, int y);
void randopull(int A[]);
const int A_SIZE = 1000;
string path = "E:\\random1000.txt";

int main(){
	int A[A_SIZE];
	int B[A_SIZE];
	randopull(A);
	randopull(B);
	insertionsort(A);
	for (int i = 0; i < A_SIZE; i++){
		cout << A[i] << endl;
	}
	cout << "dun";
	quicksort(B, 0, 5);
	for (int i = 0; i < A_SIZE; i++){
		cout << A[i] << endl;
	}
	cout << "dun";
}

void insertionsort(int A[]){
	int subarr = 1;
	int index;
	for (; subarr < A_SIZE; subarr++){
		if (A[subarr - 1] > A[subarr]){
			for (index = subarr - 1; A[index] > A[index + 1] && index >= 0; index--){
				swap(A, index + 1, index);
			}
		}
	}
}

void quicksort(int A[], int P, int r){
	if (P < r){
		int index = partition(A, P, r);
		quicksort(A, P, index - 1 );
		quicksort(A, index + 1, r);
	}
}

int partition(int A[], int P, int r){
	int Pivot = A[r];
	int i = P;
	for (int j = P; j < r - 1; j++){
		if (A[j] <= Pivot){
			swap(A, i, j);
			i++;
		}
	}
	swap(A, i, r);
	return i;
}

void swap(int A[], int x, int y){
	int temp;
	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}

void randopull(int A[]){
	ifstream file(path);
	for (int i = 0; i < A_SIZE; i++){
		file >> A[i];
	}
	file.close();
}