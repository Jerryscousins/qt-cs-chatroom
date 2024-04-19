#include "scocknet.h"

scocknet::scocknet() {
    mysock = new QTcpSocket();
    changepage = new changeuser("",nullptr);
}

void scocknet::go_connect(QString IP,int port){
    qDebug() << "连接!启动！" <<IP << port;
    connect(mysock,SIGNAL(connected()),
            this,SLOT(accept_connect()));
    mysock->connectToHost(IP,port);
}

void scocknet::accept_connect(){
    qDebug() << "连接!大成！";
    user_ip = mysock->peerAddress().toString();
    user_port = mysock->peerPort();
    connect(mysock,SIGNAL(readyRead()),this,SLOT(msg_read()));

    connect(changepage,SIGNAL(go_change_username(QString,QString)),this,SLOT(change_user(QString,QString)));
    connect(changepage,SIGNAL(go_change_pw(QString,QString)),this,SLOT(change_pw(QString,QString)));
    connect(changepage,SIGNAL(updata_name(QString)),this,SLOT(receive_name(QString)));

    connect(this,SIGNAL(change_user_send(QString)),changepage,SLOT(return_change_username(QString)));
    connect(this,SIGNAL(change_pw_send(QString)),changepage,SLOT(return_change_pw(QString)));


    emit net_accept();
}

void scocknet::msg_read(){
    QByteArray con = mysock->readAll();
    QString info = QString::fromLocal8Bit(con, con.size());
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
        emit change_user_send(message);
    }else if(mode == "0011"){
        qDebug() << "更改密码";
        emit change_pw_send(message);
    }else if(mode == "0100"){
        qDebug() << "注销用户";
        emit deluser_send(message);
    }else if(mode == "1000"){
        qDebug() << "接受信息";
        emit meg_send_send(message,list.at(2),list.at(3));
    }else qDebug() << "信息无法理解";
}

void scocknet::change_user_main(QString name){


   changepage->change_user_mode();
   changepage->change_name(name);
   changepage->show();

}

void scocknet::change_pw_main(QString name){

    changepage->change_pw_mode();
    changepage->change_name(name);
    changepage->show();
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
    QByteArray sendb = send.toLocal8Bit();
    mysock->write(sendb.data());
    return 0;
}

void scocknet::receive_name(QString new_name){
    emit updata_name(new_name);
}
