#ifndef SCOCKNET_H
#define SCOCKNET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <Qdebug>
#include <QTextEdit>
#include <qthread.h>
#include "changeuser.h"

class scocknet:public QObject
{
    Q_OBJECT
public:
    scocknet();
    QTcpSocket *mysock;
    QTextEdit *print_text;

private:
    bool flag = 1;

    QString user_ip;
    quint16 user_port;

    changeuser *changepage;

private slots:
    bool Login(QString user_name,QString user_pw);
    bool Reg(QString user_name,QString user_pw);
    bool change_user(QString user_name,QString new_name);
    bool change_pw(QString user_name,QString new_pw);
    bool deluser(QString user_name);
    bool meg_send(QString text);

    void go_connect(QString IP,int port);
    void accept_connect();
    void msg_read();

    void change_user_main(QString name);
    void change_pw_main(QString name);
    void receive_name(QString new_name);

signals:
    void net_accept();
    void log_send(QString message);
    void Reg_send(QString back);
    void change_user_send(QString back);
    void change_pw_send(QString back);
    void deluser_send(QString back);
    void meg_send_send(QString name,QString time,QString msg);
    void updata_name(QString new_name);

};

#endif // SCOCKNET_H
