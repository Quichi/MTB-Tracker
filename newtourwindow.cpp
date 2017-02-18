#include "newtourwindow.h"
#include "ui_newtourwindow.h"

#include <iostream>
#include <QDate>

NewTourWindow::NewTourWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTourWindow)
{
    ui->setupUi(this);

    QDate date = QDate::currentDate();
    ui->deDatum->setDate(date);
}

NewTourWindow::~NewTourWindow()
{
    delete ui;
}

void NewTourWindow::on_buttonBox_accepted()
{
    std::cout<<"ACCEPTED"<<std::endl;
}

float NewTourWindow::giveDistanceNew()
{
    float distance = 25.44;
    return distance;
}

Tour NewTourWindow::giveNewTour()
{
    Tour newTour;

    QString name = ui->leBezeichnung->displayText();
    //std::cout<<name.toStdString()<<std::endl;
    float distance = ui->leStrecke->displayText().toFloat();
    float vm = ui->leSchnitt->displayText().toFloat();
    float dH = ui->leHoehenmeter->displayText().toFloat();
    QDate date = ui->deDatum->date();
    QTime time = ui->teDauer->time();

    newTour = Tour(name, date, distance, vm, dH, time);

    return newTour;
}

