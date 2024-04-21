#ifndef SONSOCKET_H
#define SONSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QString>
#include <QTime>

#include "netsql.h"

class sonsocket : public QObject
{
    Q_OBJECT
public:
    explicit sonsocket(QTcpSocket * mycsk);
    ~sonsocket();
    bool return_chat(QString name,QString time,QString msg);

private:
    QString username;
    QString user_ip;
    quint16 user_port;
    QTcpSocket *csk;
    netsql *database;

    bool Login(QString user_name,QString user_pw);
    bool Reg(QString user_name,QString user_pw);
    int change_user(QString user_name,QString new_name);
    bool change_pw(QString user_name,QString new_pw);
    bool deluser(QString user_name);

    bool chat(QString msg);
signals:
    void only_chat(QString name,QString time,QString msg,QString user_ip);
private slots:
    void read_all();
    void dead();

};

#endif // SONSOCKET_H
