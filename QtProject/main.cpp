#include "loginDialog.h"
#include "startshow.h"
#include <QApplication>
#include "control.h"
#include "startload.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Control w;
    w.show();
    return a.exec();*/
    startShow w;
    w.show();
    return a.exec();

 /*  LoginDialog log;
    log.show();
    if(log.exec()==QDialog::Accepted){
       log.show();
        return a.exec();
    }else{
        return 0;
    }*/
}
