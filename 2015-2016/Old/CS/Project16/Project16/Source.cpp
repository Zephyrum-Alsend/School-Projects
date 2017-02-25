//Lucas Crockett
//Lab #1 - fun array

#include <iostream>;
#include <cmath>;
using namespace std;
int main(){
	int fun[20];
	int low;
	int high;

	cin >> low;
	cin >> high;

	for (int i = 0; i < 20; i++){
		fun[i] = (7 * (i ^ 2)) - (4 * i) - 500;
		cout << fun[i] << endl;
	}

	//if (fun[i] > 0 && fun[i] > low && fun[i] < high)
	system("pause");
}