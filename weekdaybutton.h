#ifndef WEEKDAYBUTTON_H
#define WEEKDAYBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QSplitter>

class WeekDayButton : public QPushButton
{
    Q_OBJECT

public:
    WeekDayButton(QWidget *parent = 0);

    void SetActive(bool active);
    void LoadState();
    void Expire();

    int dayOfTheWeek;

    bool active;
    bool expired;

};

#endif // WEEKDAYBUTTON_H
