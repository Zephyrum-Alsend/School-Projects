//Lucas Crockett
//Lab #2 - Orders numbers' placements ascending

#include <iostream>
using namespace std;
int main(){
	//input variables
	int x, y, z;
	//output variables
	int a, b, c;

	//ask for user input
	cout << "List a number, any number!" << endl;
	cin >> x;

	for (;;){
		cout << endl << "And how about another two numbers? Uniqueness is appreciated." << endl;
		cin >> y;
		cin >> z;
		if (x != y && x != z && y != z)break;
	}

	//Compares values, and assigns them to a, b, c in ascending order
	if (x > y && x > z){
		c = x;
		if (y > z){
			b = y;
			a = z;
		}
		else {
			a = y;
			b = z;
		}
	}
	else if (x < y && x < z){
		a = x;
		if (y > z){
			c = y;
			b = z;
		}
		else{
			b = y;
			c = z;
		}
	}
	else {
		b = x;
		if (y > z){
			c = y;
			a = z;
		}
		else{
			a = y;
			c = z;
		}
	}

	//output
	cout << endl << "Your lucky number is " << a << " " << b << " " << c << "!" << endl << endl;

	system("pause");

}