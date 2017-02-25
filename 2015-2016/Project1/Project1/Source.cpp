//Quiz 1
//Lucas Crockett
//Status: Working - testing code removed

#include <iostream>
using namespace std;
void ChangeSize(double *&x, int currentSize, int desiredSize);
template <typename T>
T exponential(T x, int n){
	if (n > 1){
		return x*exponential(x, (n - 1) );
	}
	
	else if (n < 0){
		return (1 / x*exponential(x, (n + 1)));
	}
	
	else if (n == 1){
		return x;
	}
	
	else{
		return 1;
	}
}

int main(){
	int *num = new int[10000];	//So the new ints can be accessed/deleted

	//Assigns all ints to -1
	for (int i = 0; i < 10000; i++){
		num[i] = -1;
	}

	delete num;

	return(0);
}

void ChangeSize(double *&x, int currentSize, int desiredSize){
	double *temp = new double[desiredSize];

	//Uses the smaller array size as stopping point for copying
	if (desiredSize < currentSize){
		for (int i = 0; i < desiredSize; i++){
			temp[i] = x[i];
		}
	}
	else{
		for (int i = 0; i < currentSize; i++){
			temp[i] = x[i];
		}
	}

	delete x;	//deletes original array
	x = temp;
}