//Lucas Crockett
//Lab #8 - pilF ecnetneS

#include<iostream>
#include<string>

using namespace std;
void crimsonletter(string &str);
int main(){
	string str;

	cout << "Input a sentence.\n";
	getline(cin, str);

	crimsonletter(str);
	cout << str << endl;

	system("pause");

}
void crimsonletter(string &stri){
	int p = stri.length()-1;
	char a;
	for (int i = 0; i < stri.length()/2; i++){
		a = stri[i];
		stri[i] = stri[p];
		stri[p] = a;
		p--;
	}
}