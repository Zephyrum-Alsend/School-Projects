#include "Queue.h"
using namespace std;

int main(){
	Queue tst;
	tst.enqueue(5);
	tst.enqueue(10);
	tst.enqueue(15);
	tst.enqueue(20);
	tst.enqueue(25);
	tst.PrintQueue();

	tst.PrintQueue();

	tst.enqueue(5);
	tst.enqueue(10);
	tst.enqueue(15);
	tst.enqueue(20);
	tst.enqueue(25);
	tst.dequeue();
	tst.PrintQueue();

	tst.enqueue(5);
	tst.enqueue(10);
	tst.enqueue(15);
	tst.enqueue(20);
	tst.enqueue(25);
	tst.MakeEmpty();
	tst.PrintQueue();

	cout << tst.isEmpty();
	cout << true;
}