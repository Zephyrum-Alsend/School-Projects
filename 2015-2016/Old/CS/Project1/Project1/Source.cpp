//Lucas Crockett
//Lab #1 - What's today's temperature's conversion?

#include <iostream>
using namespace std;
int main(){

	//declares Celsius variable
	int C;
	
	//asks for temperature
	cout << "What temperature is it today? (In Celsius, please)" << endl;
	cin >> C;

	//outputs C in Fahrenheit
	cout << endl << "That's... " << (1.8 * C + 32) << " degrees fahrenheit, sirah." << endl << endl;

	for (int x = -5; x <= 30.3; x = x + 2){
		cout << x << endl;
	}

	system ("pause");


}