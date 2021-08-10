#include "display.h"
#include "ui_display.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QWidget>
#include <stdio.h>

Display::Display(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Display),
    mainwindow(new MainWindow())
{
    ui->setupUi(this);
    mainwindow->hide();
}

Display::~Display()
{
    //delete ui;
}
