#ifndef MULTITHREADING_H
#define MULTITHREADING_H
#include <QThread>
#include <QMutex>
#include <QtSerialPort/QSerialPort>
#include <QObject>


class Console;
class SettingsDialog;

class multithreading : public QThread
{
    Q_OBJECT

public:
    explicit multithreading(QObject *parent = 0);
    void run();

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;

signals:
    // To communicate with Gui Thread
    // we need to emit a signal
    void READDATA2(char*);
    void STATUS(int);
    void TRAFFICSWITCH(bool); //true=>READ , false=>WRITE

private:
    QSerialPort *serial;
    Console *console;
    SettingsDialog *settings;
    bool RWALRE;


private slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void READWRITETRAFFICSLOT(bool RWT); //true=>READ , false=>WRITE



};

#endif // MULTITHREADING_H
