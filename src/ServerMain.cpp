//
// Created by 高涵 on 2020-03-26.
//

#include "Server.h"
#include "QApplication"
#include "QWidget"

int main(int argc, char* argv[]) {
     Server server;
     server.Start();

    QApplication serverApp(argc, argv);
    QWidget serverWidget;
    serverWidget.setWindowTitle("server");
    serverWidget.show();


    return serverApp.exec();

}
