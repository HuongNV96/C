/*
 * Thread.h
 *
 *  Created on: Oct 5, 2014
 *      Author: thuannq
 */

#ifndef THREAD_H_
#define THREAD_H_

typedef  void* CALLBACK;
#include <pthread.h>
class CThread {
public:
	CThread(bool bAutoDelete = true);
	virtual ~CThread();
	pthread_t getThreadID();
	void start();
	virtual void exit();
	virtual bool exitWait(int timeout);
	void abort();
protected:
    virtual void run();
	bool wait(int timeout);
	bool exitPending();
	static CALLBACK threadProc(void* parameter);
protected:
	pthread_t m_hThreadId;
	CEvents m_oExitEvent;
    bool m_bAutoDelete;
};

#endif /* THREAD_H_ */
