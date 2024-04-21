#ifndef NETSQL_H
#define NETSQL_H


#include <qsqldatabase.h>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

class netsql
{
public:
    netsql();
    ~netsql();
    bool finduser(QString user,QString passwd);
    void close();
    bool reg(QString name , QString passwd);
    int del(QString name);
    int size();
    int find_name(QString name);
    bool change_name(QString name,QString new_name);
    bool change_pw(QString name,QString new_pd);


private:
    QSqlDatabase key;
    QSqlQuery *sql_query;
    void ini();

};

#endif // NETSQL_H
