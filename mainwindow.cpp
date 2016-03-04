/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include "settingsdialog.h"
#include <QDebug>
#include <iostream>

using namespace std;

bool automode = false; // false = manual , true = auto mode.

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//! [0]
    ui->setupUi(this);

    //! [1]
    settings = new SettingsDialog;
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    ui->lineEdit->setEnabled(false);
    ui->listWidget->setEnabled(false);
    ui->STARTBT->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
     ui->pushButton_4->setEnabled(false);
      ui->pushButton_5->setEnabled(false);
       ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
         ui->pushButton_8->setEnabled(false);


           //ui->pushButton_11->setEnabled(false);
           ui->pushButton_13->setEnabled(false);
           ui->pushButton_15->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->actionClear->setEnabled(false);

    connect(ui->actionQuit, SIGNAL(triggered()), settings, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), ui->listWidget, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));


    serial = new QSerialPort(this);
    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
               SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    STATUSUPDATE(2); //Disconnect
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    if(!(ui->lineEdit->text().isEmpty()))
    {
        automode = false;
        serial->waitForBytesWritten(1000);
        serial->waitForReadyRead(100);
        writeData(ui->lineEdit->text().toLocal8Bit());
        ui->lineEdit->clear();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    NUMBEROFROBOTICSCODE = 0;
    ui->NumberOfRobotics_label->setText(QString::number(NUMBEROFROBOTICSCODE));
}

void MainWindow::on_pushButton_clicked()//UPLOAD CODE
{
    NUMBEROFROBOTICSCODE = 0;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "C:/Users/Administrator/CODE/RobotArm/J-Code", tr("Text Files (*txt)"));


    char dir[256];
    strcpy(dir,fileName.toStdString().c_str());
    ifstream ROBOTICSUPLOADDIRECTORY(dir);

    string ROBOTICSCODE;
    if (ROBOTICSUPLOADDIRECTORY.is_open())               // Open scanned wifilist
    {
      while ( getline (ROBOTICSUPLOADDIRECTORY,ROBOTICSCODE) )
      {
        ui->listWidget->addItem(QString(ROBOTICSCODE.c_str()));
        NUMBEROFROBOTICSCODE++;
      }
      ROBOTICSUPLOADDIRECTORY.close();
    }else cout << "Unable to open file";

    ui->NumberOfRobotics_label->setText(QString::number(NUMBEROFROBOTICSCODE));
}


void MainWindow::STATUSUPDATE(int status)
{

if(status == 1){                                    //Connected
    cout<<"Conected"<<endl;
    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    ui->actionConfigure->setEnabled(false);
    ui->lineEdit->setEnabled(true);
    ui->listWidget->setEnabled(true);
    ui->STARTBT->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
     ui->pushButton_4->setEnabled(true);
      ui->pushButton_5->setEnabled(true);
       ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
         ui->pushButton_8->setEnabled(true);

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->actionClear->setEnabled(true);


    //ui->pushButton_11->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_15->setEnabled(true);


    ui->listWidget_2->setEnabled(true);
    ui->save_bt->setEnabled(true);
    ui->del_bt->setEnabled(true);
    ui->cleartrain_bt->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);

    ui->statusBar->showMessage("Connected.");

}
else if(status == 2){                               //Disconnect
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    ui->lineEdit->setEnabled(false);
    ui->listWidget->setEnabled(false);
    ui->STARTBT->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
     ui->pushButton_4->setEnabled(false);
      ui->pushButton_5->setEnabled(false);
       ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
         ui->pushButton_8->setEnabled(false);




             //ui->pushButton_11->setEnabled(false);
             ui->pushButton_13->setEnabled(false);
             ui->pushButton_15->setEnabled(false);




    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->actionClear->setEnabled(false);

    ui->listWidget_2->setEnabled(false);
    ui->save_bt->setEnabled(false);
    ui->del_bt->setEnabled(false);
    ui->cleartrain_bt->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);

    ui->statusBar->showMessage(tr("Can't connect"));
}else if(status == 3){                                      //Disconnect
     ui->statusBar->showMessage(tr("Configure error"));
}else if(status == 4){                                      //Configure error
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->lineEdit->setEnabled(false);
    ui->listWidget->setEnabled(false);
    ui->STARTBT->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
     ui->pushButton_4->setEnabled(false);
      ui->pushButton_5->setEnabled(false);
       ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
         ui->pushButton_8->setEnabled(false);




              //ui->pushButton_11->setEnabled(false);
              ui->pushButton_13->setEnabled(false);
              ui->pushButton_15->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->actionClear->setEnabled(false);

    ui->listWidget_2->setEnabled(false);
    ui->save_bt->setEnabled(false);
    ui->del_bt->setEnabled(false);
    ui->cleartrain_bt->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);

    ui->statusBar->showMessage(tr("Disconnected"));
}else if(status == 5){                                      //Resource error
    ui->statusBar->showMessage(tr("Resource error."));
}




}

void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
            STATUSUPDATE(1);

    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());
        ui->statusBar->showMessage(tr("Open error"));
        STATUSUPDATE(2);
    }
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));



    STATUSUPDATE(2); //Disconnect
}


void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}


QString datatowrite;
void MainWindow::on_STARTBT_clicked() //RUNNING ROBOTICS CODE
{
    automode = true;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("J10;J2TR;J3RD;J40;J5RD;J60;#");

}

void MainWindow::sendata(int i){

    serial->waitForBytesWritten(1000);
    datatowrite = QString(ui->listWidget->item(i)->text().toLocal8Bit());
    cout<<datatowrite.toStdString()<<endl;
    writeData(datatowrite.toLocal8Bit());
}

int count_command =0;
QString data_read_all;
void MainWindow::readData()
{
        while(serial->bytesAvailable() > 0){

            serial->waitForReadyRead(100);
            datastr = serial->read(1);
            cout<<datastr.toStdString()<<endl;

            if(datastr != "P" && datastr != "F"){

                data_read_all.append(datastr);

            }

            cout<<"RUNNING MANUAL"<<endl;

            if(automode == true){
                if(datastr == "F"){
                    count_command++;
                    if(!(count_command > ui->NumberOfRobotics_label->text().toInt()))
                        sendata(count_command-1);
                    else
                     count_command = 0;

                  }
             }

    }
    cout<<data_read_all.toStdString()<<endl;

    if(!(data_read_all.isEmpty()))
    ui->listWidget_2->addItem(data_read_all);

    data_read_all.clear();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}


void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}


void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{

       ui->NumberOfRobotics_label_2->setText(QString::number(ui->listWidget->currentRow()+1));

       datatowrite = QString(ui->listWidget->currentItem()->text());

}

void MainWindow::on_cleartrain_bt_clicked()
{
    ui->listWidget_2->clear();
}

void MainWindow::on_save_bt_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Open Image"), "C:/Users/Administrator/CODE/RobotArm/J-Code", tr("Text Files (*txt)"));

    fileName.append(".txt");

    QFile pfile(fileName);
    if (!pfile.open(QFile::WriteOnly | QIODevice::Text))
    {
        return;
    }

    for(int row = 0; row < ui->listWidget_2->count(); row++)
    {
        QListWidgetItem *item = ui->listWidget_2->item(row);
        QTextStream out(&pfile);
        out << item->text().simplified() << "\n";
    }

    pfile.close();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    if(!(ui->lineEdit_2->text().isEmpty()))
    {
        ui->listWidget_2->addItem(ui->lineEdit_2->text());
        ui->lineEdit_2->clear();
    }
}

void MainWindow::on_del_bt_clicked()
{
    QListWidgetItem* item = ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    delete item;
}


void MainWindow::on_pushButton_4_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ2");
}

void MainWindow::on_pushButton_5_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ3");
}

void MainWindow::on_pushButton_6_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ4");
}

void MainWindow::on_pushButton_7_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ5");
}

void MainWindow::on_pushButton_8_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ6");
}

void MainWindow::on_pushButton_3_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("TRJ1");
}

void MainWindow::on_pushButton_11_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("J1SZ;J2SZ;J3SZ;J4SZ;J5SZ;J6SZ;#");
}

void MainWindow::on_pushButton_13_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("J10;J20;J30;J40;J50;J60;#");
}

void MainWindow::on_pushButton_15_clicked()
{
    automode = false;
    serial->waitForBytesWritten(1000);
    serial->waitForReadyRead(100);
    writeData("LEARN");
}
