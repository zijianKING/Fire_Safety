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
#include <QtWidgets/QFrame>
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
    QFrame *line_3;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QTextBrowser *DetectedText;
    QFrame *line_4;
    QPushButton *pushButton;
    QLabel *placard2;
    QPushButton *pushButton_2;
    QFrame *line_5;
    QFrame *line_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *placard1;
    QFrame *line;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QFrame *line_6;
    QPushButton *pushButton_3;
    QLabel *label_5;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(1308, 882);
        QFont font;
        font.setFamilies({QString::fromUtf8("Centaur")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        SecDialog->setFont(font);
        SecDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-color:  rgb(240, 240, 240);\n"
"border-radius: 25px;\n"
"font: 12pt \"Centaur\";"));
        gridLayout_2 = new QGridLayout(SecDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        line_3 = new QFrame(SecDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 17, 2, 1, 1);

        label_2 = new QLabel(SecDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(300, 30));
        label_2->setMaximumSize(QSize(150, 30));
        label_2->setStyleSheet(QString::fromUtf8("border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 12pt \"Centaur\";"));

        gridLayout->addWidget(label_2, 7, 5, 1, 1);

        textBrowser = new QTextBrowser(SecDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMaximumSize(QSize(16777215, 500));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-color:  rgb(240, 240, 240);\n"
"border-radius: 15px;\n"
"font: 12pt \"Centaur\";\n"
"border: 1px solid #707070;"));

        gridLayout->addWidget(textBrowser, 11, 3, 7, 3);

        DetectedText = new QTextBrowser(SecDialog);
        DetectedText->setObjectName(QString::fromUtf8("DetectedText"));
        sizePolicy.setHeightForWidth(DetectedText->sizePolicy().hasHeightForWidth());
        DetectedText->setSizePolicy(sizePolicy);
        DetectedText->setMinimumSize(QSize(256, 50));
        DetectedText->setMaximumSize(QSize(16777215, 100));
        DetectedText->setFont(font);
        DetectedText->setAutoFillBackground(true);
        DetectedText->setStyleSheet(QString::fromUtf8("border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 12pt \"Centaur\";"));

        gridLayout->addWidget(DetectedText, 5, 0, 1, 3);

        line_4 = new QFrame(SecDialog);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 10, 2, 1, 1);

        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(700, 30));
        pushButton->setMaximumSize(QSize(700, 30));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid #707070;\n"
"border-radius: 10px;\n"
"background:#00204E;\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover{\n"
"border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"}"));

        gridLayout->addWidget(pushButton, 6, 3, 1, 1);

        placard2 = new QLabel(SecDialog);
        placard2->setObjectName(QString::fromUtf8("placard2"));
        placard2->setMinimumSize(QSize(150, 150));
        placard2->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(placard2, 8, 5, 1, 1);

        pushButton_2 = new QPushButton(SecDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid #707070;\n"
"border-radius: 10px;\n"
"background:#00204E;\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"Centaur\";\n"
"}\n"
"QPushButton:hover{\n"
"border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 12pt \"Centaur\";\n"
"}"));

        gridLayout->addWidget(pushButton_2, 6, 0, 1, 3);

        line_5 = new QFrame(SecDialog);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 11, 2, 1, 1);

        line_2 = new QFrame(SecDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 15, 2, 1, 1);

        label_4 = new QLabel(SecDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(800, 60));
        label_4->setMaximumSize(QSize(800, 60));

        gridLayout->addWidget(label_4, 7, 0, 1, 3);

        label_3 = new QLabel(SecDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(700, 0));
        label_3->setMaximumSize(QSize(700, 16777215));

        gridLayout->addWidget(label_3, 7, 3, 4, 2);

        placard1 = new QLabel(SecDialog);
        placard1->setObjectName(QString::fromUtf8("placard1"));
        sizePolicy.setHeightForWidth(placard1->sizePolicy().hasHeightForWidth());
        placard1->setSizePolicy(sizePolicy);
        placard1->setMinimumSize(QSize(150, 150));
        placard1->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(placard1, 9, 5, 1, 1);

        line = new QFrame(SecDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 16, 2, 1, 1);

        label_6 = new QLabel(SecDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(700, 30));
        label_6->setMaximumSize(QSize(700, 30));
        label_6->setStyleSheet(QString::fromUtf8("border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 14pt \"Centaur\";"));

        gridLayout->addWidget(label_6, 4, 3, 1, 2);

        label_7 = new QLabel(SecDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setStyleSheet(QString::fromUtf8("border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 14pt \"Centaur\";"));

        gridLayout->addWidget(label_7, 4, 0, 1, 3);

        comboBox = new QComboBox(SecDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(700, 30));
        comboBox->setMaximumSize(QSize(700, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Centaur")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 255);\n"
"border: 1px solid #707070;\n"
"font: 14pt \"Centaur\";"));

        gridLayout->addWidget(comboBox, 5, 3, 1, 1);

        line_6 = new QFrame(SecDialog);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 12, 2, 1, 1);

        pushButton_3 = new QPushButton(SecDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid #707070;\n"
"border-radius: 10px;\n"
"background:#00204E;\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"Centaur\";\n"
"}\n"
"QPushButton:hover{\n"
"border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background: rgb(207, 237, 255);\n"
"color: #00204E;\n"
"font: 12pt \"Centaur\";\n"
"}"));

        gridLayout->addWidget(pushButton_3, 8, 0, 1, 3);

        label_5 = new QLabel(SecDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 150));
        label_5->setMaximumSize(QSize(16777215, 500));

        gridLayout->addWidget(label_5, 9, 0, 6, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "Emergency Placard", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("SecDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Centaur'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-weight:600;\">Here are the corresponding Emergency Guides:</span></p></body></html>", nullptr));
        DetectedText->setHtml(QCoreApplication::translate("SecDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Centaur'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("SecDialog", "display chemical profile", nullptr));
        placard2->setText(QCoreApplication::translate("SecDialog", "placard1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecDialog", "Click to Reload Machine-Learning Prediction", nullptr));
        label_4->setText(QCoreApplication::translate("SecDialog", "machine-learning prediction placeholder", nullptr));
        label_3->setText(QString());
        placard1->setText(QString());
        label_6->setText(QCoreApplication::translate("SecDialog", "Select a chemical for the PPM plot:", nullptr));
        label_7->setText(QCoreApplication::translate("SecDialog", "Chemicals Detected:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SecDialog", "Click to Reload Rule-Based Prediction", nullptr));
        label_5->setText(QCoreApplication::translate("SecDialog", "rule-based prediction", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
