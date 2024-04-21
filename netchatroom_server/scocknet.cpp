#include "scocknet.h"

scocknet::scocknet() {
    print_text = new QTextEdit();

    myser = new QTcpServer();
    myser->listen(QHostAddress::AnyIPv4,11451);
    myclis.clear();
    mysons.clear();

    connect(myser,SIGNAL(newConnection()),this,SLOT(accept_connect()));
    qDebug() << "监听已开始";

}

void scocknet::accept_connect(){
    qDebug() << "新的子群已汇入";
    QTcpSocket * mycsk = myser->nextPendingConnection();
    sonsocket * my_socket = new sonsocket(mycsk);
    myclis.append(mycsk);
    mysons.append(my_socket);
    connect(my_socket,SIGNAL(only_chat(QString,QString,QString,QString)),this,SLOT(go_chat(QString,QString,QString,QString)));
    connect(my_socket,SIGNAL(only_chat(QString,QString,QString,QString)),this,SLOT(all_return_chat(QString,QString,QString,QString)));
    connect(mycsk,SIGNAL(readyRead()),my_socket,SLOT(read_all()));
    connect(mycsk,SIGNAL(disconnected()),my_socket,SLOT(dead()));
}

void scocknet::go_chat(QString name,QString time,QString msg,QString user_ip){
    emit all_chat(name,time,msg,user_ip);
    return;
}

void scocknet::all_return_chat(QString name,QString time,QString msg,QString user_ip){
    for (int i = 0; i < mysons.size(); i++) {
        mysons.at(i)->return_chat(name,time,msg);
    }
    return;
}
