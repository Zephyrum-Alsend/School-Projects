//Lucas Crockett
//Lab #4 - Recursive programming

#include <iostream>
using namespace std;
int gcd(int x, int y);
int main(){
	//declares all integer variables
	int x;
	int y;
	int z;

	//asks for user input (more efficient than altering code each round)
	cout << "Input two numbers. The GCD will be calculated.\n";
	cin >> x;
	cin >> y;

	//calls upon and stores gcd() in z
	z = gcd(x, y);

	//outputs gcd
	cout << "The GCD is: " << z << endl;

	system("pause");
}
int gcd(int x, int y){
	if (y != 0)
		return gcd(y, (x % y));
	else
		return x;
}