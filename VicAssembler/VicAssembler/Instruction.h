//
// Class to parse and provide information about instructions.  Note: you will be adding more functionality.
//
#pragma once

// The elements of an instruction.
class Instruction {

public:

    Instruction( ) { };
    ~Instruction( ) { };

    // Codes to indicate the type of instruction we are processing.  Why is this inside the
    // class?
    enum InstructionType {
        ST_MachineLanguage, // A machine language instruction.
        ST_AssemblerInstr,  // Assembler Language instruction.
        ST_Comment,          // Comment or blank line
        ST_End                    // end instruction.
    };
    // Parse the Instruction.
    InstructionType ParseInstruction( string &a_buff );

    // Compute the location of the next instruction.
    int LocationNextInstruction( int a_loc );

    // To access the label
    inline string &GetLabel( ) {

        return m_Label;
    }

    // To determine if a label is blank.
    inline bool isLabel( ) {

        return ! m_Label.empty();
    }

	//To access the OpCode.
	inline string &getOpCode() {

		return m_OpCode;
	}

	//To access the numeric OpCode.
	int &getNumOp() {

		return m_NumOpCode;
	}

	//To access the line of instruction.
	inline string &getInstr() {

		return m_instruction;
	}

	//To access whether an Operand is numeric.
	inline bool &getIsNumOperand() {

		return m_IsNumericOperand;
	}

	//To access the Operand name.
	inline string &getOperand() {

		return m_Operand;
	}

	//To access the Operand value.
	inline int &getOperandVal() {

		return m_OperandValue;
	}



private:


    // The elemements of a instruction
    string m_Label;            // The label.
    string m_OpCode;       // The symbolic op code.
    string m_Operand;      // The operand.


    string m_instruction;    // The original instruction.

    // Derived values.
    int m_NumOpCode;     // The numerical value of the op code.
    InstructionType m_type; // The type of instruction.

    bool m_IsNumericOperand;// == true if the operand is numeric.
    int m_OperandValue;   // The value of the operand if it is numeric.

	// List of accepted instructions.
	string m_acceptedOpCode[4] = { "ORG", "DC", "DS", "END" };
	string m_acceptedNumOp[26] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", 
		"10", "11", "12", "13", "ADD", "SUB", "MULT", "DIV", "LOAD", "STORE",
		"READ", "WRITE", "B", "BM", "BZ", "BP", "HALT" };
};


