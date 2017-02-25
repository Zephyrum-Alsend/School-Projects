//Lucas Crockett
//Quiz #4 - Question 2
//functioning

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void crimsonletter(string &str);
int main(){
	string str;
	bool word = false;
	int words;

	cout << "Input a sentence of three or more words.\n";
	while (word == false){
		getline(cin, str);

		words = 1;
		for (int i = 0; i < str.length(); i++){
			if (isspace(str.at(i)))
				words++;
		}
		if (words >= 3)
			word = true;
		else
			cout << "Try again.\n";
	}
	
	crimsonletter(str);
	cout << str << endl;

	system("pause");

}
void crimsonletter(string &str){
	for (int i = 0; i < str.length(); i++){
		if (str.at(i) == 'a')
			str[i] = 'e';
		else if (str.at(i) == 'e')
			str[i] = 'a';
	}
}