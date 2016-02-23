#include "resultwidget.h"

ResultWidget::ResultWidget(){

}

ResultWidget::ResultWidget(int numberOfThreads, int duration, double result, double precision)
{
    this->TimeLabel = new QLabel("Duration (msec):",this);
    this->DurationTime = new QLabel(QString::number(duration),this);
    this->NumberOfThreadsLabel = new QLabel("Number of threads", this);
    this->NumberOfThreads = new QLabel(QString::number(numberOfThreads), this);
    this->ResultLabel = new QLabel("Result:", this);
    this->ResultOfCalculation = new QLabel(QString::number(result), this);
    this->PrecisionLabel = new QLabel("Preciison", this);
    this->Precision = new QLabel(QString::number(precision), this);

    this->NumberOfThreadsLabel->move(20, 20);
    this->NumberOfThreads->move(300, 20);
    this->PrecisionLabel->move(20,80);
    this->Precision->move(300, 80);
    this->TimeLabel->move(20, 140);
    this->DurationTime->move(300, 140);
    this->ResultLabel->move(20, 200);
    this->ResultOfCalculation->move(300, 200);

    this->NumberOfThreadsLabel->resize(260, 40);
    this->NumberOfThreads->resize(260, 40);
    this->PrecisionLabel->resize(260, 40);
    this->Precision->resize(260, 40);
    this->TimeLabel->resize(260, 40);
    this->DurationTime->resize(260, 40);
    this->ResultLabel->resize(260, 40);
    this->ResultOfCalculation->resize(260, 40);

    this->NumberOfThreadsLabel->show();
    this->NumberOfThreads->show();
    this->PrecisionLabel->show();
    this->Precision->show();
    this->TimeLabel->show();
    this->DurationTime->show();
    this->ResultLabel->show();
    this->ResultOfCalculation->show();
}

