#include "calculateintegral.h"
#include <qmath.h>
#include <QDebug>

CalculateIntegral::CalculateIntegral()
{
    this->result = 0;
}

void CalculateIntegral::calculatePart(double start, double end, double eps){
    QTime *startTime = new QTime(QTime::currentTime());

    for(double x = start; x < end; x += eps){
        this->result += eps * pow(x, 3) * sqrt(pow(pow(x,2) + 4, 3));
    }
    QTime *endTime = new QTime(QTime::currentTime());
    this->calculatoionTime = new QTime();
    this->calculatoionTime->setHMS(0, 0, 0, endTime->msec() - startTime->msec());
    qDebug() << QObject::thread();
}

double CalculateIntegral::getResult(){
    return this->result;
}

QTime* CalculateIntegral::getDurarion(){
    return this->calculatoionTime;
}
