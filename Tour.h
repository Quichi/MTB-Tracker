/*
 * Tour.h
 *
 *  Created on: 05.04.2016
 *      Author: quichi
 */
#include <ctime>
#include <chrono>
#include <QDate>

#ifndef TOUR_H_
#define TOUR_H_

class Tour {
private:
	int number;
    QString tag;
	float distance;
	float vm;
	float dH;
    QTime time;
    QDate date;
    QString comment;

	static int tourCount;
	static float totalDistance;
public:
	Tour();
    Tour(QString tag, QDate date, float distance, float vm, float dH, QTime time, QString comment);
	~Tour();

	int EineFunktion(int day=1);
	int giveNumber();
    QString giveTag();
	float giveDistance();
	float giveVM();
	float giveDH();
    QTime giveTime();
    QDate giveDate();
    QString giveComment();
	int giveCount();
	float giveTotalDistance();
    void resetCount();
};

#endif /* TOUR_H_ */
