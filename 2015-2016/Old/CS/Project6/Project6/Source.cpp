#include <iostream>
using namespace std;
#include <ctime>
int main(){
	srand(time(NULL));

	int arr[3];
	for (int i = 0; i < 3; i++){
		arr[i] = rand() % 2;
		if (arr[i] == 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}

	system("pause");
}

//leave early for dinner
//pay for ESO myself
//crash when I get home