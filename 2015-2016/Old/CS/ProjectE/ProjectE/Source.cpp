//Lucas Crockett
//Exam - Question 3
//Status: Works

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void finder(string str, string &str2, char vow);
int main(){
	string found;
	string sentence;
	char who;

	cout << "Input a sentence.\n";
	getline(cin, sentence);

	cout << "What vowel do you want to search for?\n";
	cin >> who;

	finder(sentence, found, who);

	cout << who << " is found in the following indexes:\n" << found << endl;

	system("pause");
}

void finder(string str, string &str2, char vow){
	for (int i = 0; i < str.length(); i++){
		stringstream ss;
		if (str.at(i) == vow){
			ss << i;
			str2 = str2 + ss.str() + ' ';
		}
	}
}