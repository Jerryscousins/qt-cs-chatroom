#include "netsql.h"


netsql::netsql() {

    if(QSqlDatabase::contains("netsql")){
        key = QSqlDatabase::database("netsql");
    }else{
        key = QSqlDatabase::addDatabase("QSQLITE","netsql");
        key.setDatabaseName("netsql.db");
    }

    if(key.open()){
        qDebug() << "数据库已打开";
        sql_query = new QSqlQuery(key);
        QString findtable = "SELECT name FROM sqlite_master WHERE type='table' AND name='userpw' ";
        sql_query->prepare(findtable);

        if(sql_query->exec()){
            if(sql_query->next()){
                qDebug() << "查询到已初始化";
            }else{
                qDebug() << "无法查询到表格";
                ini();
            }
        }else{
            qDebug() << "查询表格操作失败";
            qDebug() << sql_query->lastError().text();
        }
    }else{
        qDebug() << "数据库未打开";
    }
}

void netsql::ini(){

    QString creat_sql = "create table userpw (id INTEGER primary key AUTOINCREMENT, user text, passwd text)";
    sql_query->prepare(creat_sql);
    if(sql_query->exec()){
        qDebug() << "创建成功";

        QString sql_insert = QString("insert into userpw (user,passwd) values('%1','%2')").arg("root").arg("123456");
        sql_query->prepare(sql_insert);
        if(sql_query->exec()){
            qDebug() << "初始化插入成功";
        }else{
            qDebug() << "初始化插入失败";
            qDebug() << sql_query->lastError().text();
        }

    }else{
        qDebug() << "创建失败";
        qDebug() << sql_query->lastError().text();
    }
}

int netsql::find_name(QString name){
    sql_query->prepare("select *from userpw where user=?");
    sql_query->addBindValue(name);
    if(sql_query->exec()){
        qDebug() << "查询行为正常";
        if(sql_query->next()){
            qDebug() << name << "查询存在名称";
            return 2;
        }else{
            qDebug() << name << "未查询到名称";
            return 1;
        }
    }else{
        qDebug() << "查询出错";
        qDebug() << sql_query->lastError().text();
    }
    return 0;
}

bool netsql::finduser(QString user,QString passwd){
    sql_query->prepare("select *from userpw where user=? and passwd=?");
    sql_query->addBindValue(user);
    sql_query->addBindValue(passwd);
    if(sql_query->exec()){
        qDebug() << "查询行为正常";
        if(sql_query->next()){
            qDebug() << "查询通过";
            return 1;
        }else{
            qDebug() << "查询失败";
        }
    }else{
        qDebug() << "查询出错";
        qDebug() << sql_query->lastError().text();
    }
    return 0;
}


void netsql::close(){
    if(key.isOpen()){
        key.close();
    }
}

int netsql::size(){
    QString sql_only = "SELECT COUNT(*) FROM userpw";
    sql_query->prepare(sql_only);
    sql_query->exec();
    if(sql_query->next()){
        int num = sql_query->value(0).toInt();
        qDebug() << "存在" << num <<"条数据";
        return num;
    }else{
        qDebug() << "无数据";
    }
    return -1;
}

int netsql::del(QString name){
    if(name == ""){
        qDebug() << "尚未登陆";
        return 0;
    }

    QString sql_del = QString("delete from userpw where user = '%1'").arg(name);
    sql_query->prepare(sql_del);
    if(sql_query->exec()){
        qDebug() << "删除" << name <<"成功";
        return 1;
    }else{
        qDebug() << "删除失败";
        qDebug() << sql_query->lastError().text();
        return 0;
    }
}

bool netsql::reg(QString name , QString passwd){
    QString insert_sql = QString("insert into userpw (user,passwd) values('%1','%2')").arg(name).arg(passwd) ;
    sql_query->prepare(insert_sql);
    if(sql_query->exec()){
        qDebug() << "注册成功";
        return 1;
    }else{
        qDebug() << "注册失败";
        qDebug() << sql_query->lastError().text();
    }
    return 0;
}

bool netsql::change_pw(QString name,QString passwd){
    QString changepw_sql = QString("UPDATE userpw SET passwd = '%1' WHERE user = '%2'").arg(passwd).arg(name);
    sql_query->prepare(changepw_sql);
    if(sql_query->exec()){
        qDebug() << "修改" << name << "密码成功";
        return 1;
    }else{
        qDebug() << "修改密码失败";
        qDebug() << sql_query->lastError().text();
    }
    return 0;
}

bool netsql::change_name(QString name,QString new_name){
    QString changepw_sql = QString("UPDATE userpw SET user = '%1' WHERE user = '%2'").arg(new_name).arg(name);
    sql_query->prepare(changepw_sql);
    if(sql_query->exec()){
        qDebug() << "修改" << name << "账号" << new_name <<"成功";
        return 1;
    }else{
        qDebug() << "修改账号失败";
        qDebug() << sql_query->lastError().text();
    }
    return 0;
}

netsql::~netsql(){
    key.close();
}
