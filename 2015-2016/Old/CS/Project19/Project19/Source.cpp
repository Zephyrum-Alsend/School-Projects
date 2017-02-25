//Lucas Crockett
//Quiz #2 - Question 2: Correctional Sentence
//Outputs trash symbols in the unused space when neew[] is copied to sent[]

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void correction(char sent[80]);
int main(){
	char sent[80];
	cin.getline(sent, 80);

	correction(sent);

	int q = strlen(sent);
	for (int i = 0; i < q; i++)
		cout << sent[i];

	cout << endl;
	system("pause");
}
void correction(char sent[80]){
	int one;
	int two;
	char repl[80];
	char neew[80];
	char neaw[80];
	int z = strlen(sent);

	cout << "Input a replacement word.\n";
	cin.getline(repl, 80);

	cout << "Input the indexes to usurp.\n";
	cin >> one;
	cin >> two;

	int y = z;
	int x = 0;
	for (int i = two; i < y; i++){
		neaw[x] = sent[i];
		x++;
	}

	for (int i = 0; i < one; i++){
		neew[i] = sent[i];
	}

	y = strlen(neew) + strlen(repl);
	x = 0;
	for (int i = one; i < y; i++){
		neew[i] = repl[x];
		x++;
	}

	y = strlen(neew) + strlen(neaw);
	x = 0;
	for (int i = strlen(neew); i < y; i++){
		neew[i] = neaw[x];
		x++;
	}
	for (int i = strlen(neew); i < z; i++){
		neew[i] = '\0';
	}

	for (int i = 0; i < z; i++){
		sent[i] = neew[i];
	}
}