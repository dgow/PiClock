#ifndef ARSCH_H
#define ARSCH_H

#include <QWidget>

namespace Ui {
class Arsch;
}

class Arsch : public QWidget
{
    Q_OBJECT

public:
    explicit Arsch(QWidget *parent = 0);
    ~Arsch();

 signals:
    void GoBack();

private slots:
    void on_pushButton_clicked();

    void on_hourDown_clicked();

    void on_hourUp_clicked();

    void on_minuteDown_clicked();

    void on_minuteUp_clicked();

private:
    void UpdateTime();

    Ui::Arsch *ui;

    int hour;
    int minute;
};

#endif // ARSCH_H
