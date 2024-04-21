#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
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

    void updata_name(QString new_name);
    void deluser_return(QString back);
    void meg_return(QString name,QString time,QString msg);
    void tool_accept(QAction * mode);

private:
    Ui::Dialog *ui;
    FirstPage *firstpage1;
    scocknet * client_socket;
    QString user_name;
    int m_iLabNum = 0;

    void ini_user();
    QAction * change_pw_c;
    QAction * change_user_c;
    QAction * del_user_c;
signals:
    void go_change_user(QString user_name);
    void go_change_pw(QString user_name);

    void go_deluser(QString user_name);
    void go_meg_send(QString text);

};
#endif // DIALOG_H
