#include "secdialog.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    QFile file("C:\\Users\\zijia\\Desktop\\Fire_Safety-cpp_ui\\chemicals.txt");
    QStringList chemicals;

    if( !file.open(QIODevice::ReadOnly) )
        QMessageBox::information(0,"info",file.errorString());

    QTextStream textStream(&file);

    while( !textStream.atEnd( ) )
    {
        QString line = textStream.readLine();
        ui->comboBox->addItem(line);
        qDebug() << line;
        //chemicals.append(line);
    }

    file.close( );

    //ui->comboBox->addItems(chemicals);
    //for (int i=0;i < stringList.size(); ++i){
    //    ui->comboBox->addItem(stringList.at(i));
    //}
}

SecDialog::~SecDialog()
{
    delete ui;

}

void SecDialog::on_pushButton_clicked()
{
    ui->label_2->setText("Graph for " + ui->comboBox->currentText());

    QPixmap pm("C:\\Users\\zijia\\Desktop\\Fire_Safety-cpp_ui\\" +ui->comboBox->currentText() + " figure.jpg");
    ui->label_3->setPixmap(pm);
    ui->label_3->setScaledContents(true);
    QApplication::restoreOverrideCursor();
}

