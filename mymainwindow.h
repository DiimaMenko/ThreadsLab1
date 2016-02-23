#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "calculateintegral.h"
#include <QTime>
#include <QDebug>
#include "resultwidget.h"
#include <mythread.h>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
public slots:
    void startSerialCalculation();
    void startParallelCalculation();
    void startCalculation();
    bool checkIfEnteredNumberOfThreads();
    void threadFinishedCalculation();
private:
    Ui::MyMainWindow *ui;
    QVector<MyThread*> myThreads;
    QVector<CalculateIntegral*> calculators;
    QPushButton *startCalculationButton;
    QPushButton *startParallelCalculationButton;
    QPushButton *startSerialCalculationButton;
    QLineEdit *numberOfThreadsInput;
    QLabel *threadLabel;
    QLabel *resultSerialLabel;
    QTime timeOfParallelCalculationsStart;
    QTime timeOfSerialCalculationsStart;
    int timeOfParallelCalculations;
    int timeOfSerialCalculations;

    ResultWidget *parallelResultWidget;
    ResultWidget *serialResultWidget;

    int numberOfThreads;//number of thread you want to create
    int numberOfFinishedThreads;//number of threads that finished work
    double a;//start of interval for integration = 3
    double b;//end of interval for integration   = 5
    double eps1;//step  = 0.00001
    double eps2;//step2 = 0.0001
    double resultParallel;
    double resultSerial;
};

#endif // MYMAINWINDOW_H
