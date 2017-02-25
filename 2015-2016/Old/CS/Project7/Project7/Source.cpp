# include <iostream>
using namespace std;
int main(){
	int smith[3][6];
	int x = 1;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 6; j++){
			smith[i][j] = x;
			x++;
		}
	}

	x = 1;
	for (int a = 0; a < 6; a++){
		for (int b = 0; b < 3; b++){
			x++;
			if (x <= 10){
				cout << " " << smith[a][b] << " ";
			}
			else{
				cout << smith[a][b] << " ";
			}
		}
		cout << endl;
	}

	system("pause");
}