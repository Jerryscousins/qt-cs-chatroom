#include "sonsocket.h"

sonsocket::sonsocket(QTcpSocket * mycsk)
{
    csk = mycsk;
    user_ip = csk->peerAddress().toString();
    user_port = csk->peerPort();
    database = new netsql();
}
sonsocket::~sonsocket(){
    database->close();
    delete database;
}
void sonsocket::read_all(){
    QByteArray con = csk->readAll();
    QString info = QString::fromLocal8Bit(con, con.size());
    qDebug() <<"接收信息： "<< user_ip << user_port <<info;




    QStringList list = info.split("\\");
    QString mode = list.at(0);
    if(mode == "0000"){
        qDebug() << "登录";
        if(Login(list.at(1) , list.at(2))){
            qDebug() << "登录成功";
            csk->write("0000\\1");
            csk->flush();
            chat(username + "加入了服务器");
        }else{
            qDebug() << "登录失败";
            csk->write("0000\\0");
        }

    }else if(mode == "0001"){
        qDebug() << "注册";
        if(database->find_name(list.at(1)) == 1){
            if(Reg(list.at(1) , list.at(2))){
                qDebug() << "注册成功";
                csk->write("0001\\1");
            }else{
                qDebug() << "注册失败";
                csk->write("0001\\0");
            }
        }else{
            qDebug() << "注册名占用";
            csk->write("0001\\2");
        }

    }else if(mode == "0010"){
        qDebug() << "更改用户名";
        int return_mode = change_user(list.at(1) , list.at(2));
        if(return_mode == 1){
            qDebug() << "更改用户名成功";
            csk->write("0010\\1");
            QString oldname = this->username;
            this->username = list.at(2);
            csk->flush();
            chat(oldname + "改名为" + this->username);

        }else if(return_mode == 2){
            qDebug() << "更改用户名失败";
            csk->write("0010\\2");
        }else{
            qDebug() << "用户名被抢注或着已有用户名";
            csk->write("0010\\0");
        }

    }else if(mode == "0011"){
        qDebug() << "更改密码";
        if(change_pw(list.at(1) , list.at(2))){
            qDebug() << "更改密码成功";
            csk->write("0011\\1");
        }else{
            qDebug() << "更改密码失败";
            csk->write("0011\\0");
        }

    }else if(mode == "0100"){
        qDebug() << "注销账号";
        if(deluser(list.at(1))){
            qDebug() << "注销账号成功";
            csk->write("0100\\1");
        }else{
            qDebug() << "注销账号失败";
            csk->write("0100\\0");
        }

    }else if(mode == "1000"){
        qDebug() << "接受信息";
        chat(list.at(1));
    }else qDebug() << "信息无法理解";

}

bool sonsocket::return_chat(QString name,QString time,QString msg){
    QString send;
    send = "1000";
    send = send + "\\";
    send = send + name;
    send = send + "\\";
    send = send + time;
    send = send + "\\";
    send = send + msg;
    qDebug()<<user_ip <<" " <<user_port <<" 即将发送"<<send;
    QByteArray sendb = send.toLocal8Bit();
    csk->write(sendb);
    csk->flush();
    return 0;
}


bool sonsocket::Login(QString user_name,QString user_pw){
    if(database->finduser(user_name,user_pw)){
        this->username = user_name;
        return 1;
    }
    return 0;
}

bool sonsocket::Reg(QString user_name,QString user_pw){
    if(database->reg(user_name,user_pw)){
        return 1;
    }
    return 0;
}

int sonsocket::change_user(QString user_name,QString new_name){

    if(database->find_name(new_name) == 1 && database->find_name(user_name) == 2){
        if(database->change_name(user_name,new_name)){
            return 1;
        }else{
            return 2;
        }
    }
    return 0;
}

bool sonsocket::change_pw(QString user_name,QString new_pw){
    if(database->change_pw(user_name,new_pw)){
        return 1;
    }
    return 0;
}

bool sonsocket::deluser(QString user_name){
    if(database->del(user_name)){
        return 1;
    }
    return 0;
}

bool sonsocket::chat(QString msg){
    QDateTime dateTime= QDateTime::currentDateTime();
    QString time_str = dateTime .toString("yyyy-MM-dd hh:mm:ss");
    emit only_chat(username,time_str,msg,user_ip);
    qDebug() << "内容是：" << msg;
    return 0;
}

void sonsocket::dead(){
    chat(username + "离开了服务器");
}
