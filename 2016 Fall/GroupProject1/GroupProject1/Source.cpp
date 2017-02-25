#include <iostream>
using namespace std;

#include "OptFunc.h"

int main() {
	for (double x = 0; x < 5; x += .5) {
		cout << "x =" << x << "     " << OptFunc(x, 3, 6) << endl;
	}
}