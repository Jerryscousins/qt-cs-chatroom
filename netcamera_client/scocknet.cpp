#include "scocknet.h"

scocknet::scocknet() {

    mysock = new QTcpSocket();
    connect(mysock,SIGNAL(connected()),
            this,SLOT(accept_connect()));
    mysock->connectToHost("127.0.0.1",11451);


}

void scocknet::accept_connect(){
    qDebug() << "连接!启动！";
    user_ip = mysock->peerAddress().toString();
    user_port = mysock->peerPort();
    connect(mysock,SIGNAL(readyRead()),this,SLOT(msg_read()));
}

void scocknet::msg_read(){
    QByteArray con = mysock->readAll();
    QString info = QString::fromLatin1(con, con.size());
    qDebug() << user_ip << user_port <<info;

    QStringList list = info.split("\\");
    QString mode = list.at(0);
    QString message = list.at(1);
    if(mode == "0000"){
        qDebug() << "登录";
        emit log_send(message);
    }else if(mode == "0001"){
        qDebug() << "注册";
        emit Reg_send(message);
    }else if(mode == "0010"){
        qDebug() << "更改用户名";
    }else if(mode == "0011"){
        qDebug() << "更改密码";
    }else if(mode == "0100"){
        qDebug() << "注销账号";
    }else if(mode == "1000"){
        qDebug() << "接受信息";
    }else qDebug() << "信息无法理解";
}



bool scocknet::Login(QString user_name,QString user_pw){
    QString send;
    send = "0000";
    send = send + "\\";
    send = send + user_name;
    send = send + "\\";
    send = send + user_pw;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}

bool scocknet::Reg(QString user_name,QString user_pw){
    QString send;
    send = "0001";
    send = send + "\\";
    send = send + user_name;
    send = send + "\\";
    send = send + user_pw;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}
bool scocknet::change_pw(QString user_name,QString new_pw){
    QString send;
    send = "0011";
    send = send + "\\";
    send = send + user_name;
    send = send + "\\";
    send = send + new_pw;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}
bool scocknet::change_user(QString user_name,QString new_name){
    QString send;
    send = "0010";
    send = send + "\\";
    send = send + user_name;
    send = send + "\\";
    send = send + new_name;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}
bool scocknet::deluser(QString user_name){
    QString send;
    send = "0100";
    send = send + "\\";
    send = send + user_name;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}

bool scocknet::meg_send(QString text){
    QString send;
    send = "1000";
    send = send + "\\";
    send = send + text;
    QByteArray sendb = send.toLatin1();
    mysock->write(sendb.data());
    return 0;
}
