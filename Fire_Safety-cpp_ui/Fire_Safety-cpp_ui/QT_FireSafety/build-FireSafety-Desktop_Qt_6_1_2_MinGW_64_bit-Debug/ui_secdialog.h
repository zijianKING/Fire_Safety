/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTextBrowser *DetectedText;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(1046, 676);
        gridLayout_2 = new QGridLayout(SecDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        textBrowser = new QTextBrowser(SecDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser, 5, 2, 3, 2);

        label = new QLabel(SecDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(label, 5, 1, 1, 1);

        DetectedText = new QTextBrowser(SecDialog);
        DetectedText->setObjectName(QString::fromUtf8("DetectedText"));
        sizePolicy.setHeightForWidth(DetectedText->sizePolicy().hasHeightForWidth());
        DetectedText->setSizePolicy(sizePolicy);
        DetectedText->setMinimumSize(QSize(256, 100));
        DetectedText->setMaximumSize(QSize(16777215, 100));
        DetectedText->setAutoFillBackground(true);
        DetectedText->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);border: none;"));

        gridLayout->addWidget(DetectedText, 2, 1, 1, 1);

        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 0));
        pushButton->setMaximumSize(QSize(120, 50));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        comboBox = new QComboBox(SecDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(60, 30));
        comboBox->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(14);
        comboBox->setFont(font1);

        gridLayout->addWidget(comboBox, 3, 1, 1, 1, Qt::AlignHCenter);

        label_2 = new QLabel(SecDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);


        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("SecDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Here are the corresponding Emergency Guides:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", "TextLabel", nullptr));
        DetectedText->setHtml(QCoreApplication::translate("SecDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#5555ff;\"><br />Detected Chemicals:</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("SecDialog", "Select Chemical", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
