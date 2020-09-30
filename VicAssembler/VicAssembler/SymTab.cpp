//
//		Implementation of the symbol table class.
//
#include "stdafx.h"
#include "SymTab.h"

/**/
/*
SymbolTable::AddSymbol() SymbolTable::AddSymbol()

NAME

SymbolTable::AddSymbol - logs a symbol in the symbol table.

SYNOPSIS

void SymbolTable::AddSymbol( string &a_symbol, int a_loc );
a_symbol         --> the symbol name to be logged.
a_loc            --> the location that the symbol is found at.

DESCRIPTION

This functions checks if a_symbol already exists in m_symbolTable.
If not found, it adds the location-label pairing of a_symbol and
a_loc to m_symbolTable.  If it is found, a_symbol's value in
m_symbolTable is changed to the const value multiplyDefinedSymbol,
defined in the .h file for this class.

RETURNS

This function returns nothing.

AUTHOR

Lucas Crockett

DATE

5:42am 4/24/2017

*/
/**/
void SymbolTable::AddSymbol( string &a_symbol, int a_loc ) {

    // If the symbol is already in the symbol table, record it as multiply defined.
    map<string, int>::iterator st;
    st = m_symbolTable.find( a_symbol );
    if( st != m_symbolTable.end() ) 
	{
        st->second = multiplyDefinedSymbol;
        return;
    }
    // Record a the  location in the symbol table.
    m_symbolTable[a_symbol] = a_loc;
}

/**/
/*
SymbolTable::DisplaySymbolTable() SymbolTable::DisplaySymbolTable()

NAME

SymbolTable::DisplaySymbolTable - outputs symbol table to terminal.

SYNOPSIS

void SymbolTable::DisplaySymbolTable();
This function takes no arguments.

DESCRIPTION

This function prints all location-label pairings in m_symbolTable
to the console in a table format.  Due to m_symbolTable being a 
map, its contents are printed in alphabetical order.

RETURNS

This function returns nothing.

AUTHOR

Lucas Crockett

DATE

6:02am 4/24/2017

*/
/**/
void SymbolTable::DisplaySymbolTable() {

	map<string, int>::iterator st;
	cout << "\nSymbol Table:\nSymbol#\t|Symbol\t|Address\n";
	int i = 0;
	for (st = m_symbolTable.begin(); st != m_symbolTable.end(); st++) {

		cout << i << "\t|" << st->first << "\t|" << st->second << endl;
		i++;
	}

	cout << endl;
	system("pause");
	cout << endl;
}

/**/
/*
SymbolTable::LookupSymbol() SymbolTable::LookupSymbol()

NAME

SymbolTable::LookupSymbol - finds a given label in the symbol table.

SYNOPSIS

bool LookupSymbol( string &a_symbol, int &a_loc );
a_symbol         --> the symbol name to be found.
a_loc            --> for holding the location that the symbol is found at.

DESCRIPTION

This function looks up a_symbol in m_symbolTable and places its paired
value into a_loc, returning true.  If a_symbol is not found in the map,
this function returns false.

RETURNS

Returns true if the symbol was found in the symbol table and false
if not.  One of these two cases will always occur.

AUTHOR

Lucas Crockett

DATE

6:07am 4/24/2017

*/
/**/
bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc) {

	map<string, int>::iterator st;
	st = m_symbolTable.find(a_symbol);
	if (st != m_symbolTable.end()) 
	{
		a_loc = st->second;
		return true;
	}
	return false;
}