//
// Created by 高涵 on 2020-03-25.
//


#include <iostream>

#include "Client.h"

using std::cout;
using std::cin;
using std::endl;

Client::Client() {

    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    sock = 0;
    pid = 0;
    isClientwork = true;

}

void Client::Connect() {
    cout << "Connect Server: " << SERVER_IP << " : " << SERVER_PORT << endl;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock <0){
        perror("socket error");
        exit(-1);
    }

    if(connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0){
      perror("connect error");
      exit(-1);
    }

    // 创建管道，其中fd[0]用于父进程读，fd[1]用于子进程写
    if(pipe(pipe_fd)<0){
        perror("pipe error");
        exit(-1);
    }

}

void Client::Close() {
    if(pid){
        close(pipe_fd[0]);
        close(sock);
    } else {
        close(pipe_fd[1]);
    }
}

void Client::Start() {
    Connect();

    char send_buf[BUFF_SIZE];
    char accept_buf[BUFF_SIZE];

    while(1){
        cout<<"input your message:"<<endl;
        cout<<endl;
        cin>>send_buf;
        int res_len = send(sock,send_buf,100,0);
        if(res_len<0)
        {
            cout<<"error"<<endl;
        }
        cout<<"发送成功,等待接受"<<endl;
        recv(sock, accept_buf, 200, 0);
        cout<<"服务端消息: "<<accept_buf<<endl;

    }
    Close();

}