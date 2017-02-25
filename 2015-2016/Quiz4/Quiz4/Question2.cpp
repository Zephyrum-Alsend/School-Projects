#include <iostream>
#include <algorithm>
using namespace std;
class Roster{
public:

	Roster(const int x){
		StudentTable *st = new StudentTable[x];
		size = x;
	}

	struct StudentTable{
		char name[31];
		int age;
		double gpa;
	};

	bool Roster::LessThan(StudentTable *st1, StudentTable *st2){
		double GPA1 = st1->gpa;
		double GPA2 = st2->gpa;
		return !(GPA1 < GPA2);
	}

	void Roster::SortList(){
		sort(&st[0], &st[5000]);
	}

//	Roster Roster::operator < (StudentTable st1.gpa, StudentTable st2.gpa){
//
//	}
private:
	int size;
};
struct StudentTable{
	char name[31];
	int age;
	double gpa;
};

int main(){
	Roster st(5000);
}