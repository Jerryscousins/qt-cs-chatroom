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
    bool Reg(QString user_name,QString user_pw);
    bool change_user(QString user_name,QString new_name);
    bool change_pw(QString user_name,QString new_pw);
    bool deluser(QString user_name);
    bool meg_send(QString text);

    void accept_connect();
    void msg_read();
signals:
    void net_accept();
    void log_send(QString message);
    void Reg_send(QString back);
    void change_user_send(QString back);
    void change_pw_send(QString back);
    void deluser_send(QString back);
    void meg_send_send(QString back);

};

#endif // SCOCKNET_H
