// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : Sudoku.cpp	###############################


#include "Sudoku.h"


/**/
/*
		Sudoku::Sudoku Sudoku::Sudoku

	NAME
		Sudoku::Sudoku()

	SYNOPSIS
		Sudoku::Sudoku();

	DESCRIPTION
		Class constructor for Soduko, creating the m_board through
		BoxSets which is a 3x3 box connected to other 3x3 boxes
		which make up the Soduko m_board.

	RETURN
		((void))
*/
/**/
Sudoku::Sudoku() {

	// Initialize BoxSets :: 3x3 container at a specific row and column number.
	for(int row = 0; row < ROW_COUNT; row++)
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			m_boxSets[row][column] = new BoxSet(row, column);
		}
	for (int row = 0; row < ROW_COUNT; row++)
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			BoxSet* rowNeighbors[2]{ m_boxSets[row][(column + 1) % 3], m_boxSets[row][(column + 2) % 3] };
			BoxSet* columnNeighbors[2]{ m_boxSets[(row + 1) % 3][column], m_boxSets[(row + 2) % 3][column] };
			m_boxSets[row][column]->setNeighbors(rowNeighbors[0], rowNeighbors[1], columnNeighbors[0], columnNeighbors[1]);
		}

	ConvertBoxToBoard();
}
/*Soduko::Soduko();*/


/**/
/*
		Sudoku::Sudoku Sudoku::Sudoku

	NAME
		Sudoku::Sudoku(string filePath) :Sudoku::Sudoku()

	SYNOPSIS
		Sudoku::Sudoku(string filePath)
			:Sudoku::Sudoku();

		a_filePath, the filepath for the text file of Soduko problems to solve.

	DESCRIPTION
		Class constructor for filling in the contents of each of the boxes in the
		BoxSet to the values in the Soduko Puzzle files (to be solved)

	RETURN
		((void))
*/
/**/
Sudoku::Sudoku(string a_filePath)
	:Sudoku::Sudoku()
{
	ifstream file;
	file.open(a_filePath);
	if (!file.is_open()) {
		cout << "Error opening the file" << endl;
		system("pause");
		exit(1);
	} 
	int file_values[81];
	for (int i = 0; i < 81; i++)
		file >> file_values[i];

	// box_row represents a row of the Soduko Puzzle including 3 box segments (3 rows)
	for (int box_row = 0; box_row < ROW_COUNT; box_row++)

		// inner_row represents section we are trying to insert information into the 3x3 box area
		for (int innerRow = 0; innerRow < ROW_COUNT; innerRow++)

			// box_col represents a column of the puzzle including 3 box segments (3 columns)
			for (int box_col = 0; box_col < COLUMN_COUNT; box_col++)
				
				// innerColumn represents a column of the individual box in the puzzle 3x3 box area
				for (int innerColumn = 0; innerColumn < COLUMN_COUNT; innerColumn++) {

					// figure out the value to insert by identifying the specific index in the file_value array
					int value = file_values[ box_row * COLUMN_COUNT * ROW_COUNT * COLUMN_COUNT
							+ innerRow * COLUMN_COUNT * COLUMN_COUNT
							+ box_col * COLUMN_COUNT
							+ innerColumn];

					// Set the value into the BoxSet object.
					if (value != 0) m_boxSets[box_row][box_col]->setValue(innerRow, innerColumn, value);
					
				}
	file.close();
}
/*Soduko::Soduko(string a_filepath);*/



/**/
/*
		 Sudoku::SolvePuzzle  Sudoku::SolvePuzzle

	NAME
		void Sudoku::SolvePuzzle()

	SYNOPSIS
		void Sudoku::SolvePuzzle();

	DESCRIPTION
		Uses the functionality of the BoxSet class in order
		to solve the puzzle stored in memory.

	RETURN
		((void))
*/
/**/
void Sudoku::SolvePuzzle()
{
	bool progress = true;

	// Tracking the progression of the board will display when finished.
	while (progress)
	{
		progress = false;
		for (int row = 0; row < ROW_COUNT; row++)
			for (int col = 0; col < COLUMN_COUNT; col++)
			{
				progress += m_boxSets[row][col]->FindImplications();
			}
	}
	this->DisplayBoard();
}
/*void Sudoku::SolvePuzzle();*/



/**/
/*
		Sudoku::ConvertBoxToBoard	Sudoku::ConvertBoxToBoard

	NAME
		void Sudoku::ConvertBoxToBoard()

	SYNOPSIS
		void Sudoku::ConvertBoxToBoard();

	DESCRIPTION
		Converts the box set to a 9x9 soduko board.

	RETURN
		((void))
*/
/**/
void Sudoku::ConvertBoxToBoard() {
	int pos = 0;
	for (int row = 0; row < ROW_COUNT; row++)
		for (int innerRow = 0; innerRow < COLUMN_COUNT; innerRow++)
			for (int column = 0; column < COLUMN_COUNT; column++)
			{
				int temp[COLUMN_COUNT];
				m_boxSets[row][column]->getRow(innerRow, temp);
				for (int i = 0; i < COLUMN_COUNT; i++)
					m_board[pos / BOARD_WIDTH][pos++ % BOARD_WIDTH] = temp[i];

			}
				
}
/*void Sudoku::ConvertBoxToBoard();*/


/**/
/*
		Sudoku::IsUnsolved	Sudoku::IsUnsolved

	NAME
		bool Sudoku::IsUnsolved()

	SYNOPSIS
		bool Sudoku::IsUnsolved();

	DESCRIPTION
		Checks each value in the board to see if there is a 0
		within a row.

	RETURN  boolean
		true	if a 0 is found in any row on the board
		false	otherwise
*/
/**/
bool Sudoku::IsUnsolved()
{

	ConvertBoxToBoard();
	bool needBruteForce = false;
	for (int row = 0; row < BOARD_HEIGHT; row++)
		for (int col = 0; col < BOARD_WIDTH; col++)
			if (m_board[row][col] == 0)
			{
				cout << "Need to Brute Force." << endl;
				return true;
			}
	return false;
}
/*bool Sudoku::IsUnsolved();*/


/**/
/*
		Sudoku::SolveUseBruteForce	Sudoku::SolveUseBruteForce

	NAME
		void Sudoku::SolveUseBruteForce()

	SYNOPSIS
		void Sudoku::SolveUseBruteForce();

	DESCRIPTION
		Converts the boxset into a board sending it to the brute force implementation
		of the solution to Soduko Puzzles.

	RETURN 
		((void))
*/
/**/
void Sudoku::SolveUseBruteForce()
{
	ConvertBoxToBoard();
	m_brute = BruteForce(m_board);
	m_brute.BruteForce::Solve();
}
/*void Sudoku::SolveUseBruteForce();*/


/**/
/*
		
		Sudoku::DisplayBoard Sudoku::DisplayBoard
	NAME
		Sudoku::DisplayBoard()

	SYNOPSIS
		void Sudoku::DisplayBoard();

	DESCRIPTION
		Function to display the Soduko Puzzle Board to the user.

	RETURN
	((void))
*/
/**/
void Sudoku::DisplayBoard() {
	for (int row = 0; row < ROW_COUNT; row++)
		for (int innerRow = 0; innerRow < COLUMN_COUNT; innerRow++)
		{
			for (int column = 0; column < COLUMN_COUNT; column++)
			{
				m_boxSets[row][column]->PrintRow(innerRow);
			}
			cout << endl;
		}
	cout << endl;
}
/*void Sudoku::DisplayBoard();*/