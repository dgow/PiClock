#include "arsch.h"
#include "ui_arsch.h"

#include <QDebug>

Arsch::Arsch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arsch)
{
    hour = 0;
    minute = 0;

    ui->setupUi(this);
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);
}

Arsch::~Arsch()
{
    delete ui;
}

void Arsch::UpdateTime()
{
    if(hour > 24)
    {
        hour = 0;
    }

    if(hour < 0 )
    {
        hour = 23;
    }

    if(minute > 59)
    {
        minute = 0;
    }

    if(minute < 0 )
    {
        minute = 59;
    }


    ui->timeLabel->setText(QString::number(this->hour) + " : " + QString::number(this->minute));
}

void Arsch::on_pushButton_clicked()
{
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
