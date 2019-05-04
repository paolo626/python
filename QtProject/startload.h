#ifndef STARTLOAD_H
#define STARTLOAD_H

#include <QWidget>

namespace Ui {
class startLoad;
}

class startLoad : public QWidget
{
    Q_OBJECT

public:
    explicit startLoad(QWidget *parent = 0);
    ~startLoad();

private:
    Ui::startLoad *ui;
    void startLoadInit();
private slots:
    void doTimerProgress();
};

#endif // STARTLOAD_H
