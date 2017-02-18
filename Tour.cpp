/*
 * Tour.cpp
 *
 *  Created on: 05.04.2016
 *      Author: quichi
 */

#include "Tour.h"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

int Tour::tourCount = 0;

Tour::Tour(){
	Tour::number = 0;
    Tour::tag = "";
    Tour::distance = 0;
	Tour::vm = 0;
	Tour::dH = 0;
    Tour::comment = "";
}

Tour::Tour(QString tag, QDate date, float distance, float vm, float dH, QTime time, QString comment) {
    Tour::tag = tag;
	Tour::distance = distance;
	Tour::vm = vm;
	Tour::dH = dH;
	Tour::time = time;
	Tour::date = date;
    Tour::comment = comment;

    Tour::tourCount++;
    Tour::number = Tour::tourCount;

    std::cout<< "Tour "<<Tour::number<<" angelegt."<<std::endl;
}

Tour::~Tour() {
    //Tour::tourCount--;
}

int Tour::giveNumber() {
    //std::cout<<Tour::number<<std::endl;
	return Tour::number;
}

QString Tour::giveTag() {
    //std::cout<<Tour::tag.toStdString()<<std::endl;
    return Tour::tag;
}

int Tour::giveCount() {
    //std::cout<<Tour::tourCount<<std::endl;
	return Tour::tourCount;
}

float Tour::giveDistance() {
    //std::cout<<Tour::distance<<std::endl;
	return Tour::distance;
}

QTime Tour::giveTime(){
    //std::cout<<Tour::time<<std::endl;
	return Tour::time;
}

QDate Tour::giveDate(){
    //std::cout<<Tour::date<<std::endl;
	return Tour::date;
}

float Tour::giveVM() {
    //std::cout<<Tour::vm<<std::endl;
    return Tour::vm;
}

float Tour::giveDH() {
    //std::cout<<Tour::dH<<std::endl;
    return Tour::dH;
}

QString Tour::giveComment() {
    //std::cout<<Tour::comment<<std::endl;
    return Tour::comment;
}

void Tour::resetCount() {
    Tour::tourCount=0;
}
