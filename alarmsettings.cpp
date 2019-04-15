#include "alarmsettings.h"
#include "ui_alarmsettings.h"

#include <QDebug>
#include <QVariant>
#include <QPushButton>
#include <QDateTime>
#include <weekdaybutton.h>
#include <QTime>
#include <QTimer>

const QString hourString = "hour";
const QString minuteString = "minute";

AlarmSettings::AlarmSettings(QWidget *parent) : QWidget(parent),
    ui(new Ui::AlarmSettings)
{   
    minuteStep = 1;

    settings = new QSettings("Joe", "PiClock");


    hour = settings->value(hourString).toInt();
    minute = settings->value(minuteString).toInt();

    ui->setupUi(this);
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);

    dayButtons = new QList<WeekDayButton*>();
    dayButtons->append(ui->mo_button);
    dayButtons->append(ui->di_button);
    dayButtons->append(ui->mi_button);
    dayButtons->append(ui->do_button);
    dayButtons->append(ui->fr_button);
    dayButtons->append(ui->sa_button);
    dayButtons->append(ui->so_button);

    for( int i = 1; i <= 7; i++ )
    {
        WeekDayButton *button = dayButtons->at(i-1);
        button->dayOfTheWeek = i;
        button->LoadState();
        connect(button, SIGNAL(toggled(bool)), this, SLOT(day_clicked(bool)));
    }

    UpdateTime();

    QTimer *blickTimer = new QTimer(this);
    blickTimer->setInterval(1000);
    connect(blickTimer, SIGNAL(timeout()), this, SLOT(Blink()));
    blickTimer->start();
}

void AlarmSettings::Blink()
{
    QDateTime time = QDateTime::currentDateTime();
    QTime qTime = time.time();

    QString timeString = QString::number(this->hour).rightJustified(2,'0') + ":" + QString::number(this->minute).rightJustified(2,'0');
    timeString = this->FormatTime(hour, minute);

    if( qTime.second() % 2 == 0 )
    {
        timeString = "> " + timeString + " <";
    }

    ui->timeLabel->setText(timeString);
}

void AlarmSettings::UpdateTime()
{
    if(minute > (60 - minuteStep))
    {
        minute = 0;
        hour++;
    }

    if(minute < 0 )
    {
        minute = (60 - minuteStep);
        hour--;
    }

    if(hour > 23)
    {
        hour = 0;
    }

    if(hour < 0 )
    {
        hour = 23;
    }

    ui->timeLabel->setText(this->FormatTime(hour, minute));
}

QString AlarmSettings::FormatTime(int hour, int minute)
{
    QString s = QString::number(hour).rightJustified(2,'0') + ":" + QString::number(minute).rightJustified(2,'0');
    return s;
}

void AlarmSettings::on_pushButton_clicked()
{
    settings->setValue(hourString, QVariant(hour));
    settings->setValue(minuteString, QVariant(minute));

    emit this->GoBack();
}

void AlarmSettings::on_hourDown_clicked()
{
    this->hour--;
    this->UpdateTime();
}

void AlarmSettings::on_hourUp_clicked()
{
    this->hour++;
    this->UpdateTime();
}

void AlarmSettings::on_minuteDown_clicked()
{
    this->minute -= this->minuteStep;
    this->UpdateTime();
}

void AlarmSettings::on_minuteUp_clicked()
{
    this->minute += this->minuteStep;
    this->UpdateTime();
}

void AlarmSettings::day_clicked(bool checked)
{
    WeekDayButton *button = (WeekDayButton*)QObject::sender();
    button->SetActive(checked);
}

bool AlarmSettings::isButtonActive(int day)
{
    WeekDayButton *button = dayButtons->at(day - 1);
    return button->active;
}

AlarmSettings::~AlarmSettings()
{
    delete ui;
}
