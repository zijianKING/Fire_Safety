#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "display.h"
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
//    QString fileName = QFileDialog::getOpenFileName(this,
//        tr("Open Text file"), "", tr("Text Files (*.txt)")); //this:指针指向窗口对象
//    QFile file(fileName);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//           return;

//    QTextStream in(&file);
//    while (!in.atEnd())
//    {
//        QString line = in.readLine();
//        QStringList tokens= line.split(" ",QString::SkipEmptyParts);
//        ui->text->setTextFormat(Qt:PlainText);
//    }
//    file.close();
    display display;
    display.setModal(true);
    display.exec();


}

