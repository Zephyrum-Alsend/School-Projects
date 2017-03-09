// Project Group Members :
//					Amanda Steidl
//					Kyle Stanski
//					Lucas Crocket

// Course :		Analysis of Algorithms
// Professor :	D'Antonio
// Project	:	Final - Soduko Algorithm
// Due Date :	December 28, 2016

//########################		CURRENT FILE : BoxSet.cpp	###############################

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>


#define ROW_COUNT 3
#define COLUMN_COUNT 3
#define POSSIBILITY_COUNT ROW_COUNT*COLUMN_COUNT

using namespace std;

class BoxSet {
public:
	
	//################## CONSTRUCTORS ###################
	BoxSet(int row, int col);

	//################## DESTRUCTORS ####################
	~BoxSet() {};

	//##################	GETTERS		#################
	BoxSet* getFirstRowNeighbor()	{	return m_rowNeighbors[0];	}
	BoxSet* getSecondRowNeighbor()	{	return m_rowNeighbors[1];	}
	BoxSet* getFirstColNeighbor()	{	return m_columnNeighbors[0];	}
	BoxSet* getSecondColNeighbor()	{	return m_columnNeighbors[1];	}
	void getRow(int a_row, int target[3])
	{
		for(int i = 0; i < COLUMN_COUNT; i++)
			target[i] = m_box[a_row][i];
	}

	//##################	SETTERS		#################

	// Sets the current boxes neighbors (if they exist, else null)
	void setNeighbors(BoxSet* a_rowNeighbor1, BoxSet* a_rowNeighbor2, BoxSet* a_columnNeighbor1, BoxSet* a_columnNeighbor2) {
		m_rowNeighbors[0] = a_rowNeighbor1;
		m_rowNeighbors[1] = a_rowNeighbor2;
		m_columnNeighbors[0] = a_columnNeighbor1;
		m_columnNeighbors[1] = a_columnNeighbor2;
	}
	void setValue(int a_row, int a_col, int a_value); // Sets value and updates the implications

	//################## PUBLIC FUNCTIONS ###############
	bool FindImplications();
	void PrintRow(int a_row)
	{
		for (int i = 0; i < COLUMN_COUNT; i++)
		{
			cout << m_box[a_row][i] << ' ';
		}
	}

	

private:
	//################## MEMBER VARIABLES ###################
	const int m_originRow,
		m_originColumn; // Holds the positioning of the box in the set, [0][0] is the upper left
	
	std::vector<int> m_boxContent;
	int m_box[ROW_COUNT][COLUMN_COUNT] = { 0 };

	bool m_RowHasBeenTold[ROW_COUNT][POSSIBILITY_COUNT];
	bool m_ColumnHasBeenTold[COLUMN_COUNT][POSSIBILITY_COUNT];

	int m_RowHasImplied[POSSIBILITY_COUNT];
	int m_ColumnHasImplied[POSSIBILITY_COUNT];

	int m_possibleValues[ROW_COUNT][COLUMN_COUNT][POSSIBILITY_COUNT]; // Possible values within a single boxset

	BoxSet* m_rowNeighbors[2]; // Holds the immediate row neighbors to the current boxset [if they exist]
	BoxSet* m_columnNeighbors[2]; // Holds the immediate column neighbors to the current boxset [if they exist]

	int m_setCount = 0;


	//################## MEMBER FUNCTIONS ###################
	bool isBoxSet(int a_row, int a_col);
	void ImplyToRows(int a_row, int a_value);
	void ImplyColumns(int a_col, int a_value);

	//################## IMPLICATION FUNCTIONS ###############
	void TellRowImplications(int a_row, int a_value);
	void TellColumnImplications(int a_col, int a_value);
};