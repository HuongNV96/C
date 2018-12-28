/* 
 * File:   tcpsocket.h
 * Author: dangnq
 *
 * Created on January 31, 2015, 9:18 PM
 */

#ifndef TCPSOCKET_H
#define	TCPSOCKET_H
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

class CTcpSocket 
{
public:
    CTcpSocket(int hSocket);
    CTcpSocket();
    virtual ~CTcpSocket();
    bool write(char* pData, int nSize);
    bool write(const char* pData, int nSize);
    int read(char* pData, int nSize);
    int read(unsigned char* pData, int nSize);
    int bytesAvailable() const;
    bool waitForReadyRead(int nMSecond = 3000);
    bool waitForBytesWritten(int nMSecond = 3000);
    void disconnect();
    bool connectToServer(char* szServer, unsigned short nPort);
    bool isConnected();
private:
    int m_hSocket;
    bool m_bIsConnected;
} ;

#endif	/* TCPSOCKET_H */

