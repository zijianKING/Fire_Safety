#include "secdialog.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("CO2");
    ui->comboBox->addItem("CO");
    ui->comboBox->addItem("N2");
    ui->comboBox->addItem("SO2");
    ui->comboBox->addItem("SO");
}

SecDialog::~SecDialog()
{
    delete ui;

}
