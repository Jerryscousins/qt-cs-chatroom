#include "changeuser.h"
#include "ui_changeuser.h"

changeuser::changeuser(QString fname,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeuser)
{
    database = new netsql();
    name = fname;
    ui->setupUi(this);

}


void changeuser::change_user_mode(){
    ui->stackedWidget->setCurrentIndex(0);
}

void changeuser::change_pw_mode(){
    ui->stackedWidget->setCurrentIndex(1);
}

changeuser::~changeuser()
{
    delete ui;
}

void changeuser::on_acceptname_clicked()
{
    emit updata_name();
    if(ui->newname->text() != "" && (database->find_name(ui->newname->text()) == 1) && (database->find_name(name) == 2)){
        database->change_name(name,ui->newname->text());
        name = ui->newname->text();
        QMessageBox::about(this,name,"已加冕为王");
        emit change_name_sign(name);

        this->close();
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}

void changeuser::on_acceptpw_clicked()
{
    emit updata_name();
    if(ui->newpw->text() != "" && ui->newpw2->text() == ui->newpw->text()){
        database->change_pw(name,ui->newpw->text());
        QMessageBox::about(this,"君の密钥","已经变成只有我们两个人知道的秘密");
        this->close();
    }else{
        QMessageBox::about(this,"存在错误","请检查填写内容");
    }
}

void changeuser::updata_name_adirve(QString new_name){
    name = new_name;
}
