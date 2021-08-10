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

    QString path = "../../script";
//    qDebug() << "App path : " << qApp->applicationDirPath();

////    QString path = QDir::currentPath();
//    QString path = $$_PRO_FILE_PWD_/../
//    QTextStream(stdout) << qApp;


    QString command("python");
    QStringList params = QStringList() << "test.py";

    QProcess *p = new QProcess();
    p->startDetached(command, params, path);
    p->waitForFinished();
    p->close();

    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open Text file"), "", tr("All Files (*)")); //this:指针指向窗口对象

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
        secDialog->show();
        QApplication::restoreOverrideCursor();
        this->hide();
    }
    else
    {
        qDebug()<<"quit";
    }

    QPixmap pm("../../plots/explosive.png");
    secDialog->ui->label->setPixmap(pm);
    secDialog->ui->label->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    QPixmap pm2("../../scripts/dataframe.png");
    secDialog->ui->label_5->setPixmap(pm2);
    secDialog->ui->label_5->setScaledContents(true);
    QApplication::restoreOverrideCursor();

    //secDialog->show();
    //this->hide();
}

