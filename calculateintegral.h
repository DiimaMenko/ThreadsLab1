#ifndef CALCULATEINTEGRAL_H
#define CALCULATEINTEGRAL_H

#include <QObject>
#include <QTime>
#include <QDebug>

class CalculateIntegral : public QObject
{
    Q_OBJECT
    double result;
    QTime *calculatoionTime;
public:
    CalculateIntegral();
    void calculatePart(double start, double end, double eps);
    double getResult();
    QTime* getDurarion();
};

#endif // CALCULATEINTEGRAL_H
