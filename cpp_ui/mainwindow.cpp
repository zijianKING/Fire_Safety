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
    QStringList params = QStringList() << "Prediction.py";
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
    secDialog->show();
    QApplication::restoreOverrideCursor();
    this->hide();

    QPixmap pm("../../plots/explosive.png");
        secDialog->ui->label->setPixmap(pm);
        secDialog->ui->label->setScaledContents(true);
        QApplication::restoreOverrideCursor();

        QPixmap pm2("../../scripts/dataframe.png");
        secDialog->ui->label_5->setPixmap(pm2);
        secDialog->ui->label_5->setScaledContents(true);
        QApplication::restoreOverrideCursor();
}

