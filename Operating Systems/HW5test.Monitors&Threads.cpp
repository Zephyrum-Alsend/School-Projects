//Operating Systems HW 5
//Lucas Crockett
//Status: Working
#include "HW5.h"
#include <iostream>
#include <thread>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

//Calculates fibonacci numbers and loads them into the Q
void fibcalc(SafeQueue * SQ, int * r)
{
	double fibnum;
	double Phi = ((1+sqrt(5))/2);
	double phi = ((1-sqrt(5))/2);
	for (int i = 1; i < *r + 1; i++)
	{
		fibnum = ( ( pow(Phi, i) - pow(phi, i) ) / sqrt(5) );
		//If SQ is full, yield to fibread then try writing again
		while(!SQ->write(fibnum))
		{
			/*
			cout << "Hurry up!\n";
			*/
			this_thread::yield();
		}
	}
}

//Opens a file, "fib-r.txt", and writes the valus from Q into it
void fibread(SafeQueue * SQ, int * r)
{
	double fibe;
	ofstream fibfile;
	fibfile.open("fib-" + to_string(*r) + ".txt");
	
	for(int i = 0; i < *r; i++)
	{
		SQ->read(fibe);
		/*
		cout << fibe << endl;
		*/
		fibfile << (i + 1) << ": " << fibe << endl;
	}
	
	fibfile.close();
}

int main()
{
	SafeQueue fibtun;
	int userinput;
	/*
	if(fibtun.isEmpty()) cout << "is empty\n";
	else cout << "has something\n";
	*/
	
for(;;)
{
	do {
		cout << "Enter a value from 1 - 50, -1 to quit:\n";
		//Do not input anything other than an int. Crazy things happen otherwise.
		cin >> userinput;
		if (userinput == -1)
		{
			exit(0);
		}
	} while (userinput < 1 || userinput > 50);
	
	thread calc(fibcalc, &fibtun, &userinput);
	//cout << "fibcalc initiated\n";
	thread read(fibread, &fibtun, &userinput);
	//cout << "fibread initiated\n";

	calc.join();
	//cout << "fibcalc terminated\n";
	read.join();
	//cout << "fibread terminated\n";
}
}
