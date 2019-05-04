#ifndef SETSERIAL_H
#define SETSERIAL_H
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QtSerialPort/QSerialPort>    //提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>   //提供系统中存在的串口信息
#include <QDebug>



class setSerial : public QDialog
{
    Q_OBJECT
public:
   explicit  setSerial(QWidget *parent = 0);   //防止由构造函数定义的隐式转换
    ~setSerial();
     QSerialPort *serial;
private:

    QLabel *portLabel;
    QComboBox *portComboBox;   //设置端口号

    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;   //设置波特率

    QLabel *numBitLabel;
    QComboBox *numBitComboBox;   //设置数据位

    QLabel *checkBitLabel;
    QComboBox *checkBitComboBox;   //设置校验位

    QLabel *stopBitLabel;
    QComboBox *stopBitComboBox;   //设置停止位

    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QGridLayout *mainLayouGridLayout;
    void showSet();
private slots:
     void on_openButton_clicked();
     void on_cancelPushButton_clicked();
     void Read_Data();

};

#endif // SETSERIAL_H
