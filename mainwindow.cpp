#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImageReader>

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
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open Text file"), "", tr("Text Files (*.txt)")); //this:指针指向窗口对象

    if(!fileName.isNull())
    {
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly|QFile::Text))
        {
            QMessageBox::warning(this,tr("Error"),tr("read file error:&1").arg(file.errorString()));
            return;
        }
        QTextStream in(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);

        secDialog = new SecDialog(this);
        secDialog->setModal(false);

        secDialog->ui->textBrowser->setPlainText(in.readAll());

        QApplication::restoreOverrideCursor();

        secDialog->show();
        this->hide();
    }
    else
    {
        qDebug()<<"quit";
    }
//    secDialog = new SecDialog(this);
//    secDialog->show();


}


void MainWindow::on_pushButton_2_clicked()
{
    QPixmap pm("C:\\Users\\Cathy\\Desktop\\FireSafety\\13737.jpg"); // <- path to image file
    secDialog = new SecDialog(this);
    secDialog->setModal(false);
    secDialog->ui->graphicsView->setPixmap(pm);
    secDialog->ui->graphicsView->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    secDialog->show();
    this->hide();
}
