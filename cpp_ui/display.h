#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>
#include "mainwindow.h"
//#include "ui_mainwindow.h"
//class display;
namespace Ui {class Display;}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private:
    Ui::Display *ui;
    MainWindow* mainwindow;
};

#endif // DISPLAY_H
