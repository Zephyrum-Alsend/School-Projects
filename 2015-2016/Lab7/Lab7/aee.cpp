//Lab 7 - Arithmetic e-Expression
//Lucas Crockett
//Status: Working

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// Computes the precedence of an operator.
int prec(char op);

// Applies an operator to numbers.
int evaluate(char op, int x, int y);

int Power(int x, int y);

int main()
{
	int nst[41];       // The number stack.
	int ntop = -1;     // The top of the number stack.
	char ost[41];       // The operator stack.
	int otop = -1;     // The top of the operator stack.

	// Prompt the user for an expresion and read it.
	string ebuff;       // Buffers the arithmetic expression.
	int ie = 0;         // Indexes the arithmetic expression.
	cout << "enter arithmetic expression:\n";
	getline(cin, ebuff);

	// Let's stick a special character at the end of the string.
	ebuff += ']';

	// Put the beginning of line character in the operator stack.
	otop = 0;
	ost[0] = '[';

	// Scan throught the expression one character at a time.
	bool prevOperator = true;  // For primative error detection.
	for (ie = 0;; ie++) {

		// Buffer the next character.
		char nchar = ebuff[ie];

		// If the next character is a blank or tab, there is nothing to do.
		if (nchar == ' ' || nchar == '\t') {

			continue;
		}
		// Stack the numbers immediately.
		if (nchar >= '0' && nchar <= '9') {
			if (prevOperator) {
				ntop++;
				nst[ntop] = nchar - '0';
			}
			else {
				nst[ntop] = nst[ntop] * 10 + (nchar - '0');
			}
			
			prevOperator = false;
			continue;
		}
		// If we have a left parentheses, stack it.
		if (nchar == '(') {
			otop++;
			ost[otop] = '(';

			if (!prevOperator) {
				cout << "Syntax error" << endl;
				exit(1);
			}
			prevOperator = true;
			continue;
		}
		// At this point we must have an operator.
		if (prevOperator) {
			//Handles unary minus.
			if (nchar == '-'){
				ntop++;
				nst[ntop] = 0;
				otop++;
				ost[otop] = '`';
				continue;
			}
			cout << "Syntax error" << endl;
			exit(1);
		}

		// Perform as may operations from the stack as the precedence allows.
		while (prec(ost[otop]) >= prec(nchar)) {

			// Left paren or [ in stack means we have nothing left to
			// evaluate.
			if (ost[otop] == '[' || ost[otop] == '(') break;

			// Perform the indicated operation.
			nst[ntop - 1] = evaluate(ost[otop], nst[ntop - 1], nst[ntop]);
			ntop--;
			otop--;
		}
		// If we broke out because of matching the beginning of the line,
		// the number on the top of the stack is the result.
		if (nchar == ']') {

			if (ost[otop] == '(') {
				cout << "Imbalanced parentheses" << endl;
				exit(1);
			}
			cout << "value of expression is: " << nst[ntop] << endl;
			return 0;
		}
		// If we broke out due to matching parens, pop the paren out of the
		// stack and move on to the next character.
		if (ost[otop] == '(' && nchar == ')') {
			otop--;
			prevOperator = false;
			continue;
		}
		if (nchar == ')') {

			cout << "Imbalanced parentheses" << endl;
			exit(1);
		}
		// Stack the operator that we could not evaluate.
		otop++;
		ost[otop] = nchar;
		prevOperator = true;
		continue;
	}
}
// Function to return the precedence value for an operator.
int prec(char op)
{
	switch (op) {

	case '[':
		return 0;

	case ']':
		return 0;

	case '(':
		return 1;

	case ')':
		return 1;

	case '+':
		return 2;

	case '-':
		return 2;

	case '*':
		return 3;

	case '/':
		return 3;

	case '^':
		return 4;

	case '`':
		return 5;

	default:
		cout << "Illegal operator\n";
		exit(1);
		return 0;
	}
}
// Applies an operator to numbers.
int evaluate(char op, int x, int y)
{

	// Based on the operator, perform the operation.
	switch (op) {

	case '+':
		return x + y;

	case '-':
		return x - y;

	case '*':
		return x * y;

	case '/':
		return x / y;

	case '^':
		return Power(x, y);

	case '`':
		return x - y;

	default:

		cout << "Illegal operator" << endl;
		exit(1);
		return 0;
	}
}
//Recursive function for computing the power of a number.
int Power(int x, int y)
{
	switch (y) {
	case 1:
		return x;
	case 0:
		return 1;
	}
	if (y > 1)
		return x * Power(x, y - 1);
	else
		return 1 / Power(x, abs(y));
}