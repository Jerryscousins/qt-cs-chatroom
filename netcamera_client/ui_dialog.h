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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *username;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollarea;
    QToolButton *toolButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->setEnabled(true);
        Dialog->resize(800, 600);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(600, 530, 92, 28));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(40, 480, 501, 85));
        textEdit->setMarkdown(QString::fromUtf8(""));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(570, 50, 69, 19));
        username = new QLabel(Dialog);
        username->setObjectName("username");
        username->setGeometry(QRect(650, 50, 69, 19));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 50, 69, 19));
        scrollArea = new QScrollArea(Dialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 90, 511, 321));
        scrollArea->setWidgetResizable(true);
        scrollarea = new QWidget();
        scrollarea->setObjectName("scrollarea");
        scrollarea->setGeometry(QRect(0, 0, 509, 319));
        scrollArea->setWidget(scrollarea);
        toolButton = new QToolButton(Dialog);
        toolButton->setObjectName("toolButton");
        toolButton->setEnabled(false);
        toolButton->setGeometry(QRect(570, 100, 171, 26));
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setAutoRaise(false);
        toolButton->setArrowType(Qt::NoArrow);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\351\231\244\344\275\240\346\255\246\345\231\250\357\274\201", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        username->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog", "\345\257\271\345\206\262\345\237\272\351\207\221", nullptr));
        toolButton->setText(QCoreApplication::translate("Dialog", "\346\212\225\345\205\261\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
