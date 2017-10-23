#include "arsch.h"
#include "ui_arsch.h"

#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QPushButton>
#include <QDateTime>
#include <weekdaybutton.h>
#include <QTime>
#include <QTimer>

#include <wiringPi.h>

Arsch::Arsch(QWidget *parent) : QWidget(parent),
    ui(new Ui::Arsch)
{   
    minuteStep = 5;

    QSettings settings("Arsch", "Fotze");
    hour = settings.value("hour").toInt();
    minute = settings.value("minute").toInt();

    ui->setupUi(this);
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);

    dayButtons = new QList<WeekDayButton*>();

    UpdateTime();

    QTimer *blickTimer = new QTimer(this);
    blickTimer->setInterval(1000);
    connect(blickTimer, SIGNAL(timeout()), this, SLOT(Blink()));
    blickTimer->start();
}

Arsch::~Arsch()
{
    delete ui;
}

void Arsch::Blink()
{
    QDateTime time = QDateTime::currentDateTime();
    QTime qTime = time.time();

    QString timeString = QString::number(this->hour).rightJustified(2,'0') + ":" + QString::number(this->minute).rightJustified(2,'0');

    if( qTime.second() % 2 == 0 )
    {
        timeString = "> " + timeString + " <";
    }

    ui->timeLabel->setText(timeString);
}

void Arsch::UpdateTime()
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

    ui->timeLabel->setText(QString::number(this->hour).rightJustified(2,'0') + ":" + QString::number(this->minute).rightJustified(2,'0'));

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
        connect(button, SIGNAL(toggled(bool)), this, SLOT(on_day_clicked(bool)));
    }
}

void Arsch::on_pushButton_clicked()
{
    QSettings settings("Arsch", "Fotze");
    settings.setValue("hour", QVariant(hour));
    settings.setValue("minute", QVariant(minute));

    emit this->GoBack();
}

void Arsch::on_hourDown_clicked()
{
    this->hour--;
    this->UpdateTime();

}

void Arsch::on_hourUp_clicked()
{
    this->hour++;
    this->UpdateTime();

}

void Arsch::on_minuteDown_clicked()
{
    this->minute -= this->minuteStep;
    this->UpdateTime();
}

void Arsch::on_minuteUp_clicked()
{
    this->minute += this->minuteStep;
    this->UpdateTime();
}

void Arsch::on_day_clicked(bool checked)
{
    QDateTime time = QDateTime::currentDateTime();
    QDate date = time.date();

    WeekDayButton *button = (WeekDayButton*)QObject::sender();
    button->SetActive(checked);

    qDebug() << "BUTTON: " << button->dayOfTheWeek << " " << date.dayOfWeek() << "CHECKED: " << checked;
}

bool Arsch::isButtonActive(int day)
{
    WeekDayButton *button = dayButtons->at(day - 1);
    return button->active;
}
