#include "arsch.h"
#include "ui_arsch.h"

#include <QDebug>
#include <QSettings>
#include <QVariant>

Arsch::Arsch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arsch)
{   
    QSettings settings("Arsch", "Fotze");
    hour = settings.value("hour").toInt();
    minute = settings.value("minute").toInt();

    ui->setupUi(this);
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);

    UpdateTime();
}

Arsch::~Arsch()
{
    delete ui;
}

void Arsch::UpdateTime()
{
    if(minute > 59)
    {
        minute = 0;
        hour++;
    }

    if(minute < 0 )
    {
        minute = 59;
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




    ui->timeLabel->setText(QString::number(this->hour) + ":" + QString::number(this->minute));
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
    this->minute--;
    this->UpdateTime();
}

void Arsch::on_minuteUp_clicked()
{
    this->minute++;
    this->UpdateTime();
}
