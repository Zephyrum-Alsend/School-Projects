// ConfigFile.h: interface for the ConfigFile class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "stdafx.h"
#include <string>
#include <hash_map>
using namespace std;
using namespace stdext;

class ConfigFile
{
public:
    ConfigFile() {};
    virtual ~ConfigFile() {};

    // Load in the data from a specified configuration file.  Allow for the possibility of this being called multiple times.
	bool Load( const char *a_file, bool a_displayParameters = true );

	// New improved tool to access parameters.
	bool GetParameter( const char *a_parameter, char *a_value );   // Be careful!!!
	bool GetParameter( const char *a_parameter, string &a_value );
	bool GetParameter( const char *a_parameter, int &a_value );
	bool GetParameter( const char *a_parameter, short &a_value );
	bool GetParameter( const char *a_parameter, long &a_value );
	bool GetParameter( const char *a_parameter, float &a_value );
	bool GetParameter( const char *a_parameter, double &a_value );
	bool GetParameter( const char *a_parameter, bool &a_value );


	// Test if a config file has a parameter for a given segment.  Note: we consider a 
    // parameter to be accessed if someone asks if it exists.
    bool ContainsParameter( const char *a_parameter ) {

        string value;
        return getParameterValue( a_parameter, value );
    }
    // Provides a list of the parameters that were not accessed.
    void GetUnaccessedParameters( vector<string> &a_paramNames );

    // Clear the set of recorded parameters.
    void clearConfigData() { m_ConfigData.clear(); }
    
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
    void trimBlanks( string &a_str ); 

    // Parse a line from the parameters file.
    bool parseLine( string &a_line, string &a_name, string &a_value );
    
    // Get the value of a specified parameter.
    bool getParameterValue( const char *a_name, string &a_value );
};
