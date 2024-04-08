#ifndef SCOCKNET_H
#define SCOCKNET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <Qdebug>
#include <QTextEdit>
#include <qthread.h>

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


private slots:
    bool Login(QString user_name,QString user_pw);
    bool Reg();
    bool change_user();
    bool change_pw();
    bool deluser();

    void accept_connect();
    void msg_read();
signals:
    void net_accept();
    void log_send(QString message);
};

#endif // SCOCKNET_H
