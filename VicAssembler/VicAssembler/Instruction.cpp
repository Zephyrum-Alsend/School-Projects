//
//		Implementation of Instruction class
//
#include "stdafx.h"
#include "Instruction.h"
#include "Errors.h"

/**/
/*
Instruction::ParseInstruction() Instruction::ParseInstruction()

NAME

Instruction::ParseInstruction - parses given line of code.

SYNOPSIS

Instruction::InstructionType Instruction::ParseInstruction( string &a_buff );
a_buff           --> the line of code to be parsed.

DESCRIPTION

This function checks if a_buff is empty or contains only a comment, returning
ST_Comment if so.  It then uses an istringstream object to read a_buff word 
by word.  It determines if the first word is an OpCode, label or error and
records it accordingly, setting the appropriate instruction type.  It then 
pulls and checks the second word, which should be an OpCode or Operand.  It 
will pull the third word if the second was an OpCode.  If something does not 
meet language standards it is flagged as an error and logged.  The function
returns the recorded instruction type when it has finished parsing.

RETURNS

Returns an instruction type based on OpCode found. ST_MachineLanguage
if numeric code was discovered, ST_AssemblerInstr if symbolic, and
ST_End if an END statement was found.  Returns ST_Comment if
the given line was a comment or the line contained an error.

AUTHOR

Lucas Crockett

DATE

6:27am 4/24/2017

*/
/**/
Instruction::InstructionType Instruction::ParseInstruction( string &a_buff ) {

	m_instruction = a_buff;

	//Void all private members before starting to parse.
	m_Label = "";
	m_OpCode = "";
	m_Operand = "";
	m_NumOpCode = NULL;
	m_IsNumericOperand = false;
	m_OperandValue = NULL;
	m_type = ST_Comment;

	//Case 1: Blank line or commented line
	if (m_instruction.empty()) {

		return m_type;
	}

	//Have to check for blank line before this statement or it blows up.
	size_t first = m_instruction.find_first_not_of("\t ");
	
	if (first == string::npos || m_instruction[first] == ';') {

		return m_type;
	}

	//Cut the comment off of m_instruction.
	m_instruction = m_instruction.substr(0, m_instruction.find_first_of(';'));
	
	
	istringstream firstWord(m_instruction);
	string instruc;
	//Find label and/or OpCode.
	for (int i = 0; i < 2; i++) {

		firstWord >> instruc;
		string INSTRUC = "";
		for (unsigned int i = 0; i < instruc.size(); i++) INSTRUC += toupper(instruc[i]);
		//Case 2: Assembly instruction
		for (int i = 0; i < 3; i++) {

			if (INSTRUC == m_acceptedOpCode[i]) {

				m_type = ST_AssemblerInstr;
				m_OpCode = INSTRUC;
				break;
			}

		}


		if (m_type != ST_AssemblerInstr) {

			//Case 3: Machine instruction
			for (int i = 0; i < 26; i++) {

				if (INSTRUC == m_acceptedNumOp[i]) {

					m_type = ST_MachineLanguage;
					m_NumOpCode = (i % 13) + 1;
					m_OpCode = m_acceptedNumOp[(i % 13) + 13];
					// If the instruction is HALT, there is nothing more on the line.
					if (m_NumOpCode == 13) return m_type;
					break;
				}

			}

		}


		//Case 4: End
		if (INSTRUC == m_acceptedOpCode[3]) {

			m_type = ST_End;
			m_OpCode = "END";
			return m_type;
		}

		//Case 5: First word was a label or improper command
		if (i == 0 && m_OpCode.empty() && isalpha(INSTRUC[0]) && instruc.size() < 11) {

			m_Label = instruc;
		}

		//Case 6: Second word was not an OpCode so either operand or error
		else if(i == 1 && !m_OpCode.empty()) {

			continue;
		}

		//Case 7: First word was not a label or OpCode so error
		else if(m_OpCode.empty()) {

			string err = "Err: Improper label or OpCode. Be sure labels start with a letter and check spelling for OpCodes.";
			Errors::RecordError(err);
			return m_type;
		}

	}

	//If the current instruc is the Operand, skip
	if ( isLabel() ) firstWord >> instruc;

	int ins = instruc.size();
	//Operand might be numeric
	if (isdigit(instruc[0])) {

		//Check if instruc is mixed with non-numeric characters
		for (int i = 1; i < ins; i++) {

			if (!isdigit(instruc[i])) {

				//Mixed but started with a number so error
				string err = "Err: Operand is not a decimal number or label.";
				Errors::RecordError(err);
				return m_type;
			}

		}

		//instruc is a valid Operand and numeric
		m_Operand = instruc;
		m_IsNumericOperand = true;
		m_OperandValue = stoi(instruc);
		return m_type;
	}


	//instruc may be a label, but ORG, DS and DC do not accept labels.
	if (isalpha(instruc[0]) && ins < 11  && m_OpCode != m_acceptedOpCode[0] &&
		m_OpCode != m_acceptedOpCode[2] && m_OpCode != m_acceptedOpCode[1]) {

		m_Operand = instruc;
		m_IsNumericOperand = false;
		m_OperandValue = NULL;
		return m_type;
	}


	//instruc is an invalid label
	string err = "Err: Invalid label. Be sure labels start with a letter. ORG, DC and DS do not accept labels.";
	Errors::RecordError(err);
	return m_type;
}



/**/
/*
Instruction::LocationNextInstruction() Instruction::LocationNextInstruction()

NAME

Instruction::LocationNextInstruction - finds the position of the next instruction.

SYNOPSIS

int Instruction::LocationNextInstruction( int a_loc );
a_loc             --> contains the location of the current instruction.

DESCRIPTION

This function points a_loc to the next spot in virtual memory to store
an instruction.  It increments by 1 in most cases.  a_loc is incremented
by the value associated with ORG or DS if those were the OpCodes of the
previously parsed line.

RETURNS

Returns an integer specifying the memory location of the next instruction.

AUTHOR

Lucas Crockett

DATE

6:28am 4/24/2017

*/
/**/
int Instruction::LocationNextInstruction( int a_loc )
{

	//Case 1: ORG instruction
	if (m_OpCode == m_acceptedOpCode[0]) {

		return m_OperandValue;
	}

	//Case 2: DS instruction
	if (m_OpCode == m_acceptedOpCode[2]) {

		return (a_loc + m_OperandValue);
	}

	//Case 3: neither
	return (a_loc + 1);
}
