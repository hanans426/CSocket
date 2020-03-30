//
// Created by 高涵 on 2020-03-25.
//

//#include "QApplication"
//#include "QWidget"
#include "Server.h"
#include  <iostream>

//using namespace std;
using std::cout;
using std::endl;
using std::list;
using std::cin;
//using std::string;

Server::Server() {
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    listener = 0; //初始化socket
}

void Server::Init() {
    cout << "Init Server..." << endl;

    listener = socket(PF_INET, SOCK_STREAM, 0); //初始化socket
    if(listener < 0){
        perror("listener");
        exit(-1);
    }

    //绑定地址
    if(bind(listener, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("bind error");
        exit(-1);
    }

    //设置监听
    int ret = listen(listener, 5);
    if(ret < 0) {
        perror("listen error");
        exit(-1);
    }
    cout << "Start to listen: " << SERVER_IP << endl;

}

// 关闭服务，清理并关闭文件描述符
void Server::Close() {

    //关闭socket
    close(listener);
}

int Server::SendMsg() {
    struct sockaddr_in clinet_addr;   //用于获取客户端地址端口信息 用于回传
    socklen_t len=sizeof(struct sockaddr_in); //用于接收客户端的地址信息和端口信息，用于回传。
    int s_accept = accept(listener,(struct sockaddr*)&clinet_addr,&len);
    //在这里阻塞 挂起等待

    if( s_accept == -1  ){
        cout<<"connect error"<<endl;
    }
    cout<<"connection is OK;ready to accept"<<endl;
    char recv_buf[BUFF_SIZE];
    char send_buf[BUFF_SIZE];

    while(1){
        int recv_len= recv(s_accept,recv_buf,100,0);
        //这里 即使链接断开 也能继续监听 服务端不关闭
        if(recv_len<0)
        {
            cout<<"listen********************"<<endl;
            s_accept = accept(listener,(struct sockaddr*)&clinet_addr,&len);
            //在这里阻塞 挂起等待
            continue;
            if( s_accept == -1  )
            {
                cout<<"connect error"<<endl;
            }
        }
        cout<<"客户端消息："<<recv_buf<<endl;


        cout<<"输入服务端消息\n"<<endl;
        cin>>send_buf;
        send(s_accept,send_buf,100,0);
        cout<<"发送成功"<<endl<<endl;


    }
}

void Server::Start() {

    Init();
    SendMsg();


//   while(1){


//   }
}






