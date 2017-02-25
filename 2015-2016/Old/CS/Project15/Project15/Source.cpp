//Lucas Crockett
//Pointer syntax

#include <iostream>;
using namespace std;
int main(){

	//Makes x = 8 using a pointer
	int x = 7;

	int * ptr_x;

	ptr_x = &x;

	*ptr_x = 8;

}