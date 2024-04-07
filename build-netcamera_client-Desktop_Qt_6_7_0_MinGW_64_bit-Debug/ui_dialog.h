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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *username;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(800, 600);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 480, 92, 28));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 450, 501, 85));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(570, 140, 171, 27));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(570, 70, 69, 19));
        username = new QLabel(Dialog);
        username->setObjectName("username");
        username->setGeometry(QRect(650, 70, 69, 19));
        scrollArea = new QScrollArea(Dialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(40, 40, 501, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 499, 349));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\351\231\244\344\275\240\346\255\246\345\231\250\357\274\201", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        username->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
