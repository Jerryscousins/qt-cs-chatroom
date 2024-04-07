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
private slots:
    void accept_connect();
    void msg_write();
    void msg_read();
};

#endif // SCOCKNET_H
