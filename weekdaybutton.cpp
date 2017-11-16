#include "weekdaybutton.h"

#include <QDebug>
#include <QSettings>

WeekDayButton::WeekDayButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("background-color: rgb(255, 255, 255);\ncolor: rgb(255, 255, 255);");

    this->setStyleSheet("WeekDayButton:hover{background-color: pink;}");

    this->setStyleSheet("WeekDayButton:checked { background-color: green; color: rgb(0, 255, 0); }"
                        "WeekDayButton{background-color: white; color: rgb(255, 255, 255);}"
                        );
    expired = false;
}

void WeekDayButton::LoadState()
{
    QString st = QString ("activeDay%1").arg(this->dayOfTheWeek);
    QString expSt = QString ("expired%1").arg(this->dayOfTheWeek);
    QSettings settings("Joe", "PiClock");

    this->active = settings.value(st).toBool();
    //this->expired = settings.value(expSt).toBool();

    this->setCheckable(true);
    this->setChecked(this->active);
}

void WeekDayButton::Expire()
{
    expired = true;
    QSettings settings("Joe", "PiClock");
    QString st = QString ("expired%1").arg(this->dayOfTheWeek);
    settings.setValue(st, expired);
}

void WeekDayButton::SetActive(bool active)
{
    this->active = active;

    QSettings settings("Joe", "PiClock");
    QString st = QString ("activeDay%1").arg(this->dayOfTheWeek);
    settings.setValue(st, this->active);
}
