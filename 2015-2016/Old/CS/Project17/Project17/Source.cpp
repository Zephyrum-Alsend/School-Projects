//Lucas Crockett
//Quiz #2 - Question 1: Piglatin translator
//Functioning

#include <iostream>
#include <string>
using namespace std;
void piglatin(string& str);
int main(){
	string str;
	cout << "Input a word to translate into pig latin.\n";
	getline(cin, str);

	piglatin(str);
	cout << str << endl;

	system("pause");
}
void piglatin(string& str){
	string str1(str, 0, 1);
	string str2(str, 1);
	str = str2 + str1 + "ay";
}