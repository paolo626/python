#ifndef STARTSHOW_H
#define STARTSHOW_H

#include <QWidget>

namespace Ui {
class startShow;
}

class startShow : public QWidget
{
    Q_OBJECT

public:
    explicit startShow(QWidget *parent = 0);
    ~startShow();

private:
    Ui::startShow *ui;
    void startShowInit();
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // STARTSHOW_H
