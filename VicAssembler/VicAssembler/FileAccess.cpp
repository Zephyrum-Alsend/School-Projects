//
//  Implementation of file access class.
//
#include "stdafx.h"
#include "FileAccess.h"

/**/
/*
FileAccess::FileAccess() FileAccess::FileAccess()

NAME

FileAccess::FileAccess - the constructor for this class.

SYNOPSIS

FileAccess::FileAccess( int argc, char *argv[] );
argc             --> the number of command line arguments.
argv	         --> the values of command line arguments.

DESCRIPTION

This function checks that the proper command line arguments
were passed, terminating the program if not.  It then opens
the file passed and associates it with m_sfile.

RETURNS

Returns nothing.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
FileAccess::FileAccess( int argc, char *argv[] )
{
    // Check that there is exactly one run time parameter.
    if( argc != 2 ) {
        cerr << "Usage: Assem <FileName>" << endl;
        exit( 1 );
    }
    // Open the file.  One might question if this is the best place to open the file.
    // One might also question whether we need a file access class.
    m_sfile.open( argv[1], ios::in );

    // If the open failed, report the error and terminate.
    if( ! m_sfile ) {
        cerr << "Source file could not be opened, assembler terminated."
            << endl;
        exit( 1 ); 
    }
}

/**/
/*
FileAccess::~FileAccess() FileAccess::~FileAccess()

NAME

FileAccess::~FileAccess - the deconstructor for the class.

SYNOPSIS

FileAccess::~FileAccess();

DESCRIPTION

This function will close the file associated with the class object.

RETURNS

Returns nothing.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
FileAccess::~FileAccess( )
{
    // Not that necessary in that the file will be closed when the program terminates.
    m_sfile.close( );
}

/**/
/*
FileAccess::GetNextLine() FileAccess::GetNextLine()

NAME

FileAccess::GetNextLine - fetches next line from file.

SYNOPSIS

bool FileAccess::GetNextLine( string &a_buff );
a_buff           --> the string to hold the new line.

DESCRIPTION

This function first checks if the end of file has been reached,
returning false if so.  If not, getline is used to fill a_buff
with a line from file and then returns true.

RETURNS

Returns true if the fetch was successful and false if the
end of file has been reached.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
// Get the next line from the file.
bool FileAccess::GetNextLine( string &a_buff )
{
    // If there is no more data, return false.
    if( m_sfile.eof() ) {
    
        return false;
    }
    getline( m_sfile, a_buff );
    
    // Return indicating success.
    return true;
}

/**/
/*
FileAccess::rewind() FileAccess::rewind()

NAME

FileAccess::rewind - seeks to the start of the file.

SYNOPSIS

void FileAccess::rewind( );

DESCRIPTION

This function clears all flags for the file and seeks
to the beginning.

RETURNS

This function returns nothing.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
void FileAccess::rewind( )
{
    // Clean all file flags and go back to the beginning of the file.
    m_sfile.clear();
    m_sfile.seekg( 0, ios::beg );
}
    
