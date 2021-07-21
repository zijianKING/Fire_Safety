#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>
//class display;
namespace Ui {
class display;
}

class display : public QDialog
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = 0);
    ~display();

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
