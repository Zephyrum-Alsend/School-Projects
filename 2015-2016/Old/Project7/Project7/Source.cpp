//Lcuas Crockett
//Lab #9

#include <iostream>
#include <math.h>
using namespace std;
void solutioncalc(float interval, float water, float salt){
	//counter for 5 minute intervals
	float time = 1;

	//i is in minutes
	for (float i = 0; i <= 30; i += interval){
		//intake of solution
		water += interval*(5);
		salt += interval*(1.5);

		//leakage of solution
		water -= interval*(4);
		salt -= interval*(4 * (salt / water));

		//5 minute bucket scooping
		if (i / 5 >= time){
			water -= 2;
			salt -= 2 * (salt / water);
			time++;
		}
	}

	cout << "After 30 minutes, " << water << " gallons of solution remain, \ncontaining "
		<< salt << " pounds of salt for \n" << (salt / water)
		<< " pounds per gallon. \nCalculated at intervals of " << interval << " minutes.\n";
}
int main(){
	float water = 300;
	float salt = 10;
	float interval;

	cout << "Input an interval to calculate with (cannot exceed 30 minutes).\n";
	cin >> interval;

	solutioncalc(interval, water, salt);
	
	system("pause");
}