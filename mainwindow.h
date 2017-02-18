#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <newtourwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void beenden();
    void fillTable();
    void addTableRow(int row);
    void updateStats();

    void setTourButton(bool status);

private slots:
    void on_NewTourButton_clicked();

    void on_leTargetDistance_returnPressed();

    void on_actionBeenden_triggered();

    void on_actionLog_Datei_ffnen_triggered();

    void on_actionLog_Datei_speichern_unter_triggered();

    void on_saveButton_clicked();

    void on_actionLog_Datei_speichern_triggered();

private:
    Ui::MainWindow *ui;
    NewTourWindow *newTourWindowUi;
};

#endif // MAINWINDOW_H
