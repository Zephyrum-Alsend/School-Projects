//Works.

#include <iostream>
#include <algorithm>
#include <string>
//#include <sstream>
using namespace std;
void TrimString(string &x);

int main() {
	string quack = " ,. ,HI,.,.,,,,, YALL.";
	cout << quack << endl;
	TrimString(quack);
	cout << quack << endl;

	exit(0);
}

void TrimString(string &x)
{
	int strt = -1;
	int end;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != ' ' && x[i] != ',' && x[i] != '.') {
			strt = i;
			break;
		}
	}
	if (strt == -1) return;
	for (int i = x.size()-1; i >= strt; i--) {
		if (x[i] != ' ' && x[i] != ',' && x[i] != '.') {
			end = i;
			break;
		}
	}
	x = x.substr(strt, end - strt);
}