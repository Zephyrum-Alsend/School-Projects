//Status: Built without errors.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
string filepath = "ralph.cfg";
void Load(const char *filepath, vector<double> vic);
void storeVal(string &val, vector<double> vic);
void trimBlanks(string &str);
bool parseLine(string &line, string &name, string &value);

int main() {
	vector<double> vic;
	Load(filepath.c_str(), vic);
}

//Assumes the filepath is valid.
void Load(const char *filepath, vector<double> vic) {
	//Opens, scans and extracts the DUCK we need from the .ini file.
	ifstream file(filepath);
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
				//Checks if the entry is DUCK and extracts the values if so.
				if (name == "DUCK") {
					storeVal(value, vic);
					file.close();
					return;		//Ensures only the first DUCK is read and recorded.
				}
			}
		}
	}
	file.close();
};

void storeVal(string &val, vector<double> vic) {
	string validChar = "01234567890.";
	bool isValid = true;
	double temp;

	//Extracts and handles values.
	int ind = val.find_first_of(' ');
	while (ind != string::npos) {
		//Extracts the first value.
		string val2 = val.substr(0, ind);
		//Removes the first value from val.
		val = val.substr(ind + 1);
		trimBlanks(val);	//There may be more than one space separating values so we trim it.

		//Tests if an extracted value is valid.
		for (int i = 0; i < val2.size(); i++) {
			if (validChar.find_first_of(val2[i]) == string::npos) {
				isValid = false;
				break;
			}
		}
		//Handles the extracted value.
		if (isValid) {
			//Removes terminating decimals.
			if (val2[val2.size() - 1] == '.')
				val2 = val2.substr(0, val2.size() - 1);
			//Stores the extracted value in vic.
			istringstream(val2) >> temp;
			vic.push_back(temp);
		}
		else {
			cout << "There was an invalid value.";
		}
		//Adjusts index for next loop.
		ind = val.find_first_of(' ');
	}
}

// Trim leading and trailing blanks.
void trimBlanks(string &str) {
	int start = str.find_first_not_of(' ');
	int end = str.find_last_not_of(' ');
	str = str.substr(start, 1 + (end - start));
};

// Parse a line from the parameters file.
bool parseLine(string &line, string &name, string &value) {
	trimBlanks(line);
	int ieq = line.find_first_of('=');
	if (ieq == string::npos || ieq == 0)
	{
		return false;
	}
	name = line.substr(0, ieq);
	trimBlanks(name);
	value = line.substr(ieq + 1);
	trimBlanks(value);
	return true;
};