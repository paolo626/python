#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>
#include <QPalette>
#include <QTimer>
#include <QLCDNumber>
#include "setserial.h"
#include "paymoney.h"

class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(QWidget *parent = 0);  //explicit修饰的构造函数不能在隐式转换中国使用
    ~Control();
    QTextEdit *infoTextEdit;  //显示相关信息  中左
private:
    //最上
    QLabel *titleLabel;   //标题

    //中间
    QLabel *messageLabel;
    QVBoxLayout *MidLetfVBoxLayout;
    QLabel *SparkingStatusLabel;  //车位状态
    QLabel *SparkingStatusShowQLabel;
    QLabel *LedOne;
        QLabel *LedTwo;
            QLabel *LedThree;
                QLabel *LedFour;
                        QLabel *LedFive;
                               QLabel *StatusOne;
                                QLabel *StatusTwo;
                                 QLabel *StatusThree;
                                  QLabel *StatusFour;
                                   QLabel *StatusFive;
    QLCDNumber *StopTimeLCDNumber;  //中右
    QGridLayout *MidRightGridLayout ;
    QHBoxLayout *MidHBoxLayout;
    //最下
    QPushButton *openBtn;

    QPushButton *connectBtn;
    QHBoxLayout *downHBoxLayout;
    QVBoxLayout *mainVBoxLayout;
    setSerial *set;
    payMoney *Pay;



public slots:
    void openFun();

    void connectFun();
    void doTimeProess();
   // void recPayIfo(char);
};

#endif // CONTROL_H
