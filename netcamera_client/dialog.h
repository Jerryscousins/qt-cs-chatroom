#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "scocknet.h"
#include "firstpage.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void all_close();
    void all_open();

    void change_user_return(QString back);
    void change_pw_return(QString back);
    void deluser_return(QString back);
    void meg_return(QString back);
private:
    Ui::Dialog *ui;
    FirstPage *firstpage1;
    scocknet * client_socket;
    QString user_name;

signals:
    void go_change_user(QString user_name,QString new_name);
    void go_change_pw(QString user_name,QString new_pw);
    void go_deluser(QString user_name);
    void go_meg_send(QString text);
};
#endif // DIALOG_H
