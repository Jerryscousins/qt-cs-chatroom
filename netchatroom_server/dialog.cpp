#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    firstpage1 = new FirstPage(this);
    firstpage1->show();

    connect(firstpage1,SIGNAL(goAccept()),this,SLOT(getCamera()));
    connect(firstpage1,SIGNAL(dead()),this,SLOT(allclose()));

}

Dialog::~Dialog()
{
    delete ui;
    delete changeuser1;
}

void Dialog::change_name(QString new_name){
    username = new_name;
    ui->name->setText(username);
}

void Dialog::allopen(){
    username = firstpage1->isusername();

    changeuser1 = new changeuser(username,this);
    headsocket = new scocknet();
    database = new netsql();

    connect(changeuser1,SIGNAL(change_name_sign(QString)),this,SLOT(change_name(QString)) );
    connect(changeuser1,SIGNAL(updata_name()),this,SLOT(updata_name_s()) );
    connect(this,SIGNAL(updata_name_p(QString)),changeuser1,SLOT(updata_name_adirve(QString)));

    connect(headsocket,SIGNAL(all_chat(QString,QString,QString,QString)),this,SLOT(text_msg(QString,QString,QString)));
    ui->active->setText("服务器开始运行");

    //设置图层状态
    ui->name->setText(username);
    ui->deleteuser->setEnabled(true);
    ui->changename->setEnabled(true);
    ui->changepw->setEnabled(true);
}

void Dialog::getCamera(){
    allopen();
}

void Dialog::allclose(){
    this->close();
}


void Dialog::on_deleteuser_clicked()
{
    if(!database->del(username)){
        QMessageBox::about(this,"攻击物是水滴","无法删除！");
    }else{
        QMessageBox::about(this,"敵将打ち取ったり","删除！");
        this->close();
    }
}


void Dialog::on_changename_clicked()
{
    changeuser1->change_user_mode();
    changeuser1->show();
}

void Dialog::text_msg(QString name, QString time, QString msg){
    QString all = ui->active->toPlainText();
    all += "\n" + time ;
    all += " " + name + ":\n";
    all += msg + "";
    ui->active->setText(all);
}

void Dialog::on_changepw_clicked()
{
    changeuser1->change_pw_mode();
    changeuser1->show();
}

void Dialog::updata_name_s(){
    emit updata_name_p(username);
}
