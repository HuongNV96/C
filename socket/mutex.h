/*
 * Mutex.h
 *
 *  Created on: Oct 5, 2014
 *      Author: dangnq
 */

#ifndef MUTEX_H_
#define MUTEX_H_

class CMutex {
public:
	CMutex();
	~CMutex();
	//
	void lock();
	void unlock();
public:
	bool m_bCreated;
private:
	pthread_mutex_t m_pMutex;
};

class CMutexLocker{
public:
	CMutexLocker(CMutex* pMutex)
	{
		m_pMutex = pMutex;
		m_pMutex->lock();
	}
	~CMutexLocker()
	{
		m_pMutex->unlock();
	}
private:
	CMutex* m_pMutex;
	};
#endif /* MUTEX_H_ */
