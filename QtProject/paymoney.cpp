#include "paymoney.h"
#include "ui_paymoney.h"
#include<QMessageBox>

extern int time;    //停车时间
int unitPrice,payNum;
char success_flag;
payMoney::payMoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payMoney)
{

    ui->setupUi(this);
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::cyan);
    setPalette(p);
    ui->label->setFont(QFont("Times",10,QFont::Bold));   //设置字体大小  加粗
    ui->label->setStyleSheet(QString("color:blue"));        //设置字体颜色
    ui->label_2->setFont(QFont("Times",10,QFont::Bold));   //设置字体大小  加粗
    ui->label_2->setStyleSheet(QString("color:blue"));        //设置字体颜色
    ui->label_3->setFont(QFont("Times",10,QFont::Bold));   //设置字体大小  加粗
    ui->label_3->setStyleSheet(QString("color:blue"));        //设置字体颜色
    ui->unitPricelineEdit->setText("2");
    ui->stopTimelineEdit->setText(QString::number(time,10));
    unitPrice= ui->unitPricelineEdit->text().toInt();
    payNum=unitPrice*time;
    ui->payMoneyLineEdit->setText(QString::number(payNum,10));
}

payMoney::~payMoney()
{
    delete ui;
}

void payMoney::on_okPushButton_clicked()
{
    QString str;
    str=QString("停车时间%1s缴费%2").arg(time).arg(payNum);
    QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this,  "缴费",
                                              str,
                                              QMessageBox::Yes | QMessageBox::Cancel);
       if (reply == QMessageBox::Yes)
               success_flag=1; 
           else
               success_flag=0;
       emit payInfo(success_flag);
       this->hide();
}

void payMoney::on_cancelPushButton_clicked()
{
    this->hide();
}
