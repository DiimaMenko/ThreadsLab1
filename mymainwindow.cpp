#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->resize(640, 480);
    this->numberOfFinishedThreads = 0;
    this->numberOfThreads = 0;

    this->a = 3;//start of interval for integration = 3
    this->b = 5;//end of interval for integration   = 5
    this->eps1 = 0.00001;//step  = 0.001
    this->resultParallel = 0;

    this->threadLabel = new QLabel(this);
    this->threadLabel->move(20, 20);
    this->threadLabel->resize(300, 40);
    this->threadLabel->setText("Enter number of threads you want to create.");
    this->threadLabel->show();

    this->numberOfThreadsInput = new QLineEdit(this);
    this->numberOfThreadsInput->move(20, 80);
    this->numberOfThreadsInput->resize(200, 40);
    this->numberOfThreadsInput->show();

    this->startCalculationButton = new QPushButton(this);
    this->startCalculationButton->move(20, 140);
    this->startCalculationButton->resize(200, 40);
    this->startCalculationButton->setText("Press here to start calculation");
    connect(this->startCalculationButton, SIGNAL(clicked(bool)),this,SLOT(startCalculation()));

    this->startSerialCalculationButton = new QPushButton(this);
    this->startSerialCalculationButton->setText("Serial calculation");
    this->startSerialCalculationButton->move(120, 240);
    this->startSerialCalculationButton->resize(100, 40);
    this->startSerialCalculationButton->show();
    connect(this->startSerialCalculationButton,SIGNAL(clicked(bool)), this, SLOT(startSerialCalculation()));

    this->realResultLabel = new QLabel("Real result = ", this);
    this->realResultLabel->move(260, 20);
    this->realResultLabel->resize(200, 40);
    this->realResultLabel->show();

    this->realResult = new QLabel(this);
    this->realResult->move(330, 20);
    this->realResult->resize(200,40);
    double result = antiderivative(this->b) - antiderivative(this->a);
    this->realResult->setText(QString::number(result));
    this->realResult->show();
}

double MyMainWindow::antiderivative(double x){
    double res = 1.0 / 7.0 * sqrt(pow(pow(x, 2) + 4.0, 5)) * (pow(x, 2) - 8.0 / 5.0);
    return res;
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::startCalculation(){
    if(checkIfEnteredNumberOfThreads()){
        this->startCalculationButton->hide();
        this->numberOfThreadsInput->hide();

        this->startParallelCalculationButton = new QPushButton(this);
        this->startParallelCalculationButton->setText("Parallel calculation");
        this->startParallelCalculationButton->move(20, 240);
        this->startParallelCalculationButton->resize(100, 40);
        this->startParallelCalculationButton->show();
        connect(this->startParallelCalculationButton, SIGNAL(clicked(bool)), this, SLOT(startParallelCalculation()));
        //qDebug() << "connected parallel calculation start button";
    }
    else
    {
        this->threadLabel->setText("Enter valid number of threads please!\nYou can enter only numbers from 1 to 16.");
    }
}

bool MyMainWindow::checkIfEnteredNumberOfThreads(){
    this->numberOfThreads = this->numberOfThreadsInput->text().toInt();

    if(this->numberOfThreads > 0 && this->numberOfThreads < 17){
        return 1;
    }
    return 0;
}

void MyMainWindow::startParallelCalculation(){
    for(int i = 0; i < this->numberOfThreads; i++){
        MyThread *tempThread = new MyThread((this->b - this->a) / this->numberOfThreads * i + this->a, (this->b - this->a) / this->numberOfThreads * (i + 1) + this->a, this->eps1);
        myThreads.push_back(tempThread);
    }
    this->timeOfParallelCalculationsStart = QTime::currentTime();
    for(int i = 0; i < this->numberOfThreads; i++){
        myThreads[i]->start();
    }
    for(int i = 0; i < this->numberOfThreads; i++){
        myThreads[i]->wait();
    }
    this->timeOfParallelCalculations = QTime::currentTime().msecsSinceStartOfDay() - this->timeOfParallelCalculationsStart.msecsSinceStartOfDay();

    for(int i= 0; i < this->numberOfThreads; i++){
        this->resultParallel += myThreads[i]->getResult();
    }
    this->parallelResultWidget = new ResultWidget(this->numberOfThreads, this->timeOfParallelCalculations, this->resultParallel, this->eps1);
    this->parallelResultWidget->resize(500, 300);
    this->parallelResultWidget->setWindowTitle("Parallel Calculation Result");
    this->parallelResultWidget->show();
}

void MyMainWindow::startSerialCalculation(){
    MyThread *tempThread = new MyThread(this->a, this->b, eps1);
    this->timeOfSerialCalculationsStart = QTime::currentTime();
    tempThread->start();
    tempThread->wait();
    this->timeOfSerialCalculations = QTime::currentTime().msecsSinceStartOfDay() - this->timeOfSerialCalculationsStart.msecsSinceStartOfDay();
    this->resultSerial = tempThread->getResult();
    this->serialResultWidget = new ResultWidget(1, this->timeOfSerialCalculations, this->resultSerial, this->eps1);
    this->serialResultWidget->resize(500,300);
    this->serialResultWidget->setWindowTitle("Serial Calculation Result");
    this->serialResultWidget->show();
    tempThread->deleteLater();
}

