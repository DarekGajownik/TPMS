#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSerialPort"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void sendToDevice1(QString message);


private:
    Ui::MainWindow *ui;
     QSerialPort *device;
     QList<QSerialPortInfo> LDevices;

     void addToLogs(QString message);
     void sendToDevice(QString message);
};

#endif // MAINWINDOW_H
