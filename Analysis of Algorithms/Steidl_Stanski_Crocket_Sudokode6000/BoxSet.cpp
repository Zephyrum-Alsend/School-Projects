// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : BoxSet.cpp	###############################

#include "BoxSet.h"

#define TALK false
#define IFTALK if(TALK)


/**/
/*
	BoxSet::BoxSet BoxSet::BoxSet

	NAME
		BoxSet::BoxSet(int a_row, int a_col)

	SYNOPSIS
		BoxSet::BoxSet(int a_row, int a_col);

	DESCRIPTION
		Class constructor for BoxSet which tells where each box will
		be within the board (originRow/Col). Treating the board as if
		it were a set of 3x3 boxes of 3x3 row/col within.

	RETURN
	((void))
*/
/**/
BoxSet::BoxSet(int a_row, int a_col)
	: m_originRow(a_row)
	, m_originColumn(a_col)
{

	// Figuring out what the possibility of values within the box is. [3x3 box with 9 possible values if empty]
	for (int row = 0; row < ROW_COUNT; row++)
		for (int column = 0; column < COLUMN_COUNT; column++)
			for (int i = 0; i < POSSIBILITY_COUNT; i++)
				m_possibleValues[row][column][i] = i + 1;
}
/*BoxSet::BoxSet(int a_row, int a_col);*/


/**/
/*
	 BoxSet::ImplyToRows  BoxSet::ImplyToRows

	NAME
		void BoxSet::ImplyToRows(int a_row, int a_value)

	SYNOPSIS
		void BoxSet::ImplyToRows(int a_row, int a_value);

			a_row,	the integer value of the row that has been altered. (value added)
			a_value, the integer value of the digit being added to implications.

	DESCRIPTION
		Function is supposed to tell the neighboring boxes (ROW) which value 
		is no longer allowed in their corresponding rows.

	RETURN
		((void))
*/
/**/
void BoxSet::ImplyToRows(int a_row, int a_value)
{// Imply to adjacent m_boxSets that they can't have a_value in their a_row row.
	IFTALK cout << " -> " << a_value + 1 << " @row " << a_row + m_originRow * 3 << endl;
	m_rowNeighbors[0]->TellRowImplications(a_row, a_value);
	m_rowNeighbors[1]->TellRowImplications(a_row, a_value);
}
/*void BoxSet::ImplyToRows(int a_row, int a_value)*/

/**/
/*
		BoxSet::TellRowImplications BoxSet::TellRowImplications

	NAME
		void BoxSet::TellRowImplications(int a_row, int a_value)

	SYNOPSIS
		void BoxSet::TellRowImplications(int a_row, int a_value);

			a_row		integer value of the box's row (1 - 3)
			a_value		integer of the value trying to be entered into the row.

	DESCRIPTION
		Updates the current box at hand to the values it is not
		allowed to have within the row, based upon changes within
		other boxes.
*/
/**/
void BoxSet::TellRowImplications(int a_row, int a_value) {

	// Tell this box set it can't have a_value in its a_row.
	if (false == m_RowHasBeenTold[a_row][a_value]) {
		m_RowHasBeenTold[a_row][a_value] = true;
		for (int col = 0; col < COLUMN_COUNT; col++)
			m_possibleValues[a_row][col][a_value] = 0;
	}
}
/*void BoxSet::TellRowImplications(int a_row, int a_value);*/


/**/
/*
			BoxSet::ImplyColumns BoxSet::ImplyColumns

		NAME
			void BoxSet::ImplyColumns(int a_col, int a_value)

		SYNOPSIS
			void BoxSet::ImplyColumns(int a_col, int a_value);

				a_col,	the integer value of the column that has been altered. (value added)
				a_value, the integer value of the digit being added to implications.

		DESCRIPTION
		Function is supposed to tell the neighboring boxes (COLUMNS) which value
		is no longer allowed in their corresponding rows.

		RETURN
		((void))
*/
/**/
void BoxSet::ImplyColumns(int a_col, int a_value) {
	
	// Imply to adjacent m_boxSets that they can't have a_value in their a_col column.
	IFTALK cout << " -> " << a_value + 1 << " @column " << a_col + m_originColumn * 3 << endl;
	m_columnNeighbors[0]->TellColumnImplications(a_col, a_value);
	m_columnNeighbors[1]->TellColumnImplications(a_col, a_value);
}
/*void BoxSet::ImplyColumns(int a_col, int a_value);*/


/**/
/*
		BoxSet::TellColumnImplications BoxSet::TellColumnImplications

	NAME
		void BoxSet::TellColumnImplications(int a_col, int a_value)

	SYNOPSIS
		void BoxSet::TellColumnImplications(int a_col, int a_value);

			a_col		integer value of the box's row (1 - 3)
			a_value		integer of the value trying to be entered into the row.

	DESCRIPTION
		Updates the current box at hand to the values it is not
		allowed to have within the column, based upon changes within
		other boxes.
*/
/**/
void BoxSet::TellColumnImplications(int a_col, int a_value) {
	
	// Tell this box set it can't have a_value in its a_col.
	if (false == m_ColumnHasBeenTold[a_col][a_value])
	{
		m_ColumnHasBeenTold[a_col][a_value] = true;
		for (int row = 0; row < ROW_COUNT; row++)
			m_possibleValues[row][a_col][a_value] = 0;
	}
}
/*void BoxSet::TellColumnImplications(int a_col, int a_value);*/


/**/
/*
		 BoxSet::FindImplications	 BoxSet::FindImplications

	NAME
		bool BoxSet::FindImplications()

	SYNOPSIS
		bool BoxSet::FindImplications();

	DESCRIPTION
		The brains behind the algorithm using the implication functions, this will find
		all the possibilities of rows, then columns and find if there are any obvious answers
		to the value, or parse through the values allowed between boxes.

	RETURN	boolean
		true if an implication was made
		false otherwise.
*/
/**/
bool BoxSet::FindImplications()
{
	int rowImp[9];
	int colImp[9];
	int rowVals[ROW_COUNT][9];
	int colVals[COLUMN_COUNT][9];

	for (int i = 0; i < POSSIBILITY_COUNT; i++)
	{
		// Find row XOR:
		for (int row = 0; row < ROW_COUNT; row++)
		{
			rowVals[row][i] =
				m_possibleValues[row][0][i]
				+ m_possibleValues[row][1][i]
				+ m_possibleValues[row][2][i];
		}
		bool row_1 = rowVals[0][i] ? true : false;
		bool row_2 = rowVals[1][i] ? true : false;
		bool row_3 = rowVals[2][i] ? true : false;
		if ( // Ternary XOR:
			(!row_1 && (row_2 ^ row_3))
			|| (row_1 && !(row_2 || row_3)))
		{
			if (row_1 > row_2)
				rowImp[i] = 1;
			else if (row_2 > row_3)
				rowImp[i] = 2;
			else
				rowImp[i] = 3;
		}
		else
			rowImp[i] = false;

		// Find column XOR:
		for (int col = 0; col < COLUMN_COUNT; col++)
		{
			colVals[col][i] =
				m_possibleValues[0][col][i]
				+ m_possibleValues[1][col][i]
				+ m_possibleValues[2][col][i];
		}
		bool col_1 = colVals[0][i] ? true : false;
		bool col_2 = colVals[1][i] ? true : false;
		bool col_3 = colVals[2][i] ? true : false;
		if ( // Ternary XOR:
			(!col_1 && (col_2 ^ col_3))
			|| (col_1 && !(col_2 || col_3)))
		{
			if (col_1 > col_2)
				colImp[i] = 1;
			else if (col_2 > col_3)
				colImp[i] = 2;
			else
				colImp[i] = 3;
		}
		else
			colImp[i] = false;
	}

	// Make any implications.
	bool implicationMade = false;
	for (int i = 0; i < POSSIBILITY_COUNT; i++)
	{
		if (!m_RowHasImplied[i] && rowImp[i]) {

			// Make the implication for value i at row rowImp[i]-1
			m_RowHasImplied[i] = rowImp[i];
			ImplyToRows(m_RowHasImplied[i] - 1, i);
			implicationMade = true;

			// Remove a_value from all other rows' boxes' possibilities in the boxSet.
			int c = m_RowHasImplied[i] - 1;
			TellRowImplications((c + 1) % ROW_COUNT, i);
			TellRowImplications((c + 2) % ROW_COUNT, i);
		}
		if (!m_ColumnHasImplied[i] && colImp[i]) {

			// Make the implication for value i at column colImp[i]-1
			m_ColumnHasImplied[i] = colImp[i];
			ImplyColumns(m_ColumnHasImplied[i] - 1, i);
			implicationMade = true;

			// Remove a_value from all other columns' boxes' possibilities in the boxSet.
			int c = m_ColumnHasImplied[i] - 1;
			TellColumnImplications((c + 1) % COLUMN_COUNT, i);
			TellColumnImplications((c + 2) % COLUMN_COUNT, i);
		}
		if ((m_RowHasImplied[i] && colImp[i]) 
			|| (rowImp[i] && m_ColumnHasImplied[i])) {

			// We know where this value goes. Apply it.
			setValue(m_RowHasImplied[i] - 1, m_ColumnHasImplied[i] - 1, i + 1);
		}
	}
	return implicationMade;
}
/*bool BoxSet::FindImplications();*/


/**/
/*
	BoxSet::FindImplications	 BoxSet::FindImplications

	NAME
		void BoxSet::setValue(int a_row, int a_col, int a_value)

	SYNOPSIS
		void BoxSet::setValue(int a_row, int a_col, int a_value);

			a_row,	integer value of the row the value is going to be inserted
			a_col,	integer value of the column the value is going to be inserted
			a_val,	the value to be inserted at the specified position

	DESCRIPTION
		Inserts a new value at a location within the box, will then update the implications
		for itself as well as the row/columns surrounding it.

	RETURN
		((void))
*/
/**/
void BoxSet::setValue(int a_row, int a_col, int a_value)
{
	IFTALK cout << "Set " << a_value << " at (" << m_originRow*3+a_row << ',' << m_originColumn*3+a_col << ')' << endl;
	// Set the value and imply in both directions.
	m_box[a_row][a_col] = a_value;
	ImplyToRows(a_row, a_value - 1);
	ImplyColumns(a_col, a_value - 1);

	// Remove a_value from all boxes's possibilities in the boxSet.
	for(int row = 0; row < ROW_COUNT; row++)
		for (int col = 0; col < COLUMN_COUNT; col++)
			m_possibleValues[row][col][a_value - 1] = false;

	// Remove all possibilities from the box we are setting.
	for (int i = 0; i < POSSIBILITY_COUNT; i++)
		m_possibleValues[a_row][a_col][i] = false;

	m_possibleValues[a_row][a_col][a_value - 1] = a_value;

	m_setCount++;
}
/*void BoxSet::setValue(int a_row, int a_col, int a_value);*/



/**/
/*
		BoxSet::isBoxSet	 BoxSet::isBoxSet

	NAME
		bool BoxSet::isBoxSet(int a_row, int a_col)

	SYNOPSIS
		bool BoxSet::isBoxSet(int a_row, int a_col);

			a_row, the integer value of the row the box is currently located in
			a_col, the integer value of the column the box is currently located in

	DESCRIPTION
		Determines if the box is appropriately set to the 
		specific column and row.

	RETURN	boolean
		true,	upon a box being set in the row, col location
		false,	otherwise
*/
/**/
bool BoxSet::isBoxSet(int a_row, int a_col)
{
	if (m_originRow == a_row && m_originColumn == a_col)
		return true;
	else
		return false;
}
/*bool BoxSet::isBoxSet(int a_row, int a_col);*/
