#define _CRT_SECURE_NO_WARNINGS
#include "RCDate.h"
#include <string>
#include <time.h>
using namespace std;

int RCDate::m_FakeTodayValue = 0;
int RCDate::daysInMonth[13] = {31, 31, 28, 31, 30, 31,  30,  31,  31,  30,  31,  30,  31 };
int RCDate::dayPreMonth[13] = {365, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

//Done
void RCDate::Set(int a_year, int a_month, int a_day) {
	if(0 < a_month < 13 && 0 < a_day < daysInMonth[a_month])
		m_date = a_day + (a_month * 100) + (a_year * 10000);
	else SetToday();
}

//Done
void RCDate::Set(int a_date) {
	if (0 < ((a_date / 100) % 100) < 13 && 0 < a_date%100 <= daysInMonth[((a_date / 100) % 100)])
		m_date = a_date;
	else SetToday();
}

//Done
void RCDate::Set(const RCDate &a_date) {
	m_date = a_date.m_date;
}

//Done
void RCDate::SetToday() {
	//assumes the programmer knows what constitutes a valid date
	if (m_FakeTodayValue >= 101) {
		m_date = m_FakeTodayValue;
	}
	else {
		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		info = localtime(&rawtime);
		m_date = (info->tm_mon + 1)*100 + (info->tm_mday) + (info->tm_year + 1900)*10000;
	}
}

//Done
void RCDate::SetActualToday() {
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	m_date = (info->tm_mon + 1) * 100 + (info->tm_mday) + (info->tm_year + 1900) * 10000;
}

//Done
string RCDate::GetASCIIDate()
{
	string today = to_string(GetMonth()) + "/" + to_string(GetDay()) + "/" + to_string(GetYear());
	return today;
}

//Done
RCDate &RCDate::operator=(const RCDate &a_date) {
	m_date = a_date.m_date;
	return *this;
}

//Done
RCDate &RCDate::operator=(int a_date) {
	m_date = a_date;
	return *this;
}

//Done
int RCDate::operator -(const RCDate &a_date) {
	return (dateOffset(*this) - dateOffset(a_date));
}

//Done
//Implementing a while loop to handle years separately got too complicated once leap years were factored in.
RCDate RCDate::operator-(int a_days) {
	int days = a_days;
	if (a_days >= GetDay()) {
		//Sets date to the first of the month and subtracts appropriate amount from days.
		days -= (GetDay() - 1);
		m_date -= (GetDay() - 1);
		//Deducts months and adjusts year as necessary. Inefficient for values of a_days over 365.
		while (days >= daysInMonth[GetMonth() - 1]) {
			if (GetMonth() == 1) {
				m_date -= 8900;
				days -= 31;
			}
			else if (isLeapYear() && GetMonth() == 3) {
				m_date -= 100;
				days -= 29;
			}
			else {
				m_date -= 100;
				days -= daysInMonth[GetMonth()];
			}
		}
		//If a_days lands the date on the first of a month, return.
		if (days == 0) return *this;
		//Otherwise set the date back 1 day and subtract 1 from days.
		days--;
		if (GetMonth() == 1) m_date -= 8870;
		else if (isLeapYear() && GetMonth() == 3) m_date -= 72;
		else if (GetMonth() == 3) m_date -= 73;
		else if (daysInMonth[GetMonth() - 1] == 30) m_date -= 71;
		else m_date -= 70;
	}
	//days will not change the month so just subtract.
	m_date -= days;
	return *this;
}

//Done
RCDate RCDate::operator+(int a_days) {
	int days = a_days;
	if (a_days > (daysInMonth[GetMonth()] - GetDay())) {
		//Catches if the original date is in Feb on a leap year and the addition would land on the 29th
		if (isLeapYear() && GetMonth() == 2 && a_days + GetDay() == 29);
		else {//Sets date to the first of the next month and subtracts appropriate amount from days.
			days -= (daysInMonth[GetMonth()] - GetDay() + 1);
			if (GetMonth() == 12) m_date += 8900 - GetDay() + 1;
			else m_date += 100 - GetDay() + 1;
			//Adds months and adjusts year as necessary. Inefficient for values of a_days over 365.
			while (days >= daysInMonth[GetMonth()]) {	//Does not catch scenario: days = 28, month = 2, isLeapYear() = true.
				if (GetMonth() == 12) {
					days -= 31;
					m_date += 8900;
				}
				else if (isLeapYear() && GetMonth() == 2) {
					if (days != 28) {
						m_date += 100;
						days -= 29;
					}
					//Catch for days = 28, month = 2, isLeapYear() = true.
					else {
						m_date += 28;
						days -= 28;
					}
				}
				else {
					days -= daysInMonth[GetMonth()];
					m_date += 100;
				}
			}
		}
	}
	//days will not change the month so just add.
	m_date += days;
	return *this;
}

bool RCDate:: operator==(const RCDate &a_date) const {
	return m_date == a_date.m_date;
}
bool RCDate:: operator==(int a_date) const {
	return m_date == a_date;
}

bool RCDate::operator !=(const RCDate &a_date) const{
	return m_date != a_date.m_date;
}
bool RCDate::operator !=(int a_date) const {
	return m_date != a_date;
}
bool RCDate::operator <(const RCDate& a_date) const {
	return m_date < a_date.m_date;
}
bool RCDate::operator <(int a_date) const {
	return m_date < a_date;
}

bool RCDate::operator <= (const RCDate& a_date) {
	return m_date <= a_date.m_date;
}
bool RCDate::operator <=(int a_date) {
	return m_date <= a_date;
}

bool RCDate::operator >(const RCDate& a_date) {
	return m_date > a_date.m_date;
}
bool RCDate::operator >(int a_date) {
	return m_date > a_date;
}

bool RCDate::operator >=(const RCDate& a_date) {
	return m_date >= a_date.m_date;
}
bool RCDate::operator >=(int a_date) {
	return m_date >= (int)a_date;
}

//Done
RCDate &RCDate::operator --() {
	if (GetDay() == 1) {
		if (GetMonth() == 1) m_date -= 8870;
		else if (isLeapYear() && GetMonth() == 3) m_date -= 72;
		else if (GetMonth() == 3) m_date -= 73;
		else if (daysInMonth[GetMonth() - 1] == 30) m_date -= 71;
		else m_date -= 70;
	}
	else m_date -= 1;
	return *this;
}

//Done
RCDate &RCDate::operator ++() {
	if (GetDay() >= daysInMonth[GetMonth()]) {
		if (isLeapYear() && GetMonth() == 2) {
			if (GetDay() == 29) m_date += 72;
			else m_date += 1;
		}
		else {
			if (GetMonth() != 12) m_date += 101 - daysInMonth[GetMonth()];
			else m_date += 8870;
		}
	}
	else m_date += 1;
	return *this;
}