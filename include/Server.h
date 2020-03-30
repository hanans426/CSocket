//
// Created by 高涵 on 2020-03-25.
//

//#ifndef CSOCKET_SERVER_H
//#define CSOCKET_SERVER_H

#include <string>

#include "socketUtil.h"

//using namespace std;
using std::list;

class Server{

public:
    Server();

    void Init();

    void Close();

    void Start();

private:

    int SendMsg();

    struct sockaddr_in serverAddr; //服务器端的server addr

    int listener;

    list<int> clients_list;



};
