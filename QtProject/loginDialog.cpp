#include "loginDialog.h"
#include "ui_loginDialog.h"
#include "control.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("登录系统界面"));
    ui->passwordText->setEchoMode(QLineEdit::Password);
    ui->accountText->setFocus();
  ui->okBtn->setDefault(true);  
}

LoginDialog::~LoginDialog()
{
    delete ui;
}





void LoginDialog::on_okBtn_clicked()
{
    if(ui->accountText->text().isEmpty()){
        QMessageBox::information(this,tr("请输入账号"),tr("请先输入账号再登录！"),QMessageBox::Ok);
        ui->accountText->setFocus();
    }else{
        if("liu" == ui->accountText->text()){
            if(ui->passwordText->text().isEmpty()){
                QMessageBox::information(this,tr("请输入密码"),tr("请先输入密码再登录！"),QMessageBox::Ok);
                ui->passwordText->setFocus();
            }else{
                if("1234" == ui->passwordText->text()){
                   Control *con=new Control();
                   con->show();
                   this->destroy();
                }else{
                    QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                    ui->passwordText->clear();
                    ui->passwordText->setFocus();
                }
            }
        }else{
            QMessageBox::warning(this,tr("账号错误"),tr("账号不存在"),QMessageBox::Ok);
            ui->accountText->clear();
            ui->accountText->setFocus();
        }
    }
}


void LoginDialog::on_cancelBtn_clicked()
{
   QDialog::reject();
}
