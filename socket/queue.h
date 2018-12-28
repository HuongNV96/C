/* 
 * File:   queue.h
 * Author: dangnq
 *
 * Created on February 2, 2015, 7:21 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H
template <class TYPE>
class CNode
{
public:
    TYPE m_item;
    CNode<TYPE>* m_pNext;
    CNode(TYPE item, CNode<TYPE>* pNext)
    {
        m_item = item;
        m_pNext = pNext;
    }
};

template <class TYPE>
class CQueue
{
private:
	CNode<TYPE> * m_pFirst;												
	CNode<TYPE> * m_pLast;																								
public:
	CQueue()
    {
		m_pFirst = (CNode<TYPE>*)0;
		m_pLast = (CNode<TYPE>*)0;
    }
    
	~CQueue()
    {
        CNode<TYPE> * pTemp;						// create temporary address store
        while(m_pFirst != (CNode<TYPE>*)0)			// while the queue is not empty
        {
            pTemp = m_pFirst;
            m_pFirst = m_pFirst->m_pNext;			// advance the front object to the next
            delete pTemp;					// delete the temporary data
        }
    }
    
	bool isEmpty() const
    {
        return m_pFirst == (CNode<TYPE>*)0;
    }
    
	void enqueue(const TYPE &data)
    {
        if (m_pLast != (void*)0)
        {
            m_pLast= new CNode<TYPE>(data, m_pLast);
        }
        else
        {
            m_pFirst = new CNode<TYPE>(data, (CNode<TYPE>*)0);
            m_pLast = m_pFirst;
        }
    }
    
	TYPE dequeue()
    {
        TYPE item;
        CNode<TYPE>* pTemp;
        if (m_pFirst == (CNode<TYPE>*)0)
            return (TYPE)0;
        if (m_pLast == m_pFirst)
        {
            item = m_pLast->m_item;
            delete m_pLast;
            m_pLast = (CNode<TYPE>*)0;
            m_pFirst = (CNode<TYPE>*)0;
            return item;
        }
        pTemp = m_pFirst;
        m_pFirst = m_pFirst->m_pNext;
        item = pTemp->m_item;
        delete pTemp;
        return item;
    }
};

#endif	/* QUEUE_H */

