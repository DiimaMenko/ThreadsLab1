#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

static int a = 0;

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();
};

#endif // MYTHREAD_H
