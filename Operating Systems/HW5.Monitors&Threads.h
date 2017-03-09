#pragma once
//Status: Compiled without error

#include <mutex>
#include <semaphore.h>
using namespace std;

class SafeQueue
{
public:
	SafeQueue()
	{
		s_whead = 0;
		s_rhead = 0;
		sem_init(&s_count, 0, 0);
		s_isFull = false;
	}
	
	bool isEmpty();
	void read(double &p_value);
	int write(double p_value);

private:
	static const int s_QSIZE = 6;
	mutex s_lock;
	double s_Q[s_QSIZE];	//"Queue" Q
	int s_whead;	//write head
	int s_rhead;	//read head
	sem_t s_count;	//semaphore
	bool s_isFull;	//flag for write function
};
