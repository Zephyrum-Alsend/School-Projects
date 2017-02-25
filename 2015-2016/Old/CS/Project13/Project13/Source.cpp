//Lucas Crockett
//Lab #7 - Run For Your Lives!

#include <iostream>
using namespace std;
int main(){
	//declares variables and boolean
	float mile;
	bool minu = true;

	//asks for input and re-asks if out of range
	while (minu == true){
		cout << "Input your reading. (mph)\n";
		cin >> mile;
		if (1 <= mile && mile <= 12 && (int)(mile*100) % 10 == 0)
			minu = false;
		else
			cout << "Overload Error.\n";
	}

	//converts to miles per minute
	cout << (1 / mile) * 60 << " minutes per mile.\n";

	system("pause");

}