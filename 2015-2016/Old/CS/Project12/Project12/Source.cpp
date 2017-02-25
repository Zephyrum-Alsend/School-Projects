//Lucas Crockett
//Lab #6 - Prime Example

#include <iostream>
using namespace std;
int main(){
	//declares variables + boolean
	int low, high;
	bool prime;

	//ask for input
	cout << "Input a range to test for prime numbers.\n";
	cin >> low;
	cin >> high;

	//finds prime numbers and outputs them
	for (int test = low + 1; test < high; test++){
		
		prime = true;
		
		for (int i = 2; i < test; i++){
			
			if (test%i == 0)
				prime = false;
		
		}
		
		if (prime == true)
			cout << test << " is a prime number.\n";
	
	}

	//indicates when done
	cout << "All numbers are tested.\n";

	system("pause");
}