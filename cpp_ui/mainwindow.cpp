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
    /* clicking the button simulates the action of running the python file */
    QString path = "../../PredictionModel";
    // paste your own python interpreter
    QString command("C:/Users/Cathy/.virtualenvs/Fire_Safety/Scripts/python");
    QStringList params = QStringList() << "main.py";
    QProcess *p = new QProcess();
    p->setWorkingDirectory(path);
    p->start(command, params);
    QString p_stdout;


    if ((*p).waitForStarted()){                                 // Check if python is running
        QMessageBox::warning(this,tr("Have started"), tr("Have started"));
        p_stdout = (*p).readAllStandardOutput();                // get output
        if ((*p).waitForReadyRead(600000)){                                 // 10 sec to check if data is ready
            QMessageBox::warning(this,tr("Data ready"), tr("Data ready"));
            p_stdout = (*p).readAllStandardOutput();                // get output
            qDebug() << "result: " << p_stdout;
            if ((*p).waitForBytesWritten(600000)){     // 10 sec to check if data is written
                QMessageBox::warning(this,tr("Data written"), tr("Data written"));
            }
        }
    }

    QMessageBox::warning(this,tr("Have finished"), tr("Have finished"));
    ui->progress->setText(p_stdout); // display output
    if (!(*p).waitForFinished(600000)){                               // If process crash, stop it
        return;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    /* set up the second dialog */
    secDialog = new SecDialog(this);
    secDialog->setModal(false);
    Qt::WindowFlags flags = Qt::Window;
    secDialog->setWindowFlags(flags); //adds maximizing button
    secDialog->show();
    QApplication::restoreOverrideCursor();
    this->hide();

    /* emergency placard #1 */
    QPixmap pm("../../emergency_guides/explosive.png");
    secDialog->ui->placard1->setPixmap(pm);
    secDialog->ui->placard1->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    /* emergency placard #2 */
    QPixmap pm4("../../emergency_guides/toxic.jpg");
    secDialog->ui->placard2->setPixmap(pm4);
    secDialog->ui->placard2->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    /* load the rule-based prediction that you just ran */
    QPixmap pm2("../../PredictionModel/dataframe.png");
    secDialog->ui->label_5->setPixmap(pm2);
    secDialog->ui->label_5->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    /* load the ML prediction that you just ran */
    QPixmap pm3("../../PredictionModel/predictionResult.png");
    secDialog->ui->label_4->setPixmap(pm3);
    secDialog->ui->label_4->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    /* emergency guide's text file */
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

    /* chemicals detected */
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

