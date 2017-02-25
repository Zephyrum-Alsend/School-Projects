//Lab 10 - semi-perfect hash
//Lucas Crockett
//Status: Working

#include <iostream>
#include <string>
using namespace std;

#include "Header.h"


RCHash::RCHash(int tableSize, int x)
{
	hashTable = new int[tableSize];
	//initializes values to 0 for empty checks
	for (int i = 0; i < tableSize; i++){
		hashTable[i] = 0;
	}
	capacity = tableSize;
	size = 0;
	collisions = 0;
	k = x;
}
RCHash::~RCHash()
{
	delete[] hashTable;
}
//Hashes a value.
int RCHash::hashf(int val)
{
	unsigned int sum = (k * val) % capacity;
	return sum;
}
//Adds a value to the hash table. Returns an (nonsensical) error message if the table is full and terminates the program.
void RCHash::AddToTable(int val)
{
	if (size >= capacity)
	{
		cerr << "You stay away from my sister!" << endl;
		exit(1);
	}
	int ind = hashf(val);
	while (true)
	{
		//Stores value in next empty slot if the original hash is full. Counts number of collisions.
		if (hashTable[ind] == 0)
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
//Checks if a value is in the hash table using code similar to AddToTable. Returns -1 if not found.
int RCHash::IsInTable(int val)
{
	int ind = hashf(val);
	for (int count = 0; count < capacity; count++)
	{
		if (hashTable[ind] == 0)
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
//Displays percentage of table filled and the number of collisions.
void RCHash::GetEfficiency()
{
	cout << (int)(((double)size / (double)capacity) * 100.0) << "% full.\nCollisions: " << collisions << endl;
	return;
}
//Retrieves number of collisions. Primarily for testing.
int RCHash::GetCollisions()
{
	return collisions;
}

int main(){
	//c = capacity, total size of hash table.
	for (int c = 10; c < 201; c++){
		//k is a factor in the hashing function.
		for (int k = 1; k < 1001; k++){
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
			//Skips to the next loop if there were any collisions.
			if (HashtagTable.GetCollisions() > 0)
				continue;
			//0 collisions so display the values of c and k along with the positions of each element to see if any patterns show up.
			//Also show the table's efficiency values to compare to other values of c and k.
			else{
				cout << "Table Size: " << c << "\nk = " << k << endl;
				cout << "Positions:\n";
				cout << "18: " << HashtagTable.IsInTable(18)
					<< "\t201: " << HashtagTable.IsInTable(201)
					<< "\t277: " << HashtagTable.IsInTable(277)
					<< "\t318: " << HashtagTable.IsInTable(318)
					<< "\t393: " << HashtagTable.IsInTable(393)
					<< "\n401: " << HashtagTable.IsInTable(401)
					<< "\t417: " << HashtagTable.IsInTable(417)
					<< "\t540: " << HashtagTable.IsInTable(540)
					<< "\t583: " << HashtagTable.IsInTable(583)
					<< "\t677: " << HashtagTable.IsInTable(677) << endl;
				HashtagTable.GetEfficiency();
				cout << endl;
				//Stops testing values of k once the first value with 0 collisions is found. Remove/comment out if you want to see all values of k for a given c.
				break;
			}
		}
	}
	exit(0);
}
