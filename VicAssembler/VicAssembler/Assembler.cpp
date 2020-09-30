//
//      Implementation of the Assembler class.
//
#include "stdafx.h"
#include "Assembler.h"
#include "Errors.h"
#include <iomanip>

/**/
/*
Assembler::Assembler() Assembler::Assembler()

NAME

Assembler::Assembler - constructor for the Assembler class.

SYNOPSIS

Assembler::Assembler( int argc, char *argv[] );
argc             --> the number of command line arguments.
argv	         --> the values of command line arguments.

DESCRIPTION

This function passes the command line arguments into the FileAccess
object for its constructor.

RETURNS

Returns nothing.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
Assembler::Assembler( int argc, char *argv[] )
: m_facc( argc, argv )
{ }

/**/
/*
Assembler::PassI() Assembler::PassI()

NAME

Assembler::PassI - establishes the symbol table.

SYNOPSIS

void Assembler::PassI( );

DESCRIPTION

This function retrieves a line from the FileAccess object
and passes it into Instruction::ParseInstruction().  If the
returned type is ST_AssemblerInstr or ST_MachineLanguage,
it checks for a label and if present, records the location-
label pair into the symbol table.  
Instruction::LocationNextInstruction() is called to update 
the virtual location for the next line.  The function
returns early if an ST_END is returned from
Instruction::ParseInstruction();.

RETURNS

Returns nothing.

AUTHOR

Victor Miller

DATE

2:24am 5/8/2017

*/
/**/
void Assembler::PassI( ) 
{
    int loc = 0;        // Tracks the location of the instructions to be generated.

    // Successively process each line of source code.
    for( ; ; ) {

        // Read the next line from the source file.
        string buff; 
        if( ! m_facc.GetNextLine( buff ) ) {

            // If there are no more lines, we are missing an end statement.
            // We will let this error be reported by Pass II.
            return;
        }

        // Parse the line and get the instruction type.
        Instruction::InstructionType st =  m_inst.ParseInstruction( buff );

        // If this is an end statement, there is nothing left to do in pass I.
        // Pass II will determine if the end is the last statement.
        if( st == Instruction::ST_End ) return;

        // Labels can only be on machine language and assembler language
        // instructions.  So, skip other instruction types.
        if( st != Instruction::ST_MachineLanguage && st != Instruction::ST_AssemblerInstr ) 
        {
        	continue;
	  }
        // If the instruction has a label, record it and its location in the
        // symbol table.
        if( m_inst.isLabel( ) ) {

            m_symtab.AddSymbol( m_inst.GetLabel( ), loc );
        }
        // Compute the location of the next instruction.
        loc = m_inst.LocationNextInstruction( loc );
    }
}

/**/
/*
Assembler::PassII() Assembler::PassII()

NAME

Assembler::PassII - translates assembly file into machine code.

SYNOPSIS

Assembler::PassII();

DESCRIPTION

This function reads the assembly code file line by line, calling
Instruction::ParseInstruction() to extract the details of each line.
Using the data extracted, this function then checks for further 
errors ParseInstruction cannot catch and reports on them.  If no
errors were found it calls emulator::insertMemory() to add the 
translated line to VC3600's system memory.  Once an END statement
has been encountered it stops calling emulator::insertMemory(). 
As this function reads each line, it also prints the line to console 
and errors found within said line.

RETURNS

Returns nothing.

AUTHOR

Lucas Crockett

DATE

1:46am 5/9/2017

*/
/**/
void Assembler::PassII() {

	int loc = 0;        // Tracks the location of the instructions to be generated.
	//Initialize the error log and reset the file.
	Errors::InitErrorReporting();
	m_facc.rewind();
	//Variables for error tracking and reporting.
	bool isEnd = false;
	bool hasOrg = false;
	bool OrgErrStated = false;

	//List of OpCodes that accept a label as an operand.
	string OperandCodes[12] = { "ADD", "SUB", "MULT", "DIV", "LOAD", "STORE",
		"READ", "WRITE", "B", "BM", "BZ", "BP" };
	bool acceptLabel;
	//Variables to contain information about the parsed line.
	string Label, OpCode, Operand;
	int NumOp, OperandVal;


	//Header for output
	cout << "Code Translation:\nLoc\t|Content|\tOriginal Line\n";


	// Successively process each line of source code.
	for (; ; ) {

		acceptLabel = false;
		NumOp = 0;
		OperandVal = 0;

		// Read the next line from the source file.
		string buff;
		if (!m_facc.GetNextLine(buff)) {

			if (isEnd) {

				return;
			}

			else {

				string err = "Err: Missing END statement.";
				Errors::RecordError(err);
				Errors::DisplayErrors();
				return;
			}

		}

		//Parse the line for information.
		Instruction::InstructionType st = m_inst.ParseInstruction(buff);


		if (st == Instruction::ST_End) { 

			if (isEnd) {

				string err = "Wrn: Extra END statement. Code after first was not translated.";
				Errors::RecordError(err);
			}

			isEnd = true; 
		}

		//If it is a comment or END has already been declared, there is nothing to translate.
		if ((st != Instruction::ST_MachineLanguage && st != Instruction::ST_AssemblerInstr)
			|| isEnd) {

			cout << "\t|\t|" << buff << endl;
			Errors::DisplayErrors();
			continue;
		}

		OpCode = m_inst.getOpCode();
		if (OpCode.empty()) {

			//Without an OpCode, the line cannot be translated.
			isErr = true;
			continue;
		}


		//Check if the OpCode accepts a label as Operand so we can narrow options.
		for (int i = 0; i < 12; i++) {

			if (OpCode == OperandCodes[i]) {

				acceptLabel = true;
				break;
			}

		}



		//Branch A: no labels allowed
		if (!acceptLabel) {

			//Case 1: ORG
			if (OpCode == "ORG") {

				hasOrg = true;
				
				if (! m_inst.getIsNumOperand()) {

					//Without a proper Operand, ORG cannot be set.
					isErr = true;
					continue; //loc is left as 0.
				}
				
				OperandVal = m_inst.getOperandVal();
				for (int i = 0; i < OperandVal; i++) {

					if (!isEnd && !m_emul.insertMemory(loc, 000000)) {

						isErr = true;
						string err = "Err: System memory exceeded.";
						Errors::RecordError(err);
					}

				}

				OperandVal = 0; //For when the translation is displayed.
			}

			//Case 2: DC
			else if (OpCode == "DC") {

				if (!m_inst.getIsNumOperand()) {

					//Without a proper Operand, DC cannot be set.
					isErr = true;
					if (m_inst.isLabel()) {
						if (!isEnd && !m_emul.insertMemory(loc, 000000)) {

							isErr = true;
							string err = "Err: System memory exceeded.";
							Errors::RecordError(err);
						}

					}

					else {

						string err = "Err: DC requires a label.";
						Errors::RecordError(err);
					}

				}

				else {

					OperandVal = m_inst.getOperandVal();
					if (m_inst.isLabel() && OperandVal < 1000000 && OperandVal > -1000000) {

						if (!isEnd && !m_emul.insertMemory(loc, OperandVal)) {

							isErr = true;
							string err = "Err: System memory exceeded.";
							Errors::RecordError(err);
						}

					}

					else {

						isErr = true;
						string err = "Err: DC requires a label.";
						Errors::RecordError(err);
					}

				}

			}
	
			//Case 3: DS
			else if (OpCode == "DS") {

				if (! m_inst.getIsNumOperand()) {

					//Without a proper Operand, DS cannot be set.
					isErr = true;
					continue; //loc is left as it is.
				}

				OperandVal = m_inst.getOperandVal();
				for (int i = 0; i < OperandVal; i++) {

					if (!isEnd && !m_emul.insertMemory(loc, 000000)) {

						isErr = true;
						string err = "Err: System memory exceeded.";
						Errors::RecordError(err);
						break;
					}

				}

			}

			//Case 4: HALT
			else if (OpCode == "HALT") {

				NumOp = 13;
				if (!isEnd && !m_emul.insertMemory(loc, 130000)) {

					isErr = true;
					string err = "Err: System memory exceeded.";
					Errors::RecordError(err);
				}

			}

			//Case 5: Err
			else {

				isErr = true;
			}

		}










		//Branch B: labels. labels everywhere.
		//If NumOp were NULL, it would never enter this branch.
		else {

			//Must be machine code so we can shortcut the translation.
			NumOp = m_inst.getNumOp();
			Operand = m_inst.getOperand();
			if (Operand.empty()) {

				//Without a valid Operand, the line cannot be translated.
				isErr = true;
			}

			else {

				if(m_inst.getIsNumOperand()){

					OperandVal = m_inst.getOperandVal();
					if(OperandVal < 10000 && OperandVal > -1)
						if (!isEnd && !m_emul.insertMemory(loc, NumOp * 10000 + OperandVal)) {

							isErr = true;
							string err = "Err: System memory exceeded.";
							Errors::RecordError(err);
						}

					else {

						isErr = true;
						string err = "Err: Operand is outside legal bounds.";
						Errors::RecordError(err);
					}

				}

				else{

					if(m_symtab.LookupSymbol(Operand, OperandVal)){

						if(OperandVal < 10000 && OperandVal > -1){

							if (!isEnd && !m_emul.insertMemory(loc, NumOp * 10000 + OperandVal)) {

								isErr = true;
								string err = "Err: System memory exceeded.";
								Errors::RecordError(err);
							}

						}

						else {

							isErr = true;
							if (OperandVal = SymbolTable::multiplyDefinedSymbol) {

								string err = "Err: label is multiply defined.";
								Errors::RecordError(err);
							}

							else {

								string err = "Err: Operand is outside legal bounds.";
								Errors::RecordError(err);
							}

						}

					}

					else {

						isErr = true;
						string err = "Err: label does not exist.";
						Errors::RecordError(err);
					}

				}

			}

		}

		//This will only be entered once if ORG is not defined.
		if (!hasOrg && !OrgErrStated) {

			isErr = true;
			OrgErrStated = true;
			string err = "Err: ORG not defined.";
			Errors::RecordError(err);
		}

		//Prints out loc, contents and original line in columns then displays errors accrued.
		cout << loc << "\t|" << setfill('0') << setw(6) << NumOp*10000 + OperandVal 
			<< "\t|" << buff << endl;
		Errors::DisplayErrors();

		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);
	}
}

/**/
/*
Assembler::RunEmulator() Assembler::RunEmulator()

NAME

Assembler::RunEmulator - initiates emulator object.

SYNOPSIS

void Assembler::RunEmulator();

DESCRIPTION

This function calls Emulator::isSafeToRun() to report the
presence of errors.  Then Emulator::runProgram() is called
and waited upon for a return.  If it returns false, this 
function reports the error recorded.  If true is returned, 
this function does nothing else.

RETURNS

Returns nothing.

AUTHOR

Lucas Crockett

DATE

4:12pm 5/6/2017

*/
/**/
void Assembler::RunEmulator() {

	m_emul.isSafeToRun(isErr);
	if (!m_emul.runProgram()) {

		Errors::DisplayErrors();
	}

}

