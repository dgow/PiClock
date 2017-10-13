#ifndef ARSCH_H
#define ARSCH_H

#include <QWidget>
#include <QVector>
#include <QList>
#include <weekdaybutton.h>

namespace Ui {
class Arsch;
}

class Arsch : public QWidget
{
    Q_OBJECT

public:
    explicit Arsch(QWidget *parent = 0);

    int hour;
    int minute;

    QList<WeekDayButton*> *dayButtons;

    bool isButtonActive(int day);

    ~Arsch();

 signals:
    void GoBack();

private slots:
    void on_pushButton_clicked();

    void on_hourDown_clicked();
    void on_hourUp_clicked();

    void on_minuteDown_clicked();
    void on_minuteUp_clicked();

    void on_day_clicked(bool);

    void Blink();
private:
    void UpdateTime();

    Ui::Arsch *ui;


};

#endif // ARSCH_H
