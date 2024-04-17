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
    connect(firstpage1,SIGNAL(dead()),this,SLOT(all_close()));
    connect(firstpage1,SIGNAL(go_connect_tcp(QString,int)),client_socket,SLOT(go_connect(QString,int)));

    connect(firstpage1,SIGNAL(go_Log(QString,QString)),client_socket,SLOT(Login(QString,QString)));
    connect(firstpage1,SIGNAL(go_Reg(QString,QString)),client_socket,SLOT(Reg(QString,QString)));

    connect(client_socket,SIGNAL(log_send(QString)),firstpage1,SLOT(log_return(QString)));
    connect(client_socket,SIGNAL(Reg_send(QString)),firstpage1,SLOT(Reg_return(QString)));

    connect(this,SIGNAL(go_meg_send(QString)),client_socket,SLOT(meg_send(QString)));

}


void Dialog::all_open(){
    user_name = firstpage1->isusername();
    ui->username->setText(user_name);
    ui->pushButton->setEnabled(true);
    ui->scrollArea->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->textEdit->setEnabled(true);
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
    if(ui->textEdit->toPlainText() != ""){
        emit go_meg_send(ui->textEdit->toPlainText());
        ui->textEdit->setPlainText("");
    }else{
        QMessageBox::about(this,"不可不可","怎能发送空白问题");
    }
}


void Dialog::change_user_return(QString back){

}

void Dialog::change_pw_return(QString back){

}
void Dialog::deluser_return(QString back){

}
void Dialog::meg_return(QString back){

}
