//Lab 10 - semi-perfect hash
//Lucas Crockett
//Status: Working

#pragma once
using namespace std;

class RCHash
{
public:
	RCHash(int tableSize, int x);
	~RCHash();

	//Adds a value to the hash table. Returns an (nonsensical) error message if the table is full and terminates the program.
	void AddToTable(int val);

	//Checks if a value is in the hash table using code similar to AddToTable. Returns -1 if not found.
	int IsInTable(int val);

	//Displays percentage of table filled and the number of collisions.
	void GetEfficiency();

	//Retrieves number of collisions. Primarily for testing.
	int GetCollisions();

private:
	int *hashTable;
	int capacity;	//Total size of the hash table.
	int size;		//How many slots are filled.
	int collisions;
	int k;

	//Hashes a value.
	int hashf(int val);
};


