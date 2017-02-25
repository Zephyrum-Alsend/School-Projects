//Lucas Crockett
//Lab #3 - I spy with my array

#include <iostream>;

using namespace std;
void lowfinder(int& x, int& y, int kk[50][50], int mx, int my);
int main(){
	int ung[50][50];
	int mx, my, xx, yy;
	int sum = 0;

	//input array dimensions
	cout << "Input the array dimensions. (up to 50 x 50)\n";
	cin >> mx;
	cin >> my;

	//input array values
	cout << "Input the array values. (hope you didn't make a large array)\n";
	for (int a = 0; a < mx; a++)
		for (int b = 0; b < my; b++)
			cin >> ung[b][a];

	//output array
	for (int a = 0; a < mx; a++){
		cout << endl;
		for (int b = 0; b < my; b++){
			cout << " " << ung[b][a] << " ";
		}
		cout << endl;
	}

	//function for finding lowest value and coordinates
	lowfinder(xx, yy, ung, mx, my);

	//sums row/column
	for (int a = 0; a < mx; a++){
		sum += ung[yy][a];
	}
	for (int b = 0; b < my; b++){
		sum += ung[b][xx];
	}

	cout << endl << sum << endl;


	system("pause");
}
void lowfinder(int& x, int& y, int kk[50][50], int mx, int my) {
	int low = kk[0][0];
	x = 0;
	y = 0;

	for (int a = 0; a < mx; a++)
		for (int b = 0; b < my; b++){
			if (kk[b][a] < low){
				x = a;
				y = b;
				low = kk[b][a];
			}
		}

}