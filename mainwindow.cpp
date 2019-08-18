#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtabbar.h"
#include "qpushbutton.h"	
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include "QDebug"
#include <QDateTime>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->device=new QSerialPort(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    addToLogs( "Wcisnąłeś przycisk Połącz");


    LDevices = QSerialPortInfo::availablePorts();
    for(int i = 0; i < LDevices.count(); i++)
    {

        addToLogs( LDevices.at(i).portName() + LDevices.at(i).description());

        QString portName = LDevices.at(0).portName();
        this->device->setPortName(portName);

        // OTWÓRZ I SKONFIGURUJ PORT:
        if(device->open(QSerialPort::ReadWrite)) {
            this->device->setBaudRate(QSerialPort::Baud9600);
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);
        }
        else {


        }

        // wyslij zapytanie

        for (qint a=0;a++;a<4) {


        this->sendToDevice("cc1101TPMS");
    // odczekanie na odpowiedz
     // QTimer::singleShot(500, this, SLOT(sendToDevice1("pauza koniec")));
      QTime  delTime =QTime::currentTime().addSecs(5);
      while(QTime::currentTime()<delTime);

        //  while (timer->is);
     this->sendToDevice("sprawdzam odpowiedz");

      bool answer=0;

      if(answer==1)
      {
      break;
      }
      else {

      }
        }

    }

}


void MainWindow::addToLogs(QString message)
{
    QString curnetDateAndTime=QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEdit->append(curnetDateAndTime + "\t" +message);
qApp->processEvents();
}


void MainWindow::sendToDevice(QString message)
{
    if (device->isOpen() && device->isWritable())
    {
        this->addToLogs("wysyłam:"  + message);
                this->device->write(message.toStdString().c_str());

    }
    else {
        this->addToLogs("nie mogę wyslać wiadomosci");
    }


}

void MainWindow::sendToDevice1(QString message)
{
    if (device->isOpen() && device->isWritable())
    {
        this->addToLogs("wysyłam:"  + message);
                this->device->write(message.toStdString().c_str());

    }
    else {
        this->addToLogs("nie mogę wyslać wiadomosci");
    }


}
