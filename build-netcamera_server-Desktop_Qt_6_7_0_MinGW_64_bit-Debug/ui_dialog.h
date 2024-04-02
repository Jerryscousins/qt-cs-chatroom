/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVideoWidget *camera;
    QPushButton *photograph;
    QPushButton *deleteuser;
    QLabel *label;
    QLabel *name;
    QPushButton *changename;
    QPushButton *changepw;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(800, 600);
        camera = new QVideoWidget(Dialog);
        camera->setObjectName("camera");
        camera->setGeometry(QRect(80, 60, 511, 321));
        photograph = new QPushButton(Dialog);
        photograph->setObjectName("photograph");
        photograph->setEnabled(false);
        photograph->setGeometry(QRect(570, 450, 121, 28));
        deleteuser = new QPushButton(Dialog);
        deleteuser->setObjectName("deleteuser");
        deleteuser->setEnabled(false);
        deleteuser->setGeometry(QRect(680, 560, 111, 28));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(620, 50, 69, 19));
        name = new QLabel(Dialog);
        name->setObjectName("name");
        name->setGeometry(QRect(700, 50, 69, 19));
        changename = new QPushButton(Dialog);
        changename->setObjectName("changename");
        changename->setEnabled(false);
        changename->setGeometry(QRect(570, 560, 92, 28));
        changepw = new QPushButton(Dialog);
        changepw->setObjectName("changepw");
        changepw->setEnabled(false);
        changepw->setGeometry(QRect(460, 560, 92, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        photograph->setText(QCoreApplication::translate("Dialog", "\344\275\240\345\245\275\357\274\201\344\270\226\347\225\214\357\274\201", nullptr));
        deleteuser->setText(QCoreApplication::translate("Dialog", "\346\263\250\351\224\200\347\224\250\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        name->setText(QString());
        changename->setText(QCoreApplication::translate("Dialog", "\346\224\271\345\217\230\347\224\250\346\210\267\345\220\215", nullptr));
        changepw->setText(QCoreApplication::translate("Dialog", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
