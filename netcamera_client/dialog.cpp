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
    connect(client_socket,SIGNAL(deluser_send(QString)),this,SLOT(deluser_return(QString)));
    connect(client_socket,SIGNAL(meg_send_send(QString,QString,QString)),this,SLOT(meg_return(QString,QString,QString)));

    connect(this,SIGNAL(go_meg_send(QString)),client_socket,SLOT(meg_send(QString)));
    connect(this,SIGNAL(go_change_pw(QString)),client_socket,SLOT(change_pw_main(QString)));
    connect(this,SIGNAL(go_change_user(QString)),client_socket,SLOT(change_user_main(QString)));
}


void Dialog::all_open(){
    user_name = firstpage1->isusername();
    ui->username->setText(user_name);
    ui->pushButton->setEnabled(true);
    ui->toolButton->setEnabled(true);
    ui->textEdit->setEnabled(true);
    ini_user();
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
void Dialog::ini_user(){
    change_pw_c = ui->toolButton->addAction("更改密码");
    change_user_c = ui->toolButton->addAction("更改用户名");
    del_user_c = ui->toolButton->addAction("删除用户");
    connect(ui->toolButton,SIGNAL(triggered(QAction*)),this,SLOT(tool_accept(QAction *)));

    connect(this,SIGNAL(go_deluser(QString)),client_socket,SLOT(deluser(QString)));
    connect(client_socket,SIGNAL(updata_name(QString)),this,SLOT(updata_name(QString)));
}

void Dialog::tool_accept(QAction * mode){
    if(mode == change_pw_c){
        emit go_change_pw(user_name);
    }else if(mode == change_user_c){
        emit go_change_user(user_name);
    }else if(mode == del_user_c){
        emit go_deluser(user_name);
    }else{
        qDebug() << "选的钩子？";
    }
}

void Dialog::deluser_return(QString back){
    if(back == "1"){
        qDebug() << "注销账号成功";
        QMessageBox::about(this,"你好","再见");
        this->close();
    }else{
        qDebug() << "注销失败";
        QMessageBox::about(this,"我们之间的羁绊","可不要小看啊！");
    }
}

void Dialog::meg_return(QString name,QString time,QString msg){

    QWidget * areas = ui->scrollarea;
    QLabel *text1 = new QLabel(areas);
    text1->setText(QString(time + " " + name + ":"));
    text1->setGeometry(QRect(10,20+m_iLabNum*22,500,15));
    text1->setVisible(true);
    m_iLabNum++;

    QLabel *text2 = new QLabel(areas);
    text2->setText(msg);
    text2->setGeometry(QRect(30,20+m_iLabNum*22,500,15));
    text2->setVisible(true);
    m_iLabNum++;

    if((20+m_iLabNum*22+15)>(areas->height()-10))
    {
        int width=areas->width();
        int height=areas->height();
        areas->setMinimumSize(width,height+22);
    }
}

void Dialog::updata_name(QString new_name){
    user_name = new_name;
    ui->username->setText(user_name);
}
