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
    connect(ui->pushButton,SIGNAL(clicked()),client_socket,SLOT(msg_write()));
}

Dialog::~Dialog()
{
    delete firstpage1;
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

}

