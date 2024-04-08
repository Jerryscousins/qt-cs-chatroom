#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->show();
    firstpage1 = new FirstPage();
    firstpage1->show();
    client_socket = new scocknet();
    connect(firstpage1,SIGNAL(goAccept()),this,SLOT(all_open()));
    connect(client_socket,SIGNAL(net_accept()),firstpage1,SLOT(net_open()));
    connect(firstpage1,SIGNAL(go_Log(QString,QString)),client_socket,SLOT(Login(QString,QString)));
    connect(firstpage1,SIGNAL(dead()),this,SLOT(all_close()));

    connect(client_socket,SIGNAL(log_send(QString)),firstpage1,SLOT(log_return(QString)));
}


void Dialog::all_open(){

}

void Dialog::all_close(){
    this->close();
}

Dialog::~Dialog()
{
    delete firstpage1;
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

}
