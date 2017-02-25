//Lucas Crockett
//Lab #2 - More fun?

#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int fun[3][3][3];
	int l1 = 9;
	int l2 = 9;
	int l3 = 9;
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;

	for (int a = 0; a < 3; a++){
		cout << endl;
		for (int b = 0; b < 3; b++){
			cout << " ";
			for (int c = 0; c < 3; c++){
				fun[a][b][c] = (int)(rand() % 10);
				//ranks value by lowest
				if (fun[a][b][c] <= l1){
					l3 = l2;
					l2 = l1;
					l1 = fun[a][b][c];
				}
				else if (fun[a][b][c] <= l2){
					l3 = l2;
					l2 = fun[a][b][c];
				}
				else if (fun[a][b][c] <= l3){
					l3 = fun[a][b][c];
				}
				//ranks value by highest
				if (fun[a][b][c] >= r1){
					r3 = r2;
					r2 = r1;
					r1 = fun[a][b][c];
				}
				else if (fun[a][b][c] >= r2){
					r3 = r2;
					r2 = fun[a][b][c];
				}
				else if (fun[a][b][c] >= r3){
					r3 = fun[a][b][c];
				}

				cout << " " << fun[a][b][c] << " ";
			}
		}
		cout << endl;
	}

	cout << endl << "Highest values:" << endl << r1 << endl << r2 << endl << r3 << endl;
	cout << "Lowest values:\n" << l1 << endl << l2 << endl << l3 << endl;

	system("pause");
}