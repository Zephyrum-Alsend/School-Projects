// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : BruteForce.cpp	###############################


#include "BruteForce.h"


/**/
/*
		BruteForce::BruteForce BruteForce::BruteForce

	NAME
		BruteForce::BruteForce(int a_original[9][9])

	SYNOPSIS
		BruteForce::BruteForce(int a_original[9][9]);

			a_original, a 9 by 9 2D array which holds the board information.

	DESCRIPTION
		Fill the board with values from the original 9 x 9 board.
		Note : this is a 9 by 9 array, no longer a boxset.

	RETURN
		((void))
*/
/**/
BruteForce::BruteForce(int a_original[9][9])
{
	for (int row = 0; row < ROW_COUNT; row++)
		for (int col = 0; col < COLUMN_COUNT; col++)
		{
			original[row][col] = a_original[row][col];
			board[row][col] = original[row][col];
			boxSetBoard[row / 3][col / 3][row % 3][col % 3] = original[row][col];
		}
}
/*BruteForce::BruteForce(int a_original[9][9]);*/


/**/
/*
		BruteForce::Solve BruteForce::Solve

	NAME
		bool BruteForce::Solve()

	SYNOPSIS
		bool BruteForce::Solve();

	DESCRIPTION
		Calls the recursive _Solve function to accomplish the algorithm,
		then prints the board to the user if it is finished.
	
	RETURN	boolean
		true	upon finding a solution to the puzzle.
		false	otherwise
*/
/**/
bool BruteForce::Solve()
{
	if (_Solve(0, 0)) {
		cout << "Solution:\n";
		PrintBoard();
		return true;
	}
	else {
		cout << "No solution found.\n";
		return false;
	}
}
/*bool BruteForce::Solve();*/


/**/
/*
		BruteForce::SetValue BruteForce::SetValue

	NAME
		void BruteForce::SetValue(int a_row, int a_col, int a_value)

	SYNOPSIS
		void BruteForce::SetValue(int a_row, int a_col, int a_value)

			a_row, the row number that the value will be inserted
			a_col, the column number that the value will be inserted
			a_value,	the value to be inserted at [a_row][a_col]

	DESCRIPTION
		Sets the value at the specified spot in the board 2D array.

	RETURN
		((void))
*/
/**/
void BruteForce::SetValue(int a_row, int a_col, int a_value) {

	// Set value a_value at row a_row and column a_col.
	board[a_row][a_col] = a_value;
	boxSetBoard[a_row / 3][a_col / 3][a_row % 3][a_col % 3] = a_value;
}
/*void BruteForce::SetValue(int a_row, int a_col, int a_value);*/


/**/
/*
		BruteForce::UnsetValue BruteForce::UnsetValue

	NAME
		void BruteForce::UnsetValue(int a_row, int a_col)

	SYNOPSIS
		void BruteForce::UnsetValue(int a_row, int a_col)

			a_row,	specified row number that is being reset
			a_col,	specified column number that is being reset
			<together it is the position [a_row][a_col]>

	DESCRIPTION
		Resets the value to the original value at the specified
		position in the 2D board.

	RETURN
		((void))
*/
/**/
void BruteForce::UnsetValue(int a_row, int a_col) {
	// Unset whatever value was at row a_row and column a_col.
	board[a_row][a_col] = original[a_row][a_col];
	boxSetBoard[a_row / 3][a_col / 3][a_row % 3][a_col % 3] = original[a_row][a_col];
}
/*void BruteForce::UnsetValue(int a_row, int a_col);*/



/**/
/*
	BruteForce::NextPosition BruteForce::NextPosition

	NAME
		void BruteForce::NextPosition(int &a_row, int &a_col)

	SYNOPSIS
		void BruteForce::NextPosition(int &a_row, int &a_col);

			&_row,	the row that is being updated (passed by ref)
			&a_col,	the column that is being updated (passed by ref)

	DESCRIPTION
		Updates the board values to be set to the current location,
		will reset the positioning of column if it reaches 9, then increase
		the row accordingly.

	RETURN
		((void))
*/
/**/
void BruteForce::NextPosition(int &a_row, int &a_col) {
	
	// Move to the next position on the board.
	a_col++;
	if (a_col == 9)
	{
		a_col = 0;
		a_row++;
	}
}
/*void BruteForce::NextPosition(int &a_row, int &a_col);*/


/**/
/*
	BruteForce::PreviousPosition BruteForce::PreviousPosition

	NAME
		void BruteForce::PreviousPosition(int &a_row, int &a_col)

	SYNOPSIS
		void BruteForce::PreviousPosition(int &a_row, int &a_col);

			&_row,	the row that is being updated (passed by ref)
			&a_col,	the column that is being updated (passed by ref)

	DESCRIPTION
		Updates the board values to be set to the previous location on the board
		decreasing the values of a_col and a_row accordingly.

	RETURN
		((void))
*/
/**/
void BruteForce::PreviousPosition(int &a_row, int &a_col)
{// Move to the previous position on the board.
	a_col--;
	if (a_col < 0)
	{
		a_col = 8;
		a_row--;
	}
}
/*void BruteForce::PreviousPosition(int &a_row, int &a_col);*/


/**/
/*
	BruteForce::isValid BruteForce::isValid

	NAME
		bool BruteForce::isValid(int a_row, int a_col, int a_value)

	SYNOPSIS
		bool BruteForce::isValid(int a_row, int a_col, int a_value);

			a_row, row being checked for the corresponding value
			a_col, column being checked for the corresponding value
			a_value, the value being validated.

	DESCRIPTION
		Checks the value being entered against the basic Soduko rules.
			(1) Value cannot exist in the column or row already
			(2) Value cannot exist in the current boxset (3 x 3)

	RETURN	boolean
		true, if the value can be inserted.
		false, if anything conflicts with the rules (the value exists)
*/
/**/
bool BruteForce::isValid(int a_row, int a_col, int a_value)
{
	// (1) Not already in that row.
	for (int col = 0; col < 9; col++)
	{
		if (a_value == board[a_row][col])
			return false;
	}
	// (2) Not already in that column.
	for (int row = 0; row < 9; row++)
	{
		if (a_value == board[row][a_col])
			return false;
	}
	// (3) Not already in that boxSet.
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (a_value == boxSetBoard[a_row / 3][a_col / 3][row][col])
				return false;
		}
	}
	// No conflicts, indicate that the move is valid.
	return true;
}
/*bool BruteForce::isValid(int a_row, int a_col, int a_value)*/


/**/
/*
		BruteForce::_Solve BruteForce::_Solve

	NAME
		bool BruteForce::_Solve(int a_row, int a_col)

	SYNOPSIS
		bool BruteForce::_Solve(int a_row, int a_col);
		
			a_row, the current row location
			a_col, the current column location
		
		Note: this is of a 9x9 2D array

	DESCRIPTION

	RETURN	boolean
		true, if the puzzle was solved
		false, if there were any conflicts with values or no solution.
*/
/**/
bool BruteForce::_Solve(int a_row, int a_col)
{
	if (0 != original[a_row][a_col]){ 
		// Set as original value.
		SetValue(a_row, a_col, original[a_row][a_col]);
		int tRow = a_row,
			tCol = a_col;
		NextPosition(tRow, tCol);

		//Solved! Pass it on.
		if (!(tRow < 9)) return true;

		if (false == _Solve(tRow, tCol))
		{// Next box said value was bad, undo. Pass it on.
			UnsetValue(a_row, a_col);
			return false;
		}
		else
		{// Next box said value was good, solved. Pass it on.
			return true;
		}
	}
	else
	{
		// Find a valid value.
		for (int i = 1; i <= 9; i++)
		{
			if (true == isValid(a_row, a_col, i))
			{
				SetValue(a_row, a_col, i);
				int tRow = a_row,
					tCol = a_col;
				NextPosition(tRow, tCol);
				if (!(tRow < 9))
				{// Solved! Pass it on.
					return true;
				}
				if (false == _Solve(tRow, tCol))
				{// Next box said value was bad, continue to the next value.
					UnsetValue(a_row, a_col);
					continue;
				}
				else
				{// Next box said value was good, solved. Pass it on.
					return true;
				}
			}
		}
		// Unable to find a valid value, tell previous box its value was bad.
		UnsetValue(a_row, a_col);
		return false;
	}
}
/*bool BruteForce::_Solve(int a_row, int a_col);*/


/**/
/*
		BruteForce::PrintBoard BruteForce::PrintBoard

	NAME
		void BruteForce::PrintBoard()

	SYNOPSIS
		void BruteForce::PrintBoard();

	DESCRIPTION
		Displays the board to the user.

	RETURN
		((void))
*/
/**/
void BruteForce::PrintBoard()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int col = 0; col < COLUMN_COUNT; col++)
			cout << board[row][col] << ' ';
		cout << endl;
	}
}
/*void BruteForce::PrintBoard();*/