//Lab 3 - vtime.cpp
//Lucas Crockett
//Status: Working

#include <iostream>
#include "VTime.h"

using namespace std;

int main(){
	VTime tim1(12, 15, 45);
	cout << tim1.getASCIITime() << endl;
	tim1 = tim1 + 15;
	cout << tim1.getASCIITime() << endl;
	tim1 = tim1 - 85;
	cout << tim1.getASCIITime() << endl;
	tim1 = tim1 + 43200;
	cout << tim1.getASCIITime() << endl;
	tim1 = tim1 - 86400;
	cout << tim1.getASCIITime() << endl;
	tim1 = tim1 - 900;
	cout << tim1.getASCIITime() << endl;

	return(0);
}

// Adds a specified number of seconds onto the time.
void VTime::addSeconds(int a_seconds)
{
	m_seconds = (m_seconds + a_seconds) % 86400;
}
VTime VTime::operator +(int a_seconds)
{
	VTime tmp(0, 0, m_seconds);
	tmp.addSeconds(a_seconds);
	return tmp;
}
void VTime::subSeconds(int a_seconds)
{
	m_seconds -= a_seconds;
	while (m_seconds < 0) {
		m_seconds += 86400;
	}
}
VTime VTime::operator -(int a_seconds)
{
	VTime tmp(0 , 0, m_seconds);
	tmp.subSeconds(a_seconds);
	return tmp;
}
// Gets the time as an ASCII string
string VTime::getASCIITime()
{
	char buff[128];
	sprintf(buff, "%2.2d:%2.2d:%2.2d", (m_seconds / 3600), ((m_seconds % 3600) / 60), (m_seconds % 60));

	return buff;
}