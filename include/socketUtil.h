
#pragma once
//
//#ifdef _WIN32
//#include <winsock2.h>
//#include <WS2tcpip.h>
//#else
//#include <arpa/inet.h>
//#define SOCKET int
//#define INVALID_SOCKET (SOCKET)(~0)
//#define SOCKET_ERROR		   (-1)

//#ifndef CSOCKET_SERVER_H
//#define CSOCKET_SERVER_H

#ifdef _WIN32
#include <winsock2.h>
#include <WS2tcpip.h>
#else
#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unixbase.h"



#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define EPOLL_SIZE 5000
#define BUFF_SIZE 65535


#define CAUTION "There is only one int the char room!"


// 其他用户收到消息的前缀
#define SERVER_MESSAGE "ClientID %d say >> %s"
#define SERVER_PRIVATE_MESSAGE "Client %d say to you privately >> %s"
#define SERVER_PRIVATE_ERROR_MESSAGE "Client %d is not in the chat room yet~"
// 退出系统
#define EXIT "EXIT"

struct Msg{
    int type;
    int fromId;
    int toId;
    char content[BUFF_SIZE];
};

//static void addfd(int epollfd, int fd, bool enable_et){
//    struct epoll_event ev;
//    ev.
//}

//void cleanWSA();
//void cleanSocket(SOCKET s);
//int startupWSA();
//void setSocketAddr(sockaddr_in* addr, const char* ip);


#endif
