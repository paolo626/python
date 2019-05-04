#include "setserial.h"

setSerial::setSerial(QWidget *parent) :QDialog(parent)
{
  showSet();

  foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
     {
         QSerialPort serial;
         serial.setPort(info);
         if(serial.open(QIODevice::ReadWrite))
         {
            portComboBox->addItem(serial.portName());
            serial.close();
         }
     }
     //设置波特率下拉菜单默认显示第三项
     baudRateComboBox->setCurrentIndex(2);
     numBitComboBox->setCurrentIndex(3);
     qDebug() << tr("界面设定成功！");
}

void setSerial::showSet()
{
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::cyan);
    setPalette(p);

    setWindowTitle(tr("串口配置"));   //端口号的选择
    resize(200,200);
    portLabel=new QLabel(tr("端口号"));
    portComboBox=new QComboBox();


    baudRateLabel=new QLabel(tr("波特率"));   //波特率的选择
    baudRateComboBox=new QComboBox();
    QStringList str;
    str.append("9600");
    str.append("4800");
    str.append("38400");
    str.append("57600");
    str.append("115200");
      baudRateComboBox->addItems(str);
   /*
    baudRateComboBox->addItem(tr("9600"));
    baudRateComboBox->addItem(tr("4800"));
    baudRateComboBox->addItem(tr("38400"));
    baudRateComboBox->addItem(tr("57600"));
    baudRateComboBox->addItem(tr("115200"));*/

    numBitLabel=new QLabel(tr("数据位"));
    numBitComboBox=new QComboBox();
    numBitComboBox->addItem(tr("5"));
    numBitComboBox->addItem(tr("6"));
    numBitComboBox->addItem(tr("7"));
    numBitComboBox->addItem(tr("8"));

    checkBitLabel=new QLabel(tr("校验位"));
    checkBitComboBox=new QComboBox();
    checkBitComboBox->addItem(tr("0"));
    checkBitComboBox->addItem(tr("1"));
    checkBitComboBox->addItem(tr("2"));

    stopBitLabel=new QLabel(tr("停止位"));
    stopBitComboBox =new QComboBox();
    stopBitComboBox->addItem(tr("1"));
    stopBitComboBox->addItem(tr("1.5"));
    stopBitComboBox->addItem(tr("2"));

    okPushButton=new QPushButton(tr("确定"));
    cancelPushButton=new QPushButton(tr("取消"));
    mainLayouGridLayout =new QGridLayout (this);
    mainLayouGridLayout->addWidget(portLabel,0,0);
    mainLayouGridLayout->addWidget(portComboBox,0,1);
    mainLayouGridLayout->addWidget(baudRateLabel,1,0);
    mainLayouGridLayout->addWidget(baudRateComboBox,1,1);
    mainLayouGridLayout->addWidget(numBitLabel,2,0);
    mainLayouGridLayout->addWidget(numBitComboBox,2,1);
    mainLayouGridLayout->addWidget(checkBitLabel,3,0);
    mainLayouGridLayout->addWidget(checkBitComboBox,3,1);
    mainLayouGridLayout->addWidget(stopBitLabel,4,0);
    mainLayouGridLayout->addWidget(stopBitComboBox,4,1);
    mainLayouGridLayout->addWidget(okPushButton,5,0);
    mainLayouGridLayout->addWidget(cancelPushButton,5,1);
    mainLayouGridLayout->setColumnStretch(0,1);
    mainLayouGridLayout->setColumnStretch(1,2);

    connect(okPushButton,SIGNAL(clicked()),this,SLOT(on_openButton_clicked()));
    connect(cancelPushButton,SIGNAL(clicked()),this,SLOT(on_cancelPushButton_clicked()));
}

setSerial::~setSerial()
 {

 }

void setSerial::on_openButton_clicked()   //设置打开串口
{
           serial = new QSerialPort;
           //设置串口名
           serial->setPortName(portComboBox->currentText());
           //打开串口
           serial->open(QIODevice::ReadWrite);
           //设置波特率
           serial->setBaudRate(baudRateComboBox->currentText().toInt());
           //设置数据位数
           switch(numBitComboBox->currentIndex())
           {
           case 8: serial->setDataBits(QSerialPort::Data8); break;
           default: break;
           }
           //设置奇偶校验
           switch(checkBitComboBox->currentIndex())
           {
           case 0: serial->setParity(QSerialPort::NoParity); break;
           default: break;
           }
           //设置停止位
           switch(stopBitComboBox->currentIndex())
           {
           case 1: serial->setStopBits(QSerialPort::OneStop); break;
           case 2: serial->setStopBits(QSerialPort::TwoStop); break;
           default: break;
           }
           //设置流控制
           serial->setFlowControl(QSerialPort::NoFlowControl);
           //关闭设置菜单使能
           portComboBox->setEnabled(false);
           baudRateComboBox->setEnabled(false);
           numBitComboBox->setEnabled(false);
           checkBitComboBox->setEnabled(false);
           stopBitComboBox->setEnabled(false);
           //连接信号槽
           QObject::connect(serial, &QSerialPort::readyRead, this, &setSerial::Read_Data);
           this->hide();
}
extern QByteArray buf;
void setSerial::Read_Data()
{
   buf = serial->readAll();

}
void setSerial::on_cancelPushButton_clicked()
{
 //  serial->write(QString("fghj").toLatin1());
    serial->close();
    this->destroy();
}


