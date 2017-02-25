#pragma once
class ThreeNumbersISee
{
public:
	ThreeNumbersISee();
	~ThreeNumbersISee();
	ThreeNumbersISee & operator++()
	{
		x++; y++; z++;
		return *this;
	}
	ThreeNumbersISee & operator++(int)
	{
		ThreeNumbersISee temp = *this;
		++(*this);
		return temp;
	}
	virtual int GetCake() 
	{
		return x + y + z;
	}

private:
	int x, y, z;
	static int count;
};

