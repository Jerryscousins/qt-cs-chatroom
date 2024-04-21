#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QDialog>
#include <QCloseEvent>
#include <QDebug>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "netsql.h"


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

private slots:
    void on_accept_clicked();
    void on_reg_clicked();
    void on_back_clicked();
    void on_reg_2_clicked();
    void accept();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::FirstPage *ui;
    bool flag = 0;
    QString username;
    netsql *database;

signals:
    void goAccept();
    void dead();
};

#endif // FIRSTPAGE_H
