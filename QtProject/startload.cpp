#include "startload.h"
#include "ui_startload.h"
#include "loginDialog.h"
#include <QTimer>

startLoad::startLoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startLoad)
{
    ui->setupUi(this);
    startLoadInit();

}

startLoad::~startLoad()
{
    delete ui;
}
void startLoad:: startLoadInit()
{
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::cyan);
    setPalette(p);
    ui->startLoadLabel->setStyleSheet(QString("color:blue"));
    ui->startLoadProgressLabel->setStyleSheet(QString("color:blue"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(doTimerProgress()));
    timer->start(30);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
}

void startLoad::doTimerProgress()
{
    static int progress;
    progress++;
    ui->progressBar->setValue(progress);
    if(progress==100)
    {
       LoginDialog *Login= new LoginDialog();
       Login->show();
       this->destroy();
    }

}


