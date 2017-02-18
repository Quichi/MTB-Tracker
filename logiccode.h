#ifndef LOGICCODE_H
#define LOGICCODE_H

#include <QDate>
#include "Tour.h"

class LogicCode
{
public:
    LogicCode();
    void readfile();
    void saveFile();
    void makeTourObjects(int numTours , QString arrData[][10]);
    void addTour(Tour newTour);
    Tour giveTour(int tourNr);
    float calcTotalDistance();
    void setTargetDistance(float targetDist);
    float getTargetDistance();
    void setFilename(QString filename);
    QString getFilename();
    void clearTourObjects();

private:
    QString filename = "Data2016.csv";
    Tour arrTour[1024];
    float targetDistance;
};

#endif // LOGICCODE_H
