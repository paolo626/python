#ifndef PAYMONEY_H
#define PAYMONEY_H

#include <QWidget>

namespace Ui {
class payMoney;
}

class payMoney : public QWidget
{
    Q_OBJECT

public:
    explicit payMoney(QWidget *parent = 0);
    ~payMoney();

private slots:
    void on_okPushButton_clicked();

    void on_cancelPushButton_clicked();
signals:
    void payInfo(char);

private:
    Ui::payMoney *ui;
};

#endif // PAYMONEY_H
