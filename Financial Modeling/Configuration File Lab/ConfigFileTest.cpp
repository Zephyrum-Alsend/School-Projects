#include "stdafx.h"
#include "ConfigFile.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ConfigFile Test;
	string FilePath = "E:\\Skyrim.INI";
	if(Test.Load(FilePath.c_str(), true)) cout << "true" << endl << endl;
	//Test.DisplayParameters();

	vector<string> param;
	Test.GetUnaccessedParameters(param);
	string something = "something";
	param.push_back(something);
	for (int i = 0; i < param.size(); i++) {
		cout << param[i] << endl;
	}

	cout << Test.ContainsParameter("fMusicDuckingSeconds") << endl;
	cout << Test.ContainsParameter("fMusicUnDuckingSeconds") << endl;
	cout << Test.ContainsParameter("fMusicDuckingSeconds") << endl;
	cout << Test.ContainsParameter("fMenuModeFadeOutTime") << endl;
	cout << Test.ContainsParameter("fMenuModeFadeInTime") << endl;
	cout << Test.ContainsParameter("bDrawLandShadows") << endl;
	Test.GetUnaccessedParameters(param);
	for (int i = 0; i < param.size(); i++) {
		cout << param[i] << endl;
	}

	string val1;
	int val2;
	short val3;
	long val4;
	float val5;
	double val6;
	bool val7;
	char val8[100]; //Attempted values of 100 and 4 (output value is "ENGLISH").
				    //Output "ENGLISH" for 100... and 4.
	Test.GetParameter("sLanguage", val1);
	Test.GetParameter("iShadowMapResolutionPrimary", val2);
	Test.GetParameter("uExterior Cell Buffer", val3);
	Test.GetParameter("iShadowMapResolutionPrimary", val4);
	Test.GetParameter("fMusicDuckingSeconds", val5);
	Test.GetParameter("fShadowLODMaxStartFade", val6);
	Test.GetParameter("bAllowLoadGrass", val7);
	cout << val1 << endl << val2 << endl << val3 << endl << val4 << endl << val5 << endl << val6 << endl << val7 << endl;
	Test.GetParameter("sLanguage", val8);
	cout << val8 << endl;
	Test.Load(FilePath.c_str(), false);
	Test.GetUnaccessedParameters(param);
	for (int i = 0; i < param.size(); i++) {
		cout << param[i] << endl;	//List is missing the previously accessed parameters above.
	}
	cout << ((int)val2 + (int)val4) << endl;

	cout << "done";
}