#include <iostream>
#include <cmath>
using namespace std;
int main() {

	int x = 1;
	int y = 0;
	do{
		y = y + x;
		x++;
	} while (x <= 1000);
	cout << y << endl;


	system("pause");
}