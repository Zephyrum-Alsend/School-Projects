// ConfigFile.h: interface for the ConfigFile class.
// Written all functions inline for editing convenience. Remember to move them all to a .cpp once done. Sorry if I forgot to move any.
//////////////////////////////////////////////////////////////////////
#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "stdafx.h"
#include <string>
#include <hash_map>
#include <fstream>
using namespace std;
using namespace stdext;

class ConfigFile
{
public:
	ConfigFile() {};
	virtual ~ConfigFile() {};

	// Load in the data from a specified configuration file.  Allow for the possibility of this being called multiple times.
	// Assumes a_file is the full path to a .ini file.
	bool Load(const char *a_file, bool a_displayParameters = true);

	// New improved tool to access parameters.
	bool GetParameter(const char *a_parameter, char *a_value);   // Be careful!!!
	bool GetParameter(const char *a_parameter, string &a_value);
	bool GetParameter(const char *a_parameter, int &a_value);
	bool GetParameter(const char *a_parameter, short &a_value);
	bool GetParameter(const char *a_parameter, long &a_value);
	bool GetParameter(const char *a_parameter, float &a_value);
	bool GetParameter(const char *a_parameter, double &a_value);
	bool GetParameter(const char *a_parameter, bool &a_value);


	// Test if a config file has a parameter for a given segment.  Note: we consider a 
	// parameter to be accessed if someone asks if it exists.
	bool ContainsParameter(const char *a_parameter);
	
	// Provides a list of the parameters that were not accessed.
	void GetUnaccessedParameters(vector<string> &a_paramNames);

	// Clear the set of recorded parameters.
	void clearConfigData();

	// Display the parameters in alphabetical order.
	void DisplayParameters();

private:

	struct ConfigValue {

		string value;
		bool isAccessed;    // Notes whether or not the parameter was accessed.

		ConfigValue() { isAccessed = false; }
	};
	hash_map<string, ConfigValue> m_ConfigData;

	// Trim leading and trailing blanks.
	void trimBlanks(string &a_str) {
		int start = a_str.find_first_not_of(' ');
		int end = a_str.find_last_not_of(' ');
		a_str = a_str.substr(start, 1 + (end - start));
	};

	// Parse a line from the parameters file.
	bool parseLine(string &a_line, string &a_name, string &a_value) {
		trimBlanks(a_line);
		int ieq = a_line.find_first_of('=');
		if (ieq == string::npos || ieq == 0)
		{
			return false;
		}
		a_name = a_line.substr(0, ieq);
		trimBlanks(a_name);
		a_value = a_line.substr(ieq + 1);
		trimBlanks(a_value);
		return true;
	};

	// Get the value of a specified parameter.
	bool getParameterValue(const char *a_name, string &a_value) {
		if (m_ConfigData.find(a_name) != m_ConfigData.end()) {
			a_value = m_ConfigData[a_name].value;
			m_ConfigData[a_name].isAccessed = true;
			return true;
		}
		else return false;
	};

	// Check if file exists.
	bool fileExists(const char* a_file) {
		ifstream bfile(a_file);
		return (bool)bfile; //File closed as it goes out of scope.
	};
};
