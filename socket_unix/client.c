#include "client.h"

const char * socket_path = "\0hidden";

void initClientSocket(PClientSocket pClient) {
    pClient->m_sockfd=-1;
    pClient->m_isConnected=false;
}
bool connectToServer(PClientSocket pClient) {
    struct sockaddr_un addr; 
    pClient->m_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(pClient->m_sockfd < 0) {
        return false;
    } 
    //connect to server
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    if (*socket_path == '\0') {
        *addr.sun_path = '\0';
        strncpy(addr.sun_path+1, socket_path+1, sizeof(addr.sun_path)-2);
    } else {
        strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    }
	if (connect(pClient->m_sockfd, (struct sockaddr *)&addr, sizeof(addr)) <0) {
        close(pClient->m_sockfd);
        pClient->m_sockfd = -1;
        return false;
	}
    pClient->m_isConnected = true;
    return true;
}
void disconnect(PClientSocket pClient) {
    if (pClient->m_sockfd == -1)
        return;
    close(pClient->m_sockfd);
    pClient->m_sockfd = -1;
    pClient->m_isConnected= false;
}
bool isConnected(PClientSocket pClient) {
    return pClient->m_isConnected;
}
bool writeData(PClientSocket pClient,char* pData, int nSize) {
    int nTotal = 0;
    int nSend = 0;
    do {
        nSend = send(pClient->m_sockfd , pData + nTotal , nSize - nTotal, 0);
        nTotal += nSend;
    } while (nSend > 0 && nTotal < nSize);
    return (nTotal == nSize);
    //check sum
    pClient->m_isConnected = (nTotal == nSize);
    if (!pClient->m_isConnected)
        disconnect(pClient);
    return (nTotal == nSize);
}
int bytesAvailable(PClientSocket pClient) {
    int nBytesAvailable;
    if (ioctl(pClient->m_sockfd, FIONREAD, &nBytesAvailable) == -1) {
        return -1;
    }
    return nBytesAvailable;
}
int readData(PClientSocket pClient,char* pData, int nSize) {
    int nBytesAvailable = bytesAvailable(pClient);
    if (nBytesAvailable <= 0)
        return 0;
    if (nSize > nBytesAvailable)
        nSize = nBytesAvailable;
    nSize = recv(pClient->m_sockfd, pData, nSize, 0);
    return nSize;
}