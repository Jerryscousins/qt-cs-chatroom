#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDir>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDialog>

#include <QCamera>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>

#include "firstpage.h"
#include "changeuser.h"
#include "scocknet.h"


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
    void getCamera();
    void allclose();
    void change_name(QString new_name);
    void on_deleteuser_clicked();
    void on_changename_clicked();
    void on_changepw_clicked();
    void updata_name_s();

    void text_msg(QString name, QString time, QString msg);

private:
    Ui::Dialog *ui;
    FirstPage *firstpage1;
    netsql *database;
    changeuser *changeuser1;
    scocknet * headsocket;

    QString username = "";
    void allopen();

signals:
    void updata_name_p(QString name_now);
};
#endif // DIALOG_H
