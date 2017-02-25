#pragma once
#include <string>
using namespace std;

class RCHash
{
public:
	RCHash( int tableSize, int x );
	~RCHash();

	void AddToTable(int val);
	int IsInTable(int val);
	void GetEfficiency();

private:
	int *hashTable;
	int capacity;
	int size;
	int collisions;
	int k;

	int hashf(int val, int k = 1);
};


