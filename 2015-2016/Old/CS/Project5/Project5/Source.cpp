#include <iostream>
using namespace std;
int main(){

	float a, b, c;
	bool pessimism = true;

	cout << "Input three positive decimals to be examined." << endl;

	while (pessimism == true){
		cin >> a;
		if (a >= 0){
			pessimism = false;
		}
		else{
			cout << "Don't be negative!" << endl;
		}
	}

	while (pessimism == false){
		cin >> b;
		if (b >= 0){
			pessimism = true;
		}
		else{
			cout << "Positives only." << endl;
		}
	}

	while (pessimism == true){
		cin >> c;
		if (c >= 0){
			pessimism = false;
		}
		else{
			cout << "What number is greater than zero?" << endl << "Not negative." << endl;
		}
	}

	if ((a < b && a > c) || (a < c && a > b)){
		cout << a << endl;
	}
	else if ((b < a && b > c) || (b < c && b > a)){
		cout << b << endl;
	}
	else{
		cout << c << endl;
	}

	system("pause");

}