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

    /* set up the chemical comboBox */
    QTextStream textStream(&file);
    while( !textStream.atEnd( ) )
    {
        QString line = textStream.readLine();
        chemicals.append(line);
    }
    file.close();
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



