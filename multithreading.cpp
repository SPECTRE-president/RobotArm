#include "multithreading.h"
#include "mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include <QMessageBox>
#include <iostream>
#include <qmetaobject.h>
#include <QMetaType>
#include <QDebug>

using namespace std;
bool connected = false;

multithreading::multithreading(QObject *parent) :
    QThread(parent)
{

}

// run() will be called when a thread starts
void multithreading::run()  //Receive Data from serial communication.
{

QMutex mutex;
bool WRITEALLOWED = true;

console = new Console;
console->setEnabled(false);
//! [1]
    settings = new SettingsDialog;

//! [1]
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));
//! [2]
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
//! [2]
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
//! [3]

openSerialPort();
writeData("REQSEND#");
readData();
/*
for(;;)
{
    if(connected == true)
    {
               // Mutex area  ----------------------------------------------------------------------


                if(this->Stop){}
                //Do something in this mutex area.

                // Serial Communication
                if(RWALRE == true && WRITEALLOWED == true){ //READY TO WRITE.
                    mutex.lock();              // prevent other threads from changing the "Stop" value

                    serial->write("REQSEND#");
                    emit TRAFFICSWITCH(false);   //WRITE SUCCESS
                    WRITEALLOWED = false;
                    cout<<"REQUEST DATA"<<endl;

                    mutex.unlock();
                    //Unlock mutex  ---------------------------------------------------------------------
                }

                 if(RWALRE == false && WRITEALLOWED == false)    //READY TO READ
                 {
                        cout<<"WAIT TARGET CONFIRM"<<endl;
                        QByteArray data = serial->readAll();

                        while(QString(data).toStdString() != "OK")
                         {
                            //Wait for target ready.
                            //cout<<"Wait confirmation."<<endl;
                            readData();
                            data.clear();
                            data = serial->readAll();
                         }
                        //emit TRAFFICSWITCH(false);  //READ
                        WRITEALLOWED = true;
                        cout << "TARGET HAS BEEN CONFIRMED" <<endl;
                        return;

                 }
                 if(WRITEALLOWED == true && RWALRE == false)
                 {
                     cout << "TRANMISSION ALLOWED." <<endl;
                     mutex.lock();              // prevent other threads from changing the "Stop" value

                     serial->write("J330;#");

                     emit TRAFFICSWITCH(false);   //WRITE SUCCESS
                     WRITEALLOWED = false;
                     mutex.unlock();
                 }

  }
}*/
}
//! [4]
void multithreading::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    if (serial->open(QIODevice::ReadWrite)) {
        if (serial->setBaudRate(p.baudRate)
                && serial->setDataBits(p.dataBits)
                && serial->setParity(p.parity)
                && serial->setStopBits(p.stopBits)
                && serial->setFlowControl(p.flowControl)) {

            //console->setEnabled(true);
            console->setLocalEchoEnabled(p.localEchoEnabled);
            connected = true;
            emit STATUS(1);
        } else {
            serial->close();
            //QMessageBox::critical(this, tr("Error"), serial->errorString());
            emit STATUS(2);
        }
    } else {
        //QMessageBox::critical(this, tr("Error"), serial->errorString());

       emit STATUS(3);
    }
}
//! [4]

//! [5]
void multithreading::closeSerialPort()
{
    serial->close();
    console->setEnabled(false);
    emit STATUS(4);
}
//! [5]


//! [7]
void multithreading::readData()
{
    QByteArray data = serial->readAll();
    cout<< "Data=>" <<QString(data).toStdString() <<endl;
    console->putData(data);
}
//! [7]

//! [8]
void multithreading::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        //QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        emit STATUS(4);
        closeSerialPort();
    }
}
//! [8]

//! [6]
void multithreading::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

void multithreading::READWRITETRAFFICSLOT(bool RWT)
{
if(RWT == true)     //Ready to write.
RWALRE = true;


if(RWT == false)    //Ready to read.
RWALRE = false;

}
