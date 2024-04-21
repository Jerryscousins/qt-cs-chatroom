#include "firstpage.h"
#include "ui_firstpage.h"

FirstPage::FirstPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FirstPage)
{
    ui->setupUi(this);
    database = new netsql();
    connect(this,SIGNAL(goAccept()),this,SLOT(accept()));
}

FirstPage::~FirstPage()
{
    database->close();
    delete database;
    delete ui;
}

QString FirstPage::isusername(){
    return username;
}

void FirstPage::on_accept_clicked()
{
    if( database->finduser(ui->username->text(),ui->userpw->text()) ){
        username = ui->username->text();
        emit goAccept();
    }else{
        QMessageBox::about(this,"验证失败","是的孩子，这并不好笑");
    }

}

//调用子类并不会调用父类的？我还需重构
void FirstPage::closeEvent(QCloseEvent *event){
    if(!flag)emit dead();   
}

void FirstPage::accept(){
    flag = true;
    this->close();
}

void FirstPage::on_reg_clicked()
{
    ui->layout->setCurrentIndex(1);
}


void FirstPage::on_back_clicked()
{
    ui->layout->setCurrentIndex(0);
}


void FirstPage::on_reg_2_clicked()
{
    if(ui->useradd->text() != "" && ui->useraddpw1->text() != "" && ui->useraddpw1->text() == ui->useraddpw2->text()){
        if(database->find_name(ui->useradd->text()) == 1){
            database->reg(ui->useradd->text(),ui->useraddpw1->text());
            ui->username->setText(ui->useradd->text());
            ui->userpw->setText("");
            on_back_clicked();
        }else{
            QMessageBox::about(this,"注册失败","该用户名已被使用");
        }
    }else{
        QMessageBox::about(this,"注册失败","检查用户名和密码");
    }
}

