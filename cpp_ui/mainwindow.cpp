#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImageReader>
#include <QPixmap>
#include <QProcess>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //clicking the button simulates the action of running the python file
    QString path = "../../PredictionModel";
    QString command("C:/Users/Cathy/.virtualenvs/Fire_Safety/Scripts/python");
    QStringList params = QStringList() << "main.py";
    QProcess *p = new QProcess();
    p->startDetached(command, params, path);
//    QString p_stdout = (*p).readAll();
//    ui->lineEdit->setPlainText(p_stdout); //我想把python print出的text display到Qt上面， 但是不work
//    ui->lineEdit->setPlainText("at least");
    p->waitForFinished();
    p->close();

//    QString fileName;
//    fileName = QFileDialog::getOpenFileName(this,
//    tr("Open Text file"), "", tr("All Files (*)")); //this:pointer to the object

//    if(!fileName.isNull())
//    {
//        QFile file(fileName);
//        if(!file.open(QFile::ReadOnly|QFile::Text))
//        {
//            QMessageBox::warning(this,tr("Error"),tr("read file error:&1").arg(file.errorString()));
//            return;
//        }
//        QTextStream in(&file);
//        QApplication::setOverrideCursor(Qt::WaitCursor);
//        secDialog = new SecDialog(this);
//        secDialog->setModal(false);
//        secDialog->ui->textBrowser->setPlainText(in.readAll());
//        secDialog->show();
//        QApplication::restoreOverrideCursor();
//        this->hide();
//    }
//    else
//    {
//        qDebug()<<"quit";
//    }


}


void MainWindow::on_pushButton_2_clicked()
{
    secDialog = new SecDialog(this);
    secDialog->setModal(false);
    Qt::WindowFlags flags = Qt::Window;
    secDialog->setWindowFlags(flags);
    secDialog->show();
    QApplication::restoreOverrideCursor();

    this->hide();


    QPixmap pm("../../emergency_guides/explosive.png");
    secDialog->ui->placard1->setPixmap(pm);
    secDialog->ui->placard1->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    QPixmap pm4("../../emergency_guides/toxic.jpg");
    secDialog->ui->placard2->setPixmap(pm4);
    secDialog->ui->placard2->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    QPixmap pm2("../../PredictionModel/dataframe.png");
    secDialog->ui->label_5->setPixmap(pm2);
    secDialog->ui->label_5->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    QPixmap pm3("../../PredictionModel/predictionResult.png");
    secDialog->ui->label_4->setPixmap(pm3);
    secDialog->ui->label_4->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    //guide placeholder
    QFile inputFile("../../emergency_guides/guide_137.txt");
    if(!inputFile.open(QFile::ReadOnly|QFile::Text))
    {
          QMessageBox::warning(this,tr("Error"),tr("read file error:&1").arg(inputFile.errorString()));
          return;
    }
    QTextStream in(&inputFile);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    secDialog->ui->textBrowser->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    //chemicals placeholder
    QFile inputFile2("../../data/chemicals.txt");
    if(!inputFile2.open(QFile::ReadOnly|QFile::Text))
    {
          QMessageBox::warning(this,tr("Error"),tr("read file error:&1").arg(inputFile2.errorString()));
          return;
    }
    QTextStream in2(&inputFile2);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    secDialog->ui->DetectedText->setPlainText(in2.readAll());
    QApplication::restoreOverrideCursor();

}

