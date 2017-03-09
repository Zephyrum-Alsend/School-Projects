#include <iostream>
#include <stdio.h>
#include <chrono>


using namespace std;
#include "Sudoku.h"

void solveOne();
void solveTwo();
void solveThree();

int main()
{
	solveOne();
	solveTwo();
	solveThree();
	return 0;
}


//#################  TESTING CODE  ####################
void solveOne() {
	chrono::high_resolution_clock::time_point puzzle1_start = chrono::high_resolution_clock::now();
	Sudoku sudocode("easypuzzle1.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.SolveUseBruteForce();
	chrono::high_resolution_clock::time_point puzzle1_end = chrono::high_resolution_clock::now();
	auto puzzle1_total = chrono::duration_cast<chrono::microseconds>(puzzle1_end - puzzle1_start);
	cout << endl << endl;
	cout << puzzle1_total.count() <<endl;
	
}

void solveTwo() {
	chrono::high_resolution_clock::time_point puzzle2_start = chrono::high_resolution_clock::now();
	Sudoku sudocode("easypuzzle2.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.SolveUseBruteForce();
	chrono::high_resolution_clock::time_point puzzle2_end = chrono::high_resolution_clock::now();
	auto puzzle2_total = chrono::duration_cast<chrono::microseconds>(puzzle2_end - puzzle2_start);
	cout << endl << endl;
	cout << puzzle2_total.count() << endl;
	
}

void solveThree() {
	chrono::high_resolution_clock::time_point puzzle3_start = chrono::high_resolution_clock::now();
	Sudoku sudocode("easypuzzle3.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.SolveUseBruteForce();
	chrono::high_resolution_clock::time_point puzzle3_end = chrono::high_resolution_clock::now();
	auto puzzle3_total = chrono::duration_cast<chrono::microseconds>(puzzle3_end - puzzle3_start);
	cout << endl << endl;
	cout << puzzle3_total.count() << endl;

	system("pause");
}