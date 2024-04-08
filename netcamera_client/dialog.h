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

private:
    Ui::Dialog *ui;
    FirstPage *firstpage1;
    scocknet * client_socket;
};
#endif // DIALOG_H
