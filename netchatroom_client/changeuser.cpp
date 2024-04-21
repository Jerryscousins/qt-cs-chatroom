#include "changeuser.h"
#include "ui_changeuser.h"

changeuser::changeuser(QString fname,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeuser)
{
    name = fname;
    ui->setupUi(this);

}


void changeuser::change_user_mode(){
    ui->stackedWidget->setCurrentIndex(0);
}

void changeuser::change_pw_mode(){
    ui->stackedWidget->setCurrentIndex(1);
}

void changeuser::change_name(QString newname){
    name = newname;
}

changeuser::~changeuser()
{
    delete ui;
}

void changeuser::on_acceptname_clicked()
{
    if(ui->newname->text() != ""){
        emit go_change_username(name,ui->newname->text());
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}

void changeuser::return_change_username(QString msg){
    if(msg == "1"){
        name = ui->newname->text();
        emit updata_name(name);
        QMessageBox::about(this,name,"已加冕为王");
        this->close();
    }else if(msg == "2"){
        QMessageBox::about(this,"撞车!","另起炉灶！");
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}

void changeuser::return_change_pw(QString msg){
    if(msg == "1"){
        QMessageBox::about(this,"君の密钥","已经变成只有我们两个人知道的秘密");
        this->close();
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}
void changeuser::on_acceptpw_clicked()
{
    if(ui->newpw->text() != "" && ui->newpw2->text() == ui->newpw->text()){
        emit go_change_pw(name,ui->newpw->text());
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}
