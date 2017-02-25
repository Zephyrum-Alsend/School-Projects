//Lucas Crockett
//Lab #1 - fun array

#include <iostream>;
#include <cmath>;
using namespace std;
int main(){
	int fun[20];
	int low;
	int high;

	cout << "A unique array will be generated.\nInput the range of values you want it to output.\nLow value first.\n";
	cin >> low;
	cout << "High value second.\n";
	cin >> high;

	for (int i = 19; i >-1; i--){
		fun[i] = (7 * (i * i) - (4 * i) - 500);
	}

	cout << "\nThe array is as follows:\n";
	for (int i = 19; i > -1; i--){
		if (fun[i] > 0 && fun[i] > low && fun[i] < high){
			cout << fun[i] << endl;
		}
	}
	
			
	system("pause");
}