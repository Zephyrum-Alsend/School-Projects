#include "stdafx.h"
#include "ConfigFile.h"
#include <iostream>
#include <sstream>
#include <algorithm>



// Load in the data from a specified configuration file.  Allow for the possibility of this being called multiple times.  Assumes a_file is the full path to a .ini file.
bool ConfigFile::Load(const char *a_file, bool a_displayParameters) {
	//Checks if the file exists. Prints an error message and does nothing if file path is incorrect.
	if (fileExists(a_file)) {
		//Opens, copies and loads the .ini file's contents into a hashmap then closes.
		ifstream file(a_file);
		for (string line; getline(file, line);) {
			//Removes ;comments from the copied line.
			if (line.find(';') != line.npos) {
				line.erase(line.find(';'));
			}
			//Skips processing the line if it is whitespace.
			if (line.find_first_not_of(' ') != line.npos) {
				string name, value;
				//Returns true and processes the line if it is of the format "key = value."
				if (parseLine(line, name, value)) {
					//parseLine handles trimming blanks from line, name and value.
					//Checks if the entry already exists in the hashmap.
					if (m_ConfigData.find(name) == m_ConfigData.end()) {
						ConfigValue temp;
						temp.value = value;
						m_ConfigData[name] = temp;
					}
				}
			}
		}
		file.close();
		if (a_displayParameters) DisplayParameters();
		return true;
	}
	else {
		cout << "File not found.\n";
		return false;
	}
};

// New improved tool to access parameters.
bool ConfigFile::GetParameter(const char *a_parameter, char *a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value; //There is no way to tell how long the char array is 
											  //if the user forgot to \0 terminate it, and no way
											  //to tell if it is \0 terminated either.
		return true;
	}
	else return false;
};   // Be careful!!!
bool ConfigFile::GetParameter(const char *a_parameter, string &a_value) {
	if (m_ConfigData.find(a_parameter) != m_ConfigData.end()) {
		a_value = m_ConfigData[a_parameter].value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, int &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, short &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, long &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, float &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, double &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};
bool ConfigFile::GetParameter(const char *a_parameter, bool &a_value) {
	string temp_value;
	if (getParameterValue(a_parameter, temp_value)) {
		istringstream(temp_value) >> a_value;
		return true;
	}
	else return false;
};


// Test if a config file has a parameter for a given segment.  Note: we consider a 
// parameter to be accessed if someone asks if it exists.
bool ConfigFile::ContainsParameter(const char *a_parameter) {

	string value;
	return getParameterValue(a_parameter, value);
}
// Provides a list of the parameters that were not accessed.
void ConfigFile::GetUnaccessedParameters(vector<string> &a_paramNames) {
	a_paramNames.clear();
	//for(auto iter = m_ConfigData.begin(); iter != m_ConfigData.end(); iter++) {
	for (auto const& iter : m_ConfigData) {
		if (!m_ConfigData[iter.first].isAccessed)
			a_paramNames.push_back(iter.first);
	}
};

// Clear the set of recorded parameters.
void ConfigFile::clearConfigData() { m_ConfigData.clear(); }

// Display the parameters in alphabetical order.
void ConfigFile::DisplayParameters() {
	vector<string> temp_param;
	for (auto const& iter : m_ConfigData) {
		temp_param.push_back(iter.first);
	}
	sort(temp_param.begin(), temp_param.end());
	for (int i = 0; i < temp_param.size(); i++) {
		cout << temp_param[i] << endl;
	}
};
