/********************************************************************************
** Form generated from reading UI file 'changeuser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSER_H
#define UI_CHANGEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeuser
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *newname;
    QLabel *label;
    QPushButton *acceptname;
    QWidget *page_2;
    QLabel *label_2;
    QLineEdit *newpw;
    QLineEdit *newpw2;
    QLabel *label_3;
    QPushButton *acceptpw;

    void setupUi(QDialog *changeuser)
    {
        if (changeuser->objectName().isEmpty())
            changeuser->setObjectName("changeuser");
        changeuser->resize(400, 300);
        stackedWidget = new QStackedWidget(changeuser);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 20, 341, 261));
        page = new QWidget();
        page->setObjectName("page");
        newname = new QLineEdit(page);
        newname->setObjectName("newname");
        newname->setGeometry(QRect(180, 90, 113, 27));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 69, 19));
        acceptname = new QPushButton(page);
        acceptname->setObjectName("acceptname");
        acceptname->setGeometry(QRect(120, 180, 92, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 50, 69, 19));
        newpw = new QLineEdit(page_2);
        newpw->setObjectName("newpw");
        newpw->setGeometry(QRect(190, 50, 113, 27));
        newpw2 = new QLineEdit(page_2);
        newpw2->setObjectName("newpw2");
        newpw2->setGeometry(QRect(190, 100, 113, 27));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 81, 19));
        acceptpw = new QPushButton(page_2);
        acceptpw->setObjectName("acceptpw");
        acceptpw->setGeometry(QRect(120, 200, 92, 28));
        stackedWidget->addWidget(page_2);

        retranslateUi(changeuser);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(changeuser);
    } // setupUi

    void retranslateUi(QDialog *changeuser)
    {
        changeuser->setWindowTitle(QCoreApplication::translate("changeuser", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("changeuser", "\346\226\260\345\220\215\347\247\260", nullptr));
        acceptname->setText(QCoreApplication::translate("changeuser", "\345\221\210\351\200\222\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("changeuser", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("changeuser", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        acceptpw->setText(QCoreApplication::translate("changeuser", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeuser: public Ui_changeuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSER_H
