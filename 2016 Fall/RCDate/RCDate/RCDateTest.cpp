#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "RCDate.h"
#include <string>
#include <time.h>
using namespace std;

int main() {
	//Constructor testing
	cout << "Constructor testing:" << endl;
	RCDate date1(20161106);
	RCDate date2(2008, 9, 21);
	RCDate date3(date2);
	RCDate date4 = 20318219;
	cout << "date1: " << date1.GetASCIIDate() << endl;
	cout << "date2: " << date2.GetASCIIDate() << endl;
	cout << "date3: " << date3.GetASCIIDate() << endl;
	cout << "date4: " << date4.GetASCIIDate() << endl;

	//operator= testing
	cout << "Operator= testing:" << endl;
	date2 = date1;
	cout << "date2: " << date2.GetASCIIDate() << endl;
	date1 = 20080921;
	cout << "date1: " << date1.GetASCIIDate() << endl;

	//operator- testing
	cout << "Operator- testing:" << endl;
	date3 = 20170101;	//modify testing date
	date3 - 31;		//modify days deducted
	cout << "date3: " << date3.GetASCIIDate() << endl;

	cout << (date2 - date1) << endl;
	cout << (date1 - date2) << endl;
	date2 = 20160301;
	cout << (date2 - date3) << endl;

	//operator+ testing
	cout << "Operator+ testing:" << endl;
	date1 = 20160201;
	date2 = 20151231;
	date1 + 28;
	date2 + 60;
	cout << date1.GetASCIIDate() << endl;
	cout << date2.GetASCIIDate() << endl;

	//unary minus testing
	cout << "Unary Minus testing:" << endl;
	--date2;
	cout << date2.GetASCIIDate() << endl;
	date2--;
	cout << date2.GetASCIIDate() << endl;
	date2 = 20160101;
	--date2;
	cout << date2.GetASCIIDate() << endl;
	(date2--) + 1;	//Suffix gives 12/30/2015 while prefix gives 12/31/2015
	//Suffix ignores "+ 1" for some strange reason
	cout << date2.GetASCIIDate() << endl;

	//unary plus testing
	cout << "Unary Plus testing:" << endl;
	date2++;
	cout << date2.GetASCIIDate() << endl;
	++date2;
	cout << date2.GetASCIIDate() << endl;
	date2 = 20160228;
	++date2;
	cout << (date2++).GetASCIIDate() << endl;
	cout << date2.GetASCIIDate() << endl;
	++date2 - 1;
	cout << date2.GetASCIIDate() << endl;
	date2++ - 1;	//Same issue as unary minus suffix.
	cout << date2.GetASCIIDate() << endl;

	//Figuring out time.h functionality
	time_t rawtime;
	struct tm *info;

	time(&rawtime);

	info = localtime(&rawtime);
	cout << "Current local time and date: " << info->tm_mon + 1 << "/" << info->tm_mday << "/" << info->tm_year + 1900 << endl;

	//Set(Actual)Today testing
	date2.SetToday();	//Modify m_FakeTodayValue in RCDate.cpp for testing. Tested: 101, 1, 17430917
	cout << date2.GetASCIIDate() << endl;
	date2.SetActualToday();
	cout << date2.GetASCIIDate() << endl;

	//Comparison testing
	cout << "Comparison testing:" << endl;
	date1.SetActualToday();
	date2 = date1;
	date3 = 20181012;
	date4 = 19000101;
	cout << "This is true: " << (1 == 1) << endl << "This is false: " << (1 == 0) << endl;
	//These should be true
	cout << (date1 == date2) << endl;
	cout << (date1 != date3) << endl;
	cout << (date1 >= date2) << endl;
	cout << (date1 >= date4) << endl;
	cout << (date1 <= date2) << endl;
	cout << (date1 <= date3) << endl;
	cout << (date1 > date4) << endl;
	cout << (date1 < date3) << endl;
	//These should be false
	cout << (date1 == date3) << endl;
	cout << (date1 != date2) << endl;
	cout << (date1 >= date3) << endl;
	cout << (date1 <= date4) << endl;
	cout << (date1 > date2) << endl;
	cout << (date1 > date3) << endl;
	cout << (date1 < date2) << endl;
	cout << (date1 < date4) << endl;

	//These should be true
	cout << (date3 == 20181012) << endl;
	cout << (date3 != 20181013) << endl;
	cout << (date3 >= 20181012) << endl;
	cout << (date3 >= 20181011) << endl;
	cout << (date3 <= 20181012) << endl;
	cout << (date3 <= 20181013) << endl;
	cout << (date3 > 20181011) << endl;
	cout << (date3 < 20181013) << endl;
	//These should be false
	cout << (date3 == 20181011) << endl;
	cout << (date3 != 20181012) << endl;
	cout << (date3 >= 20181013) << endl;
	cout << (date3 <= 20181011) << endl;
	cout << (date3 > 20181012) << endl;
	cout << (date3 > 20181013) << endl;
	cout << (date3 < 20181012) << endl;
	cout << (date3 < 20181011) << endl;

	return 0;
}