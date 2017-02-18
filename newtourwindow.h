#ifndef NEWTOURWINDOW_H
#define NEWTOURWINDOW_H

#include <QDialog>
#include <Tour.h>

namespace Ui {
class NewTourWindow;
}

class NewTourWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewTourWindow(QWidget *parent = 0);
    ~NewTourWindow();
    float giveDistanceNew();
    Tour giveNewTour();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewTourWindow *ui;

};

#endif // NEWTOURWINDOW_H
