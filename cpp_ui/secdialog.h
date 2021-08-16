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
};

#endif // SECDIALOG_H
