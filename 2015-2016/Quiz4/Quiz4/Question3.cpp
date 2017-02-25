#include <iostream>
using namespace std;
int hashf(double x, int &increment);

bool InHashTable(const double x){
	int increment = 0;
	int ind = hashf(x, increment);
	int indcopy = ind;

	if (ht[ind].empty()){
		return false;
	}
	if (ht[ind] == x){
		return true;
	}
	ind = (ind + increment) % capacity;
	while (ind != indcopy){
		if (ht[ind] == x){
			return true;
		}
		ind = (ind + increment) % capacity;
	}
	return false;
}