# include <iostream>
using namespace std;
int main(){
	char sent[80];
	cin.getline(sent, 80);

	int ran = strlen(sent);

	int a = 0;
	int i = 0;
	int u = 0;
	int e = 0;
	int o = 0;

	cout << endl;
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

	cout << a << " " << i << " " << u << " " << e << " " << o << endl;

	system("pause");
}