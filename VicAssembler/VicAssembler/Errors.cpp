#include "stdafx.h"
#include "Errors.h"
vector<string> Errors::m_ErrorMsgs;

/**/
/*
Errors::InitErrorReporting() Errors::InitErrorReporting()

NAME

Errors::InitErrorReporting - clears m_ErrorMsgs.

SYNOPSIS

void Errors::InitErrorReporting();

DESCRIPTION

This function clears m_ErrorMsgs of all previously accrued
messages.

RETURNS

Returns nothing.

AUTHOR

Lucas Crockett

DATE

2:24am 5/8/2017

*/
/**/
// Initializes error messages.
void Errors::InitErrorReporting() {

	m_ErrorMsgs.clear();
}

/**/
/*
Errors::RecordError() Errors::RecordError()

NAME

Errors::RecordError - logs error messages.

SYNOPSIS

void Errors::RecordError(string &a_emsg);
a_emsg           --> the error message to be recorded.

DESCRIPTION

This function will insert a_emsg into the beginning of 
m_ErrorMsgs.

RETURNS

Returns nothing.

AUTHOR

Lucas Crockett

DATE

2:24am 5/8/2017

*/
/**/
// Records an error message.
void Errors::RecordError(string &a_emsg) {

	string temp = a_emsg;
	auto it = m_ErrorMsgs.begin();
	m_ErrorMsgs.insert(it, temp);
}

/**/
/*
Errors::DisplayErrors() Errors::DisplayErrors()

NAME

Errors::DisplayErrors - prints an error message.

SYNOPSIS

void Errors::DisplayErrors();

DESCRIPTION

This function flushes m_ErrorMsgs to the console, 
printing the last element and deleting it promptly afterwards
until m_ErrorMsgs is empty.

RETURNS

Returns nothing.

AUTHOR

Lucas Crockett

DATE

1:46am 5/9/2017

*/
/**/
// Displays the collected error message.
void Errors::DisplayErrors() {

	while (!m_ErrorMsgs.empty()) {

		cout << m_ErrorMsgs.back() << endl;
		m_ErrorMsgs.pop_back();
	}

}