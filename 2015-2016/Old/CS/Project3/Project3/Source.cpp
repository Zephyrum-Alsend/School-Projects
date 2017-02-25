//Lucas Crockett
//Lab #3 - # guessing game

#include <iostream>
#include <ctime>
using namespace std;
int main() {

	//sets up random number generator
	srand(time(NULL));

	//declares variables
	int guessme = rand( ) % 100 + 1;
	int wrongs = 0;
	int guess;
	bool correct = false;

	//cheat code
	//cout << guessme << endl;

	//guessing game loop
	for (;;){
		
		//user prompt
		cout << endl << "Guess a number from 1 to 100." << endl << "Go on. Take a stab." << endl;
		cin >> guess;

		//checks if guess is right, low, high, or nowhere
		if (guess == guessme){
			correct = true;
		}
		else if (guess < guessme && guess >= 1){
			cout << "Too low!" << endl;
			wrongs++;
		}
		else if (guess > guessme && guess <= 100){
			cout << "Too high!" << endl;
			wrongs++;
		}
		else{
			cout << "Out of range." << endl;
			wrongs++;
		}

		if (correct == true || wrongs == 99)break;
	}

	//easter egg
	if (wrongs == 99){
		cout << endl << "There's only one number left, " << guessme << ". Good job." 
			<< endl << endl << "Learn math." << endl << endl << endl;
	}
	//easter egg #2
	else if (wrongs == 0){
		cout << endl << "On the first try...!" << endl 
			<< endl << "CHEATS." << endl << "I call hacks!!" << endl;
	}
	//for grammar, and easter egg #3
	else if (wrongs == 1){
		cout << "Correct! " << guessme << " is right!" << endl << endl << "Finally, after " << wrongs 
			<< " wrong guess." << endl << "Now back to sleep mode... No? Damn." << endl;
	}
	//correct guess output message
	else {
		cout << "Correct! " << guessme << " is right!" << endl << endl << "Finally, after " << wrongs
			<< " wrong guesses." << endl << "Now could you put me on sleep mode? Please?" << endl;
	}

	system("pause");

}