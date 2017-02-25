//Lucas Crockett
//Lab #7 - Byte-sized pacakging

#include <iostream>
using namespace std;
void extract(unsigned long package, int num){
	//Bumps desired value to left end of long int, deleting what was left of it
	package = package << ((num - 1) * 4);
	//moves desired value to right end, deleting all to right of it
	package = package >> 28;
	cout << endl <<  "Value " << num << ": " << package << endl << endl;
}
int main(){
	unsigned long package = 0;
	int num;
	bool rng;
	char yeno;
	
	cout << "Input 8 numbers from 1 - 15 for compact storage.\n";
	for (int i = 0; i < 8; i++){
		//idiot check
		rng = false;
		while (rng == false){
			cin >> num;
			if (num <= 15 && num >= 1)
				rng = true;
			else
				cout << "Try a number between 1 and 15 this time.\n";
		}
		//stores value inside package
		package = package << 4;
		package += num;
	}

	//While loop so the user can extract as many values as s/he likes
	while (rng == true){
		cout << "Do you want to extract a value? Y/N\n";
		cin >> yeno;
		if (toupper(yeno) == 'Y'){
			//idiot check
			do{
				cout << "Which value do you want to extract? (1-8)\n";
				cin >> num;
			} while (num > 8 || num < 1);
			//runs extraction program
			extract(package, num);
		}
		//terminates program
		else if (toupper(yeno) == 'N'){
			cout << "Ending program.\n";
			rng = false;
		}
		//idiot check
		else
			cout << "Invalid input.\n";
	}

	system("pause");
}