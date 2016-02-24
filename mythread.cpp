#include "mythread.h"

#include <iostream>
#include <QtMath>

MyThread::MyThread()
{

}

MyThread::MyThread(double start, double end, double eps){
    this->a = start;
    this->b = end;
    this->eps = eps;
}

void MyThread::run(){
    for(double x = this->a; x < this->b; x += this->eps){
        this->result += this->eps * pow(x, 3) * sqrt(pow(pow(x,2) + 4, 3));
    }
}

double MyThread::getResult(){
    return this->result;
}
