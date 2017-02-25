//Lucas Crockett
//Lab #4 - Saving the bank

#include <iostream>
using namespace std;
int main(){
	//declares variables
	float savi;
	float perc;
	float inter;
	int year;

	//asks for user deposit
	cout << "How much money will you deposit? ($$$$.$$)\n";
	cin >> savi;

	//asks for interest rate
	cout << "What is your ideal interest rate? (%%.%) \n";
	cin >> perc;

	//asks for years saved
	cout << "After how many years do you plan to withdraw your compounded amount? (YY)\n";
	cin >> year;

	//converts interest to decimal
	inter = perc / 100.0;

	//calculates value w/ interest
	for (int i = year; i > 0; i--){
		savi = savi * (inter + 1);
	}

	//truncates value to two decimals
	savi = (float)((int)(savi*100))/100;

	//output
	cout << "You will withdraw $" << savi << " in the year " << (2014 + year) << ".\n";

	system("pause");

}