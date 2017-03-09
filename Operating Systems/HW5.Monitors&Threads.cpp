//Status: Compiled without error
//Remember -std=c++11 -lpthread

#include "HW5.h"
using namespace std;

bool SafeQueue::isEmpty()
{
	int trueorfalse = sem_getvalue(&s_count, &trueorfalse);
	return trueorfalse == 0;
}

void SafeQueue::read(double &p_value)
{
	sem_wait(&s_count);
	s_lock.lock();
	p_value = s_Q[s_rhead];
	s_rhead = (s_rhead + 1) % s_QSIZE;
	s_isFull = false;
	s_lock.unlock();
	return;
}

int SafeQueue::write(double p_value)
{
	s_lock.lock();			
	//So long as Q is not full, write the value. Checks if full after incrementing write head
	if (!s_isFull)
	{
		s_Q[s_whead] = p_value;
		sem_post(&s_count);
		s_whead = (s_whead + 1) % s_QSIZE;
		if(s_whead == s_rhead)
		{
			s_isFull = true;
		}
		s_lock.unlock();
		return true;
	}
	//Write head has caught up to read head, Q is full
	s_lock.unlock();
	return false;
}
