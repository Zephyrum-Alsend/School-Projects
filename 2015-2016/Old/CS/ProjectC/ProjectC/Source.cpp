//Lucas Crockett
//Exam - Question 1
//Status: Works

#include <iostream>
using namespace std;
int main(){
	int test;
	
	cout << "Input an integer to test.\n";
	cin >> test;

	for (int te = 1; te <= test; te++){
		if ((float)(test % te) != 0)
			cout << te << endl;
	}

	cout << "These are all integers which divide evenly into " << test <<".\n";

	system("pause");
}