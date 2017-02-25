#include "ThreeNumbersISee.h"
#include <iostream>
using namespace std;

int ThreeNumbersISee::count = 0;

ThreeNumbersISee::ThreeNumbersISee()
{
	count++;
	x = y = z = 1;
	cout << "count = " << count << endl;
}


ThreeNumbersISee::~ThreeNumbersISee()
{
	count--;
	cout << "quiggity quackerjack" << endl;
}
