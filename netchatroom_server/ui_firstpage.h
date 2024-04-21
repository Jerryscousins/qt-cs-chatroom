/********************************************************************************
** Form generated from reading UI file 'firstpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTPAGE_H
#define UI_FIRSTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstPage
{
public:
    QStackedWidget *layout;
    QWidget *page;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *userpw;
    QPushButton *reg;
    QPushButton *accept;
    QWidget *page_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *useradd;
    QLineEdit *useraddpw1;
    QLineEdit *useraddpw2;
    QPushButton *reg_2;
    QPushButton *back;

    void setupUi(QDialog *FirstPage)
    {
        if (FirstPage->objectName().isEmpty())
            FirstPage->setObjectName("FirstPage");
        FirstPage->resize(400, 300);
        layout = new QStackedWidget(FirstPage);
        layout->setObjectName("layout");
        layout->setGeometry(QRect(0, 0, 401, 301));
        layout->setLineWidth(1);
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 69, 19));
        username = new QLineEdit(page);
        username->setObjectName("username");
        username->setGeometry(QRect(210, 60, 113, 27));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 120, 71, 20));
        userpw = new QLineEdit(page);
        userpw->setObjectName("userpw");
        userpw->setGeometry(QRect(210, 120, 113, 27));
        reg = new QPushButton(page);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(200, 220, 151, 28));
        accept = new QPushButton(page);
        accept->setObjectName("accept");
        accept->setGeometry(QRect(60, 220, 111, 28));
        layout->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 60, 69, 19));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 110, 69, 19));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 160, 69, 19));
        useradd = new QLineEdit(page_2);
        useradd->setObjectName("useradd");
        useradd->setGeometry(QRect(200, 60, 113, 27));
        useraddpw1 = new QLineEdit(page_2);
        useraddpw1->setObjectName("useraddpw1");
        useraddpw1->setGeometry(QRect(200, 110, 113, 27));
        useraddpw2 = new QLineEdit(page_2);
        useraddpw2->setObjectName("useraddpw2");
        useraddpw2->setGeometry(QRect(200, 160, 113, 27));
        reg_2 = new QPushButton(page_2);
        reg_2->setObjectName("reg_2");
        reg_2->setGeometry(QRect(40, 230, 101, 28));
        back = new QPushButton(page_2);
        back->setObjectName("back");
        back->setGeometry(QRect(190, 230, 171, 28));
        layout->addWidget(page_2);

        retranslateUi(FirstPage);

        layout->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FirstPage);
    } // setupUi

    void retranslateUi(QDialog *FirstPage)
    {
        FirstPage->setWindowTitle(QCoreApplication::translate("FirstPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FirstPage", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("FirstPage", "\345\257\206\347\240\201", nullptr));
        reg->setText(QCoreApplication::translate("FirstPage", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\347\202\271\345\207\273\345\260\261\351\200\201", nullptr));
        accept->setText(QCoreApplication::translate("FirstPage", "\345\277\240\350\257\232\357\274\201\345\215\227\344\270\213\357\274\201", nullptr));
        label_3->setText(QCoreApplication::translate("FirstPage", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("FirstPage", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("FirstPage", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        reg_2->setText(QCoreApplication::translate("FirstPage", "\346\263\250\345\206\214\357\274\201\345\220\257\345\212\250\357\274\201", nullptr));
        back->setText(QCoreApplication::translate("FirstPage", "\346\255\273\345\216\273\347\232\204\350\256\260\345\277\206\345\274\200\345\247\213\346\224\273\345\207\273\346\210\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstPage: public Ui_FirstPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTPAGE_H
