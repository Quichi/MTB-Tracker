#include "logiccode.h"
#include "iostream"

#include <QFile>
#include <QTextStream>

LogicCode::LogicCode()
{
    this->targetDistance = 1000;
    this->readfile();

}

void LogicCode::readfile()
{
    int numTours = 0;
    QString array[1024][11];
    QStringList arrayColumn;
    QFile inputFile(this->filename);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        in.readLine();

        while(!in.atEnd())
        {
            QString line = in.readLine();
            line = line.simplified();

            QRegExp delimiters("(;|/|:)");
            arrayColumn = line.split(delimiters);

            for (int i=0;i<arrayColumn.length();i++)
            {
                array[numTours][i]=arrayColumn[i];
            }
            numTours++;
        }
    }
     makeTourObjects(numTours , array);
}

void LogicCode::saveFile() {
    int numTours = this->arrTour[0].giveCount();
    Tour tour;

    QFile file(this->filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "Name; Datum; Strecke; Schnitt; Hoehenmeter; Zeit; Bemerkung; \n";
    for (int i=0 ; i<numTours ; i++) {
        tour = this->arrTour[i];
        out << tour.giveTag() << "; ";
        out << tour.giveDate().toString("dd/MM/yyyy") << "; ";
        out << tour.giveDistance() << "; ";
        out << tour.giveVM() << "; ";
        out << tour.giveDH() << "; ";
        out << tour.giveTime().toString("hh:mm:ss") << "; ";
        out << tour.giveComment() << ";\n";
    }
    std::cout << "File saved to: " << this->filename.toStdString() << std::endl;
}


void LogicCode::makeTourObjects(int numTours , QString arrData[][11]){
    QTime time;
    QDate date;

    for (int i=0; i<numTours; i++){
        time = QTime(arrData[i][7].toInt() , arrData[i][8].toInt() , arrData[i][9].toInt());
        date = QDate(arrData[i][3].toInt() , arrData[i][2].toInt() , arrData[i][1].toInt());

        this->arrTour[i] = Tour(	arrData[i][0] ,
                                        date ,
                                        arrData[i][4].toFloat() ,
                                        arrData[i][5].toFloat() ,
                                        arrData[i][6].toFloat() ,
                                        time ,
                                        arrData[i][10]);
    }
    std::cout<< "Anzahl der Touren: "<<numTours<<std::endl;
}

void LogicCode::clearTourObjects() {
    int numTours = this->arrTour[0].giveCount();

    for(int i=0 ; i<numTours ; i++) {
        this->arrTour[i]=Tour();
        //LogicCode::arrTour[i].~Tour();
    }
    this->arrTour[0].resetCount();
}

float LogicCode::calcTotalDistance(){
    float totalDistance = 0;
    int numTours = this->arrTour[0].giveCount();

    for (int i=0; i<numTours; i++){
        totalDistance += this->arrTour[i].giveDistance();
    }

    std::cout<<"Total Distance: "<<totalDistance<<std::endl;
    return totalDistance;
}

void LogicCode::addTour(Tour newTour){
   int newTourNumber = this->arrTour[0].giveCount()-1;
   this->arrTour[newTourNumber] = newTour;
}

Tour LogicCode::giveTour(int tourNr){
   return this->arrTour[tourNr];
}

void LogicCode::setTargetDistance(float targetDist) {
    this->targetDistance = targetDist;
}

float LogicCode::getTargetDistance() {
    return this->targetDistance;
}

void LogicCode::setFilename(QString filename) {
    this->filename = filename;
}

QString LogicCode::getFilename() {
    return this->filename;
}

