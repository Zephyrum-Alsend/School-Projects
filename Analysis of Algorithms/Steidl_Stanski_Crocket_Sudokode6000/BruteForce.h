// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : BruteForce.h	###############################

#pragma once

#include <iostream>

#define ROW_COUNT 9
#define COLUMN_COUNT 9

#define INNER_ROW_COUNT 3
#define INNER_COL_COUNT 3
#define OUTER_ROW_COUNT 3
#define OUTER_COL_COUNT 3

using namespace std;

class BruteForce {
public:
	BruteForce(int[9][9]);
	bool Solve();
	void PrintBoard();
	
private:
	// ################## MEMBER VARIABLES ###############################
	int board[ROW_COUNT][COLUMN_COUNT];
	int boxSetBoard[OUTER_ROW_COUNT][OUTER_COL_COUNT][INNER_ROW_COUNT][INNER_COL_COUNT];
	int original[ROW_COUNT][COLUMN_COUNT];

	// ################### UTILITY FUNCTIONS #############################
	void SetValue(int a_row, int a_col, int a_value);
	void UnsetValue(int a_row, int a_col);
	void NextPosition(int &a_row, int &a_col);
	void PreviousPosition(int &a_row, int &a_col);
	bool isValid(int a_row, int a_col, int a_value);
	bool _Solve(int a_row, int a_col);
};