#ifndef SCOCKNET_H
#define SCOCKNET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QString>
#include <sonsocket.h>


class scocknet : public QObject
{
    Q_OBJECT
public:
    scocknet();
    QTcpServer *myser;
    QList <QTcpSocket *> myclis;
    QList <sonsocket *> mysons;

    QTextEdit *print_text;

private:

private slots:
    void accept_connect();
    void listen_read();
    void go_chat(QString name,QString time,QString msg,QString user_ip);
    void all_return_chat(QString name,QString time,QString msg,QString user_ip);
signals:
    void all_chat(QString name,QString time,QString msg,QString user_ip);
};

#endif // SCOCKNET_H
