#include "stdafx.h"
#include "Emulator.h"
#include "Errors.h"

/**/
/*
emulator::insertMemory() emulator::insertMemory()

NAME

emulator::insertMemory - inserts a value into VC3600's memory.

SYNOPSIS

bool emulator::insertMemory(int a_location, int a_contents);
a_location       --> the location within system memory.
a_contents       --> the value to place into memory.

DESCRIPTION

This function checks if a_location is within the bounds of system
memory before inserting a_contents into the place a_location
specifies.  If a_location is out of bounds, it returns false.  This
function does not check if a_contents is valid, foisting that 
responsibility onto the code calling this function.

RETURNS

Returns false if there is no more memory remaining, otherwise true.

AUTHOR

Lucas Crockett

DATE

2:24am 5/8/2017

*/
/**/
bool emulator::insertMemory(int a_location, int a_contents) { 
	
	if (a_location > 9999) return false;

	m_memory[a_location] = a_contents;
	return true;
}

/**/
/*
emulator::runProgram() emulator::runProgram()

NAME

emulator::runProgram - processes new opens for this model.

SYNOPSIS

bool emulator::runProgram();

DESCRIPTION

This function first checks if Assembler::PassII() detected any errors,
returning false if true.  If no errors were reported, then this function
starts reading from m_memory and executing the instructions with a Switch
table.  Once a HALT instruction is found, this function returns true.
If no HALT was encountered by the time it reads the end of memory or a 
branch points to a negative address, an error message is logged and false 
is returned.

RETURNS

Returns true if a HALT statement was read, false if it reads beyond system
memory or if Assembler::PassII() detected an error.

AUTHOR

Lucas Crockett

DATE

2:24am 5/8/2017

*/
/**/
bool emulator::runProgram() { 
	
	cout << endl;
	system("pause");
	cout << endl;

	if (notSafeToRun) {

		string err = "The emulator was not run due to the presence of errors.";
		Errors::RecordError(err);
		return false;
	}

	cout << "Emulator:" << endl;

	int content;
	int OpCode;
	int addr;
	string input;

	for (int i = 0; -1 < i && i < 10000; i++) {

		//Read in the word.
		content = m_memory[i];
		OpCode = content / 10000;
		addr = content % 10000;


		//Parse and execute the contents.
		switch (OpCode) {
		
		//ADD
		case 1:
			accumulator += m_memory[addr];
			accumulator %= 1000000;
			continue;

		//SUB
		case 2:
			accumulator -= m_memory[addr];
			accumulator %= 1000000;
			continue;

		//MULT
		case 3:
			accumulator *= m_memory[addr];
			accumulator %= 1000000;
			continue;

		//DIV
		case 4:
			accumulator /= m_memory[addr];
			accumulator %= 1000000;
			continue;

		//LOAD
		case 5:
			accumulator = m_memory[addr];
			continue;

		//STORE
		case 6:
			m_memory[addr] = accumulator;
			continue;

		//READ
		case 7:
			cout << "? ";
			cin >> input;
			m_memory[addr] = stoi(input.substr(0, 6));
			continue;

		//WRITE
		case 8:
			cout << m_memory[addr] << endl;
			continue;

		//BRANCH
		case 9:
			i = addr-1;
			continue;

		//BRANCH MINUS
		case 10:
			if (accumulator < 0) i = addr-1;
			continue;

		//BRANCH ZERO
		case 11:
			if (accumulator == 0) i = addr-1;
			continue;

		//BRANCH PLUS
		case 12:
			if (accumulator > 0) i = addr-1;
			continue;

		//HALT
		case 13:
			cout << "End of Emulation." << endl;
			return true;

		}

	}

	//If the emulator never encounters a HALT statement, it will reach here.
	string err = "Err: Segmentation fault. Check for missing HALT statement.";
	Errors::RecordError(err);
	return false;
}