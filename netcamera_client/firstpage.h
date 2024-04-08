#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QDialog>
#include <QCloseEvent>
#include <QDebug>

#include <QMessageBox>
#include <scocknet.h>

namespace Ui {
class FirstPage;
}

class FirstPage : public QDialog
{
    Q_OBJECT

public:
    explicit FirstPage(QWidget *parent = nullptr);
    QString isusername();
    ~FirstPage();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::FirstPage *ui;
    bool flag = 0;

    QString username;

private slots:
    void on_accept_clicked();
    void on_reg_clicked();
    void on_back_clicked();
    void on_reg_2_clicked();
    void accept();

    void net_open();
    void log_return(QString back);
    void Reg_return(QString back);

signals:
    void goAccept();
    void dead();

    void go_Log(QString user_name,QString user_pw);
    void go_Reg(QString user_name,QString user_pw);

};

#endif // FIRSTPAGE_H
