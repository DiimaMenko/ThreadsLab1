#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
    double a;
    double b;
    double result;
    double eps;
public:
    MyThread();
    MyThread(double start, double end, double eps);
    double getResult();
    void run();
};

#endif // MYTHREAD_H
