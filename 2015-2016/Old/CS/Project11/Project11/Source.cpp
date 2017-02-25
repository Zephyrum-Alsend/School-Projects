//Lucas Crockett
//Lab #5 - あ　い　う　え　お

#include <iostream>
using namespace std;
int main(){
	//declares c-string
	char sent[80];

	//input declaration
	cout << "Type something.\n";
	cin.getline(sent, 80);

	//gets c-srting length
	int ran = strlen(sent);

	//declares counters
	int a = 0;
	int i = 0;
	int u = 0;
	int e = 0;
	int o = 0;

	cout << endl;

	//counts vowels
	for (int NB = 0; NB < ran; NB++){
		if (sent[NB] == 'a' || sent[NB] == 'A')
			a++;
		else if (sent[NB] == 'i' || sent[NB] == 'I')
			i++;
		else if (sent[NB] == 'u' || sent[NB] == 'U')
			u++;
		else if (sent[NB] == 'e' || sent[NB] == 'E')
			e++;
		else if (sent[NB] == 'o' || sent[NB] == 'O')
			o++;
	}

	//output counter
	cout << "There were\n" << a << " A's\n" << i << " I's\n" << u << " U's\n" << e << " E's\n" << o << " O's" << endl;

	system("pause");
}