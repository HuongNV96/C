/* 
 * File:   tcpserver.h
 * Author: dangnq
 *
 * Created on January 31, 2015, 8:46 PM
 */
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef TCPSERVER_H
#define	TCPSERVER_H

class CTcpServer {
public:
    CTcpServer();
    virtual ~CTcpServer();
    bool waitForNewConnection(int nMSecond);
    int acceptConnection(struct sockaddr_in& stAddr);
    bool listenConnection(char* szServer, unsigned short nPort, int nMaxClient);
private:
    int m_hServer;
} ;

#endif	/* TCPSERVER_H */

