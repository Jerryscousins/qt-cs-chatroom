#include "scocknet.h"

scocknet::scocknet() {

    mysock = new QTcpSocket();
    connect(mysock,SIGNAL(connected()),
            this,SLOT(accept_connect()));
    connect(mysock,SIGNAL(connected()),
            this,SLOT(msg_write()));
    mysock->connectToHost("127.0.0.1",11451);


}


void scocknet::accept_connect(){
    qDebug() << "连接!启动！";
}
void scocknet::msg_write(){
    mysock->write("连接！充分");
}
void scocknet::msg_read(){

}
