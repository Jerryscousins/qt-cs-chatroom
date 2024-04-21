#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QDialog>
#include <QMessageBox>
#include "netsql.h"

namespace Ui {
class changeuser;
}

class changeuser : public QDialog
{
    Q_OBJECT

public:
    explicit changeuser(QString fname , QWidget *parent = nullptr);
    ~changeuser();
    void change_user_mode();
    void change_pw_mode();

private slots:
    void on_acceptname_clicked();
    void on_acceptpw_clicked();
    void updata_name_adirve(QString new_name);

private:
    QString name;
    Ui::changeuser *ui;
    netsql *database;

signals:
    void change_name_sign(QString new_name);
    void updata_name();

};

#endif // CHANGEUSER_H
