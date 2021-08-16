#include "secdialog.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextEdit>
#include <QProcess>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    QFile file("../../data/chemicals.txt");
    QStringList chemicals;


    if( !file.open(QIODevice::ReadOnly) )
        QMessageBox::information(0,"info",file.errorString());

    QTextStream textStream(&file);

    while( !textStream.atEnd( ) )
    {
        QString line = textStream.readLine();
        //ui->comboBox->addItem(line);
        //qDebug() << line;
        chemicals.append(line);
    }

    file.close();

   // ui->comboBox->addItems(chemicals);
    for (int i=0;i < chemicals.size(); ++i){
        ui->comboBox->addItem(chemicals.at(i));
    }
}

SecDialog::~SecDialog()
{
    delete ui;

}


void SecDialog::on_pushButton_clicked()
{



    QPixmap pm("../../plots/" +ui->comboBox->currentText() + " figure.jpg");
    ui->label_3->setPixmap(pm);
    ui->label_3->setScaledContents(true);
    QApplication::restoreOverrideCursor();
}

//void SecDialog::on_pushButton_2_clicked()
//{
////    //click button模拟了run python file的行动
////    QString path = "../../PredictionModel";
////    QString command("C:\\Users\\Cathy\\.virtualenvs\\Fire_Safety\\Scripts\\python");
////    QStringList params = QStringList() << "Prediction.py";
////    QProcess *p = new QProcess();
////    p->startDetached(command, params, path);
////    p->waitForFinished();
////    p->close();

//    QPixmap pm("../../PredictionModel/predictionResult.png");
//    ui->label_4->setPixmap(pm);
//    ui->label_4->setScaledContents(true);
//    QApplication::restoreOverrideCursor();
//}


