//Lucas Crockett
//Lab #12 - Life & Death

#include <iostream>
#include <random>
#include <time.h>
using namespace std;
void bigbang(int universe[10][10]);
void generation(int uni[10][10]);
int main(){
	srand(time(NULL));
	int universe[10][10];
	
	bigbang(universe);
	system("pause");
	generation(universe);
	system("pause");
}
void bigbang(int universe[10][10]){
	//Seeds life randomly throughout universe
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 10; x++){
			universe[y][x] = (int)(rand() % 2);
		}
	}

	//Outputs universe at generation 0
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 10; x++){
			cout << " " << universe[y][x] << " ";
		}
		cout << endl << endl;
	}
}
void generation(int uni[10][10]){
	int life;
	int gen;
	int uni2[10][10];
	cout << "How many generations do you want to go through?\n";
	cin >> gen;

	for (int g = 0; g < gen; g++){
		//copies universe into universe2
		for (int y = 0; y < 10; y++){
			for (int x = 0; x < 10; x++){
				uni2[y][x] = uni[y][x];
			}
		}
		//checks universe for conditions and applies changes to universe2
		for (int y = 0; y < 10; y++){
			for (int x = 0; x < 10; x++){
				life = 0;
				//checks for life in immediate surroundings
				if (uni[y - 1][x - 1] == 1 && -1 < (y - 1) && (y - 1) < 10 && -1 < (x - 1) && (x - 1) < 10){
					life++;
				}
				if (uni[y - 1][x] == 1 && -1 < (y - 1) && (y - 1) < 10 && -1 < x < 10){
					life++;
				}
				if (uni[y - 1][x + 1] == 1 && -1 < (y - 1) < 10 && -1 < (x + 1) < 10){
					life++;
				}
				if (uni[y][x - 1] == 1 && -1 < y < 10 && -1 < (x - 1) < 10){
					life++;
				}
				if (uni[y][x + 1] == 1 && -1 < y < 10 && -1 < (x - 1) < 10){
					life++;
				}
				if (uni[y + 1][x - 1] == 1 && -1 < (y + 1) < 10 && -1 < (x - 1) < 10){
					life++;
				}
				if (uni[y + 1][x] == 1 && -1 < (y + 1) < 10 && -1 < x < 10){
					life++;
				}
				if (uni[y + 1][x + 1] == 1 && -1 < (y + 1) < 10 && -1 < (x + 1) < 10){
					life++;
				}
				//determines life, death, or birth
				if (life == 3){
					uni2[y][x] = 1;
				}
				else if (life < 2 || life > 3){
					uni2[y][x] = 0;
				}
			}
		}
		//Copies universe2 to universe
		for (int y = 0; y < 10; y++){
			for (int x = 0; x < 10; x++){
				uni[y][x] = uni2[y][x];
			}
		}
		//Outputs universe at generation x
		cout << endl;
		for (int y = 0; y < 10; y++){
			for (int x = 0; x < 10; x++){
				cout << " " << uni[y][x] << " ";
			}
			cout << endl << endl;
		}
	}

	
}