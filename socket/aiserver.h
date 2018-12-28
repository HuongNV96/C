/*
 * ipcserver.h
 *
 *  Created on: May 18, 2017
 *      Author: dangnq
 */

#ifndef AI_SERVER_H_
#define AI_SERVER_H_


#include <socket/events.h>
#include <socket/thread.h>
#include <socket/tcpserver.h>
#include <socket/tcpsocket.h>
#include <socket/mutex.h>
#define NEW_CONNECTION_INCOMMING	0
#define CLIENT_DATA_AVAIABLE		1
#define NEW_CONNNECTION_FORWARD_INCOMMING	2
#define CLIENT_FORWARD_DATA_AVAIABLE		3


class CAIServer: public CThread {
public:
	CAIServer();
	virtual ~CAIServer();
	void writeToApp(char* buffer, int size);
	void run();
private:
	CTcpServer* m_pServer;
	CTcpSocket* m_pClient;
	CMutex m_oMutex;
};

#endif /* AI_SERVER_H_ */
