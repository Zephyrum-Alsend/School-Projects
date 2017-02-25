//Lucas Crockett
//Lab #10 - Today's Weather is...

#include <iostream>
#include <string>
#include <time.h>
#include <random>
using namespace std;
void weather(char& today){
	int chance = rand() % 100;  //initiates and declares random number for determining next day's weather
	//if today was snowy, tomorrow will be...
	if (today == 's'){
		if (chance < 30){
			today = 'r';
		}
		else if (chance < 50){
			today = 'f';
		}
		else{
			today = 's';
		}
	}
	//if today was fair, tomorrow will be...
	else if (today == 'f'){
		if (chance < 25){
			today = 'r';
		}
		else if (chance < 75){
			today = 'f';
		}
		else{
			today = 's';
		}
	}
	//if today was rainy, tomorrow will be...
	else{
		if (chance < 63){
			today = 'r';
		}
		else if (chance < 87){
			today = 'f';
		}
		else{
			today = 's';
		}
	}
}
int main(){
	srand(time(NULL));

	//initiates today and the weather/day count; starts on snowy day
	char today = 's';
	int snow = 1;
	int fair = 0;
	int rain = 0;
	
	//generates the weather for the next 999 days and keeps track of how many each type occured
	for (int days = 1; days < 1000; days++){
		weather(today);
		if (today == 's')
			snow++;
		else if (today == 'f')
			fair++;
		else
			rain++;
	}

	//outputs the weather for 1000 days
	cout << "Over 1000 days, " << snow << " days were snowy, " << fair << " were fair and " << rain << " were rainy.\n";

	system("pause");
}