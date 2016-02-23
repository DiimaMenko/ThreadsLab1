#ifndef PARALLELRESULTWIDGET_H
#define PARALLELRESULTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QTime>

class ResultWidget : public QWidget
{
    Q_OBJECT
public:
    QLabel *TimeLabel;
    QLabel *DurationTime;
    QLabel *NumberOfThreadsLabel;
    QLabel *NumberOfThreads;
    QLabel *ResultLabel;
    QLabel *ResultOfCalculation;
    QLabel *PrecisionLabel;
    QLabel *Precision;
    ResultWidget();
    ResultWidget(int numberOfThreads, int duration, double result, double precision);
};

#endif // PARALLELRESULTWIDGET_H
