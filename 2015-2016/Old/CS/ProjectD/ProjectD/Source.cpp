//Lucas Crockett
//Exam - Question 2
//Status: Works

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void rearrange(string &str);
int main(){
	string name;
	cout << "Input a full name.\n";
	getline(cin, name);

	rearrange(name);

	cout << name << endl;

	system("pause");
}

void rearrange(string &str){
	string st;
	string nd;
	string rd;
	
	int a = 0;
	int b = 0;
	
	for (int i = 0; i < str.length(); i++){
		if (isspace(str.at(i))){
			if (a == 0)
				a = i;
			else if (b == 0)
				b = i;
		}
	}

	st = str.substr(0, a + 1);
	nd = str.substr(a + 1, b - a);
	rd = str.substr(b + 1);

	str = rd + ", " + st + nd;
}