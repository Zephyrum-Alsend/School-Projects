// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : Sudoku.h	###############################


#pragma once

#include <fstream>

#include "BoxSet.h"
#include "BruteForce.h"

#define ROW_IMPLICATION true
#define ROW_COUNT 3
#define COLUMN_COUNT 3
#define BOXSET_ROW_DIM 3
#define BOXSET_COLUMN_DIM 3
#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9

using namespace std;

class Sudoku {

public:
	Sudoku();	// Base Constructor for the board
	Sudoku(string filePath); // Filling the board with values from the board (initial)

	void SolvePuzzle();	// Utilizes the BoxSet knowledge of related boxes to solve the puzzle
	void DisplayBoard();// Displays board to the user.
	void SolveUseBruteForce(); // Solves the board using a more brute force approach.

private:
	//###############	MEMBER VARIABLES	######################
	int m_board[BOARD_HEIGHT][BOARD_WIDTH];
	BruteForce m_brute = BruteForce(m_board);
	BoxSet *m_boxSets[ROW_COUNT][COLUMN_COUNT];

	//###############	MEMBER FUNCTIONS	######################
	void ConvertBoxToBoard(); // Converts boxset to a 9x9 array.
	bool IsUnsolved(); // For checking the status upon the completion of the Algorithm
};