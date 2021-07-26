#include "secdialog.h"
#include "ui_mainwindow.h"
#include "ui_secdialog.h"


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("CO2 ppm 191c");
    ui->comboBox->addItem("Benzene  191c");
    ui->comboBox->addItem("Acetylene");
    ui->comboBox->addItem("CO (500) 191C (1of2)");
    ui->comboBox->addItem("NO (350,3000) 191C");
    ui->comboBox->addItem("HF ppm (10) 191C");
}

SecDialog::~SecDialog()
{
    delete ui;

}

void SecDialog::on_pushButton_clicked()
{
    ui->label_2->setText("Graph for " + ui->comboBox->currentText());

    QPixmap pm("C:\\Users\\zijia\\Downloads\\Fire_Safety-cpp_ui\\" +ui->comboBox->currentText() + ".png");
    ui->label_3->setPixmap(pm);
    ui->label_3->setScaledContents(true);
    QApplication::restoreOverrideCursor();
}

