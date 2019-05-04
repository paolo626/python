#include "startshow.h"
#include "startload.h"
#include "ui_startshow.h"
#include <QMovie>
#include <QWidget>
#include<QResizeEvent>

startShow::startShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startShow)
{
    ui->setupUi(this);
    startShowInit();
}

startShow::~startShow()
{
    delete ui;
}
void startShow::startShowInit()
{
  setWindowTitle(tr("登陆画面"));
  ui->startShowLabel->setMovie(new QMovie("Spark.gif"));
  ui->startShowLabel->movie()->start();
  ui->startShowLabel->setScaledContents(true);
  ui->startShowLabel->setGeometry(0,0,this->width(),this->height());



}
//图像宽度随窗体变化

void startShow::resizeEvent(QResizeEvent *resize)
{
   ui->startShowLabel->setGeometry(0,0, resize->size().width(),resize->size().height());
}

void startShow::mousePressEvent(QMouseEvent *e)
{
  startLoad *Load= new startLoad();
  Load->show();
  this->destroy();
}
