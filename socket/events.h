/*
 * Events.h
 *
 *  Created on: Oct 5, 2014
 *      Author: thuannq
 */

#ifndef EVENTS_H_
#define EVENTS_H_
#define INFINITE  0xFFFFFFFF
#include <pthread.h>
class CEvents {
public:
	CEvents(bool bAutoReset = true);
	~CEvents();
	//
	int setEvent();
	int resetEvent();
	bool waitSingleForObject(unsigned long msec);
private:
    int unlockedWaitForEvent(unsigned long msec);
private:
	pthread_mutex_t m_pMutex;
	pthread_cond_t m_pCond;
	//
	bool m_bSet;
	bool m_bAutoReset;
	//
};

#endif /* EVENTS_H_ */
