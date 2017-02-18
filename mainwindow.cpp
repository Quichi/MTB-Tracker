#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logiccode.h"
#include "Tour.h"
#include <iostream>
#include <QFileDialog>

LogicCode logicCode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->twTouren->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->twTouren->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->twTouren->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->twTouren->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->leTotalDistance->setReadOnly(true);
    ui->leRemainingDistance->setReadOnly(true);

    MainWindow::fillTable();
    MainWindow::updateStats();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::beenden(){
    close();
}

void MainWindow::on_NewTourButton_clicked() {
    MainWindow::newTourWindowUi = new NewTourWindow();

    if(MainWindow::newTourWindowUi->exec()>0)
    {
       std::cout<<"neue Tour einlesen und erstellen"<<std::endl;
       Tour newTour = MainWindow::newTourWindowUi->giveNewTour();
       logicCode.addTour(newTour);
       std::cout<<logicCode.giveTour(0).giveCount()<<std::endl;
       MainWindow::fillTable();
       MainWindow::updateStats();
    }
    else
    {
        std::cout<<"nix machen"<<std::endl;
    }
}

void MainWindow::setTourButton(bool status) {
    ui->NewTourButton->setDisabled(status);
}

void MainWindow::fillTable() {
    int numTour = logicCode.giveTour(0).giveCount();
    ui->twTouren->setRowCount(numTour);

    for (int i=0 ; i<=numTour ; i++) {
       MainWindow::addTableRow(i);
    }
}

void MainWindow::addTableRow(int row) {
    QTableWidgetItem *arrayItems[8];
    arrayItems[0] = new QTableWidgetItem(logicCode.giveTour(row).giveTag());
    arrayItems[1] = new QTableWidgetItem(logicCode.giveTour(row).giveDate().toString("dd.MM.yyyy"));
    arrayItems[2] = new QTableWidgetItem(QString::number(logicCode.giveTour(row).giveDistance()));
    arrayItems[3] = new QTableWidgetItem(logicCode.giveTour(row).giveTime().toString("HH:mm:ss"));
    arrayItems[4] = new QTableWidgetItem(QString::number(logicCode.giveTour(row).giveVM()));
    arrayItems[5] = new QTableWidgetItem(QString::number(logicCode.giveTour(row).giveDH()));

    for(int i=0 ; i<=5 ; i++){
        ui->twTouren->setItem(row,i,arrayItems[i]);
    }
}

void MainWindow::updateStats() {
    float totalDistance = logicCode.calcTotalDistance();
    float targetDistance = logicCode.getTargetDistance();
    int percentage = totalDistance/targetDistance*100;

    ui->leTargetDistance->setText(QString::number(targetDistance));
    ui->leTotalDistance->setText(QString::number(totalDistance));
    ui->leRemainingDistance->setText(QString::number(targetDistance-totalDistance));

    if(percentage < 100) {
       ui->pbRemaining->setValue(percentage);
    }
    else {
        ui->pbRemaining->setValue(100);
    }
}

void MainWindow::on_leTargetDistance_returnPressed()
{
    float newTargetDist = ui->leTargetDistance->displayText().toFloat();
    logicCode.setTargetDistance(newTargetDist);

    MainWindow::updateStats();
}

void MainWindow::on_actionBeenden_triggered()
{
    MainWindow::beenden();
}

void MainWindow::on_actionLog_Datei_ffnen_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    logicCode.setFilename(filename);
    logicCode.clearTourObjects();

    logicCode.readfile();
    MainWindow::fillTable();
    MainWindow::updateStats();
}

void MainWindow::on_actionLog_Datei_speichern_unter_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
    logicCode.setFilename(filename);
    logicCode.saveFile();
}

void MainWindow::on_saveButton_clicked()
{
    logicCode.saveFile();
}

void MainWindow::on_actionLog_Datei_speichern_triggered()
{
    logicCode.saveFile();
}
