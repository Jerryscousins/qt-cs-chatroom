#include "firstpage.h"
#include "ui_firstpage.h"

FirstPage::FirstPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FirstPage)
{
    ui->setupUi(this);
    connect(this,SIGNAL(goAccept()),this,SLOT(accept()));
}

FirstPage::~FirstPage()
{
    delete ui;
}

void FirstPage::net_open(){
    ui->layout->setCurrentIndex(0);
}

QString FirstPage::isusername(){
    return username;
}

void FirstPage::on_accept_clicked()
{

    if(ui->username->text()!="" && ui->userpw->text() != ""){
        emit go_Log(ui->username->text(),ui->userpw->text());
    }else{
        QMessageBox::about(this,"莫是在消遣洒家","怎是屏幕上空空如也");
    }
}

void FirstPage::on_pushButton_clicked()
{
    qDebug() << "发起连接通告" ;

    emit go_connect_tcp(ui->ip_edit->text(),ui->port_edit->text().toInt());
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
        emit go_Reg(ui->useradd->text(),ui->useraddpw1->text());
    }else{
        QMessageBox::about(this,"注册失败","检查用户名和密码");
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

void FirstPage::log_return(QString message){
    if( message == "1" ){
        username = ui->username->text();
        emit goAccept();
    }else{
        QMessageBox::about(this,"验证失败","是的孩子，这并不好笑");
    }
}

void FirstPage::Reg_return(QString back){
    if(back == "1"){
        QMessageBox::about(this,"新的记忆涌入","带来了生命和希望");
        ui->username->setText(ui->useradd->text());
        ui->userpw->setText("");
        on_back_clicked();
    }else if(back == "2"){
        QMessageBox::about(this,"注册失败","该用户名已被使用");
    }else if(back == "0"){
        QMessageBox::about(this,"注册失败","无效的呈递");
    }

}



