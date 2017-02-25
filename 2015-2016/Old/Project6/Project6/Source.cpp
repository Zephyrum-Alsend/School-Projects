//Lucas Crockett
//Lab #5 - piglatin translator

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void piglatin(string& str);
int main(){
	string str;
	cout << "Input a word or sentence or phrase to translate into pig latin.\n";
	getline(cin, str);

	piglatin(str);
	cout << str << endl;

	system("pause");
}
void piglatin(string& str){
	//declares storage strings
	string str1;
	string str2;
	string str3;

	//declares string index holder
	int ind1 = 0;
	for (int i = 0; i < str.length(); i++){
		//checks for when a word ends, stores index, and converts word to piglatin
		if (isspace(str.at(i))){
			str1 = str.substr(ind1, 1);
			str2 = str.substr(ind1 + 1, i-(ind1+1));
			str3 = str3 + str2 + str1 + "ay ";
			ind1 = i+1;
		}
		//translates final word to piglatin
		if ((i + 1) == str.length()){
			str1 = str.substr(ind1, 1);
			str2 = str.substr(ind1 + 1);
			str3 = str3 + str2 + str1 + "ay ";
		}
	}

	//replaces input string with translated string
	str = str3;
}