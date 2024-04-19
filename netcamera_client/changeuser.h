#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QDialog>
#include <QMessageBox>

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
    void change_name(QString newname);

private slots:
    void on_acceptname_clicked();
    void on_acceptpw_clicked();
    void updata_name_adirve(QString new_name);

    void return_change_username(QString msg);
    void return_change_pw(QString msg);

private:
    QString name;
    Ui::changeuser *ui;

signals:
    void go_change_username(QString user_name,QString new_user_name);
    void go_change_pw(QString user_name,QString pw);
    void updata_name(QString user_name);
};

#endif // CHANGEUSER_H
