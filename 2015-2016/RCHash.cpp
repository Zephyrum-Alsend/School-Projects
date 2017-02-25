#include <iostream>
using namespace std;

#include "RCHash.h"


RCHash::RCHash(int tableSize, int x)
{
	hashTable = new int[tableSize];
	capacity = tableSize;
	size = 0;
	collisions = 0;
	k = x;
}
RCHash::~RCHash()
{
	delete[] hashTable;
}
int RCHash::hashf(int val, int k)
{
	unsigned int sum = (k * val) % capacity;
	return sum;
}
void RCHash::AddToTable(int val)
{
	if (size >= capacity)
	{
		cerr << "You stay away from my sister!" << endl;
		exit(1);
	}
	int ind = hashf(val, k);
	while (true)
	{
		if (hashTable[ind].empty())
		{
			hashTable[ind] = val;
			size++;
			return;
		}
		if (hashTable[ind] == val)
		{
			return;
		}
		ind = (ind + 1) % capacity;
		collisions++;
	}
}
int RCHash::IsInTable(int val)
{
	int ind = hashf(val, k);
	for (int count = 0; count < capacity; count++)
	{
		if (hashTable[ind].empty())
		{
			return -1;
		}
		if (hashTable[ind] == val)
		{
			return ind;
		}
		ind = (ind + 1) % capacity;
	}
	return -1;
}
void RCHash::GetEfficiency()
{
	cout << (int)( ( (double)size / (double)capacity ) * 100.0 ) << "% full.\nCollisions: " << collisions << endl;
	return;
}

int main(){
	for (int c = 10; c < 2001; c++){
		cout << "Table Capacity: " << c << endl;
		for (int k = 1; k < 1001; k++){
			cout << "k = " << k << endl;
			RCHash HashtagTable(c, k);
			HashtagTable.AddToTable(18);
			HashtagTable.AddToTable(201);
			HashtagTable.AddToTable(277);
			HashtagTable.AddToTable(318);
			HashtagTable.AddToTable(393);
			HashtagTable.AddToTable(401);
			HashtagTable.AddToTable(417);
			HashtagTable.AddToTable(540);
			HashtagTable.AddToTable(583);
			HashtagTable.AddToTable(677);
			cout << "Positions:\n";
			cout << "18: " << HashtagTable.IsInTable(18)
				<< "\t201: " << HashtagTable.IsInTable(201)
				<< "\t277: " << HashtagTable.IsInTable(277)
				<< "\t318: " << HashtagTable.IsInTable(318)
				<< "\t393: " << HashtagTable.IsInTable(393)
				<< "\t401: " << HashtagTable.IsInTable(401)
				<< "\t417: " << HashtagTable.IsInTable(417)
				<< "\t540: " << HashtagTable.IsInTable(540)
				<< "\t583: " << HashtagTable.IsInTable(583)
				<< "\t677: " << HashtagTable.IsInTable(677) << endl;
			HashtagTable.GetEfficiency();
			cout << endl;
		}
	}
	exit(0);
}
