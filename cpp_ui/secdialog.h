#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QTextEdit>
namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();
    Ui::SecDialog *ui;

private:
    QTextEdit *textEdit;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void setWindowFlags(Qt::WindowFlags flags);
};

#endif // SECDIALOG_H
