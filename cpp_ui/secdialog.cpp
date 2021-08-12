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

void SecDialog::setWindowFlags(Qt::WindowFlags flags)
{
    QWidget::setWindowFlags(flags);

    QString text;

    Qt::WindowFlags type = (flags & Qt::WindowType_Mask);
    if (type == Qt::Window)
        text = "Qt::Window";
    else if (type == Qt::Dialog)
        text = "Qt::Dialog";
    else if (type == Qt::Sheet)
        text = "Qt::Sheet";
    else if (type == Qt::Drawer)
        text = "Qt::Drawer";
    else if (type == Qt::Popup)
        text = "Qt::Popup";
    else if (type == Qt::Tool)
        text = "Qt::Tool";
    else if (type == Qt::ToolTip)
        text = "Qt::ToolTip";
    else if (type == Qt::SplashScreen)
        text = "Qt::SplashScreen";

    if (flags & Qt::MSWindowsFixedSizeDialogHint)
        text += "\n| Qt::MSWindowsFixedSizeDialogHint";
    if (flags & Qt::X11BypassWindowManagerHint)
        text += "\n| Qt::X11BypassWindowManagerHint";
    if (flags & Qt::FramelessWindowHint)
        text += "\n| Qt::FramelessWindowHint";
    if (flags & Qt::NoDropShadowWindowHint)
        text += "\n| Qt::NoDropShadowWindowHint";
    if (flags & Qt::WindowTitleHint)
        text += "\n| Qt::WindowTitleHint";
    if (flags & Qt::WindowSystemMenuHint)
        text += "\n| Qt::WindowSystemMenuHint";
    if (flags & Qt::WindowMinimizeButtonHint)
        text += "\n| Qt::WindowMinimizeButtonHint";
    if (flags & Qt::WindowMaximizeButtonHint)
        text += "\n| Qt::WindowMaximizeButtonHint";
    if (flags & Qt::WindowCloseButtonHint)
        text += "\n| Qt::WindowCloseButtonHint";
    if (flags & Qt::WindowContextHelpButtonHint)
        text += "\n| Qt::WindowContextHelpButtonHint";
    if (flags & Qt::WindowShadeButtonHint)
        text += "\n| Qt::WindowShadeButtonHint";
    if (flags & Qt::WindowStaysOnTopHint)
        text += "\n| Qt::WindowStaysOnTopHint";
    if (flags & Qt::CustomizeWindowHint)
        text += "\n| Qt::CustomizeWindowHint";

    textEdit->setPlainText(text);
}

void SecDialog::on_pushButton_clicked()
{

    ui->label_2->setText("Graph for " + ui->comboBox->currentText());

    QPixmap pm("../../plots/" +ui->comboBox->currentText() + " figure.jpg");
    ui->label_3->setPixmap(pm);
    ui->label_3->setScaledContents(true);
    QApplication::restoreOverrideCursor();
}

void SecDialog::on_pushButton_2_clicked()
{
    //click button模拟了run python file的行动
    QString path = "../../PredictionModel";
    QString command("python");
    QStringList params = QStringList() << "test.py";
    QProcess *p = new QProcess();
    p->startDetached(command, params, path);
    p->waitForFinished();
    p->close();

    QPixmap pm("../../PredictionModel/test.png");
    ui->label_4->setPixmap(pm);
    ui->label_4->setScaledContents(true);
    QApplication::restoreOverrideCursor();
}


