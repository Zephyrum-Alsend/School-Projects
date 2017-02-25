//Lucas Crockett
//Quiz #4 - Question 1
//functioning

#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1 = "I am a fun person";
	string str2 = "Some feel that great programmers are rare";

	string str3 = str1.substr(0, 7) + str2.substr(15, 16);

	cout << str3 << endl;

	system("pause");

}