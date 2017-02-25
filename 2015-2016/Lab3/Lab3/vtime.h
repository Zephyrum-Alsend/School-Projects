//Lab 3 - vtime.h
//Lucas Crockett
//Status: Unkown

#pragma once
#include <string>
using namespace std;

class VTime
{
public:

	// Constructor for this class.  We allow the user to initially set the stime or it will be set to zero.
	VTime(int a_hours = 0, int a_minutes = 0, int a_seconds = 0)
	{
		m_seconds = a_hours * 3600;
		m_seconds += a_minutes * 60;
		m_seconds += a_seconds;
	}
	// Accessor functions.
	int getHours()
	{
		return m_seconds / 3600;
	}
	int getMinutes()
	{
		return (m_seconds % 3600) / 60;
	}
	int getSeconds()
	{
		return m_seconds % 60;
	}
	void setHours(int a_hours)
	{
		m_seconds = (a_hours * 3600) + (m_seconds % 3600);
	}
	void setMinutes(int a_minutes)
	{
		m_seconds = (a_minutes * 60) + ((m_seconds / 3600) * 3600) + (m_seconds % 60);
	}
	void setSeconds(int a_seconds)
	{
		m_seconds = a_seconds + ((m_seconds / 60) * 60);
	}
	// A function to add a specified number of seconds to the time.
	void addSeconds(int a_seconds);

	// Plus operator to add seconds onto the time.
	VTime operator +(int a_seconds);

	// A function to subtract a specified number of seconds to the time.
	void subSeconds(int a_seconds);

	// Minus operator to compute the difference between two times.
	VTime operator -(int a_seconds);

	// Gets the time as an ASCII string.
	string getASCIITime();

private:

	int m_seconds;

};