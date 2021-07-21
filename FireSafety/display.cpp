#include "display.h"
#include "ui_mainwindow.h"
#include "ui_loginwindow.h"
#include <QDialog>
#include <QGraphicsEffect>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
display::display(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::display)
{
    ui->setupUi(this);
}

display::~display()
{
    delete ui;
}
