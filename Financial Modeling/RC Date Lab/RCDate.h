// RCDate.h: interface for the RCDate class.
//
//  This is a general date class.  Dates as represented internally as:
//      year * 10000 + 100 * month + day
//
//  Although there may be more efficent ways of representing the day, 
//  this approach make running the code in the debugger much easier.
//
//////////////////////////////////////////////////////////////////////
#pragma once 
#include <iostream>

using namespace std;

class RCDate
{
public:

	// Constructors for the date class.
	RCDate() {
		m_date = 0;
	}
	RCDate(const RCDate &a_date) {

		Set(a_date);
	}

	RCDate(int a_year, int a_month, int a_day) {
		Set(a_year, a_month, a_day);
	}

	RCDate(int a_date) {
		Set(a_date);
	}
	// This is a blank date.
	static const int BlankDate = 0;

	// Defines the day of the week.
	enum DAY_OF_WEEK {
		SUNDAY = 0,
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
		UNDEF_DOW
	};
	static string getStringDOW(DAY_OF_WEEK a_dow) {
		static string sdow[8] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Undefined" };
		if (a_dow < SUNDAY || a_dow > UNDEF_DOW) {

			return "OutOfRange";
		}
		return sdow[a_dow];
	}
	// Set functions for the date.
	void Set(int a_year, int a_month, int a_day);
	void Set(int a_date);
	void Set(const RCDate &a_date);

	// Set the fake today value.  This will be used instead of the real today.
	static void setFakeTodayValue(int a_val) { m_FakeTodayValue = a_val; }

	// Record today's local date in this object - allows faked today's date.
	void SetToday();

	// Record today's local date in this object.  Does not use faked today's date.
	void SetActualToday();

	// Returns the elements of a date.
	int GetYear() const { return m_date / 10000; }
	int GetMonth() const { return m_date / 100 % 100; }
	int GetDay() const { return m_date % 100; }

	// Gets the date as one value or as its component values.
	int Get() { return m_date; }
	void Get(int &a_year, int &a_month, int &a_day) const {

		a_year = GetYear();
		a_month = GetMonth();
		a_day = GetDay();
	}
	// Return date as an ASCII string in the form "MM/DD/YYYY".
	string GetASCIIDate();

	// Conversion operators.
	operator int() const { return m_date; }

	// Assignement operators.
	RCDate& operator =(const RCDate &a_date);
	RCDate& operator =(int a_date);

	// Finds the difference between two dates.  
	int operator -(const RCDate &a_date);

	// Subtracts a specified number of days to the date.  
	RCDate operator -(int a_days);

	// Adds a specified number of days to the date.  
	RCDate operator +(int a_days);

	// Compares two dates. 
	bool operator ==(const RCDate &a_date) const;
	bool operator ==(int a_date) const;

	bool operator !=(const RCDate &a_date) const;
	bool operator !=(int a_date) const;
	bool operator <(const RCDate& a_date) const;
	bool operator <(int a_date) const;

	bool operator <= (const RCDate& a_date);
	bool operator <=(int a_date);	//Removed const because compiler got confused

	bool operator >(const RCDate& a_date);
	bool operator >(int a_date);	//Removed const because compiler got confused

	bool operator >=(const RCDate& a_date);
	bool operator >=(int a_date);	//Removed const because compiler got confused

	// Unary minus operators.
	RCDate& operator --(); // This is the prefix operator.

	RCDate operator --(int) {  // This guy is the postfix operator.
		RCDate d = *this;
		operator --();
		return d;
	}
	// Unary plus operators.
	RCDate& operator ++();

	RCDate operator ++(int) {
		RCDate d = *this;
		operator ++();
		return d;
	}
	// Determines if the year recorded here is a leap year.  This code will work only
	// between 1901 and 2099.  We will talk of the general rule in class.
	bool isLeapYear() const { return (m_date / 10000) % 4 == 0; }

	// Gets the Julian day from this date.  Julian day vary from 0 to 365.
	int getJulianDay() const {

		int month = m_date / 100 % 100;
		int day = m_date % 100;
		int incre = (isLeapYear() && month > 2) ? 1 : 0;
		return dayPreMonth[month] + day - 1 + incre;
	}
	//  This algorithm works from 1901 until 2100.  
	int GetDayOfWeek() const {

		int year = m_date / 10000;
		int mday = (year * 365) + ((year - 1) / 4) + getJulianDay() + 6;
		return mday % 7;
	}
	// Computes the calendar difference between two date.  In order to optimize speed, this only works
	// for dates between 1901 and 2099 inclusive.
	int CalendarDiffDates(const RCDate &a_nearDate, const RCDate &a_farDate)
	{
		int diff = dateOffset(a_nearDate) - dateOffset(a_farDate);
		return diff;
	}
private:

	// This only uses up a 4 byte integer.
	int m_date;

	// To fake out the value of today.
	static int m_FakeTodayValue;

	// The number of days since the beginning of the year to a given month.  (non-leap year)
	static int dayPreMonth[13];

	// The number of days in a month. (non-leap year)
	static int daysInMonth[13];

	// Get the offset from the year 0.
	int dateOffset(const RCDate &a_date) {  // This has a flaw

		int year = a_date.m_date / 10000;
		int offset = (year * 365) + ((year - 1) / 4) + a_date.getJulianDay();
		return offset;
	}
};

