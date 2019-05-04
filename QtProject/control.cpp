#include "control.h"
#include "setserial.h"





Control::Control(QWidget *parent) : QWidget(parent)
{
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::cyan);
    setPalette(p);
//最上面 标题
     titleLabel =new QLabel(tr("充电柜系统"));
     titleLabel->setFont(QFont("Times",18,QFont::Bold));   //设置字体大小  加粗
     titleLabel->setStyleSheet(QString("color:blue"));        //设置字体颜色
     titleLabel->setAlignment(Qt::AlignHCenter);     //设置居中对齐

//中左  提示信息框
     messageLabel=new QLabel(tr("提示信息"));
     messageLabel->setStyleSheet("color:blue");
     messageLabel->setFont(QFont("Times",10,QFont::Bold));
     infoTextEdit=new QTextEdit;
     infoTextEdit->setGeometry(9,9,200,25);
//中右 车位状态 停车时间
     QFont font;
     font.setPointSize(10);
     font.setBold(true);

     SparkingStatusLabel=new QLabel(tr("当前用户："));
     SparkingStatusLabel->setStyleSheet("color:blue");
     SparkingStatusLabel->setFont(font);
     SparkingStatusShowQLabel=new QLabel;

     SparkingStatusShowQLabel->setText("无");
     SparkingStatusShowQLabel->setStyleSheet("color:blue");
     SparkingStatusShowQLabel->setFont(font);
     LedOne=new QLabel(tr("镍氢矿灯:"));
     LedOne->setStyleSheet("color:blue");
     LedOne->setFont(font);
     StatusOne=new QLabel(tr("待测"));
     StatusOne->setStyleSheet("color:blue");
     StatusOne->setFont(font);


     LedTwo=new QLabel(tr("锰酸锂矿灯:"));
     LedTwo->setStyleSheet("color:blue");
     LedTwo->setFont(font);
     StatusTwo=new QLabel(tr("待测"));
     StatusTwo->setStyleSheet("color:blue");
     StatusTwo->setFont(font);

     LedThree=new QLabel(tr("锰酸锂矿灯:"));
     LedThree->setStyleSheet("color:blue");
     LedThree->setFont(font);
     StatusThree=new QLabel(tr("待测"));
     StatusThree->setStyleSheet("color:blue");
     StatusThree->setFont(font);

     LedFour=new QLabel(tr("通用矿灯:"));
     LedFour->setStyleSheet("color:blue");
     LedFour->setFont(font);
     StatusFour=new QLabel(tr("待测"));
     StatusFour->setStyleSheet("color:blue");
     StatusFour->setFont(font);

     LedFive=new QLabel(tr("自救器:"));
     LedFive->setStyleSheet("color:blue");
     LedFive->setFont(font);
     StatusFive=new QLabel(tr("待测"));
     StatusFive->setStyleSheet("color:blue");
     StatusFive->setFont(font);


//最下 控件
     openBtn=new QPushButton(tr("开锁"));
     openBtn->setStyleSheet("color:blue");

     connectBtn=new QPushButton(tr("连接串口"));
     connectBtn->setStyleSheet("color:blue");
//布局  中左
     MidLetfVBoxLayout = new QVBoxLayout();
     MidLetfVBoxLayout->setMargin(10);
     MidLetfVBoxLayout->addWidget(messageLabel);
     MidLetfVBoxLayout->addWidget(infoTextEdit);
     MidLetfVBoxLayout->setSpacing(5);
//布局 中右
     MidRightGridLayout=new QGridLayout();
     MidRightGridLayout->addWidget(SparkingStatusLabel,0,0);
     MidRightGridLayout->addWidget(SparkingStatusShowQLabel,0,1);
     MidRightGridLayout->addWidget(LedOne,1,0);
     MidRightGridLayout->addWidget(StatusOne,1,1);
     MidRightGridLayout->addWidget(LedTwo,2,0);
      MidRightGridLayout->addWidget(StatusTwo,2,1);
     MidRightGridLayout->addWidget(LedThree,3,0);
      MidRightGridLayout->addWidget(StatusThree,3,1);
     MidRightGridLayout->addWidget(LedFour,4,0);
      MidRightGridLayout->addWidget(StatusFour,4,1);
      MidRightGridLayout->addWidget(LedFive,5,0);
       MidRightGridLayout->addWidget(StatusFive,5,1);
     MidRightGridLayout->setSpacing(5);
     MidRightGridLayout->setColumnStretch(0,1);
     MidRightGridLayout->setColumnStretch(1,5);
 //布局 中
     MidHBoxLayout=new QHBoxLayout();
     MidHBoxLayout->setMargin(15);
     MidHBoxLayout->setSpacing(10);
     MidHBoxLayout->addLayout(MidLetfVBoxLayout);
     MidHBoxLayout->addLayout(MidRightGridLayout);
 //下 布局
     downHBoxLayout=new QHBoxLayout();
     downHBoxLayout->setMargin(20);
     downHBoxLayout->setSpacing(50);
     downHBoxLayout->addWidget(openBtn);

     downHBoxLayout->addWidget(connectBtn);

 //整体布局
     mainVBoxLayout=new QVBoxLayout (this);
     mainVBoxLayout->addWidget(titleLabel);
     mainVBoxLayout->addLayout(MidHBoxLayout);
     mainVBoxLayout->addLayout(downHBoxLayout);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(doTimeProess()));
    timer->start(1000);
    connect(openBtn,SIGNAL(clicked()),this,SLOT(openFun()));

    connect(connectBtn,SIGNAL(clicked()),this,SLOT(connectFun()));   //串口配置


}

Control::~Control()
{

}
QByteArray str;

void Control::openFun()    //开锁命令
{


    str[0]=1;

    set->serial->write(str);

}





QByteArray buf;

void Control::doTimeProess()
{


    if(!buf.isEmpty())
    {


        if(buf.contains("A"))
        {
            infoTextEdit->append("A用户已经登陆\r\n");
            SparkingStatusShowQLabel->setText("A用户");


        }
        else if(buf.contains("B"))
        {
            infoTextEdit->append("B用户已经登陆\r\n");
            SparkingStatusShowQLabel->setText("B用户");
        }
        else if(buf.contains("1no"))
        {
            infoTextEdit->append("镍氢矿灯不在位\r\n");
            StatusOne->setText("不在位");
        }
        else  if(buf.contains("1yes"))
        {
            infoTextEdit->append("镍氢矿灯在位\r\n");
            StatusOne->setText("在位");
        }
        else if(buf.contains("2no"))
        {
            infoTextEdit->append("锰酸锂矿灯不在位\r\n");
            StatusTwo->setText("不在位");
        }
        else if(buf.contains("2yes"))
        {
            infoTextEdit->append("锰酸锂矿灯在位\r\n");
            StatusTwo->setText("在位");
        }
        else if(buf.contains("3no"))
        {
            infoTextEdit->append("磷酸铁锂矿灯不在位\r\n");
            StatusThree->setText("不在位");
        }
        else if(buf.contains("3yes"))
        {
            infoTextEdit->append("磷酸铁锂矿灯在位\r\n");
            StatusThree->setText("在位");
        }
        else if(buf.contains("4no"))
        {
            infoTextEdit->append("通用矿灯不在位\r\n");
            StatusFour->setText("不在位");
        }
        else if(buf.contains("4yes"))
        {
            infoTextEdit->append("通用矿灯在位\r\n");
            StatusFour->setText("不在位");
        }
        else if(buf.contains("5no"))
        {
            infoTextEdit->append("自救器不在位\r\n");
            StatusFive->setText("不在位");
        }
        else if(buf.contains("5yes"))
        {
            infoTextEdit->append("自救器在位\r\n");
            StatusFive->setText("不在位");

        }



        buf.clear();
     }


}

void Control::connectFun()
{
  set =new setSerial();
  set->show();
}

