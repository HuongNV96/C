#ifndef _CLIENT_SOCKET_H_
#define	_CLIENT_SOCKET_H_

#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdbool.h>

typedef struct tagClientSocket {
    int m_sockfd;
    bool m_isConnected;
}ClientSocket,*PClientSocket;

void initClientSocket(PClientSocket pCLient);
bool connectToServer(PClientSocket pCLient);
void disconnect(PClientSocket pCLient);
bool isConnected(PClientSocket pCLient);
bool writeData(PClientSocket pCLient,char* pData, int nSize);
int  bytesAvailable();
int  readData(PClientSocket pCLient,char* pData, int nSize);


#endif	/* _CLIENT_SOCKET_H_ */