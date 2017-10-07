#include "arsch.h"
#include "ui_arsch.h"

#include <QDebug>

Arsch::Arsch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arsch)
{
    ui->setupUi(this);
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);
}

Arsch::~Arsch()
{
    delete ui;
}

void Arsch::on_pushButton_clicked()
{
    qDebug() << "fotze fotze";
    emit this->GoBack();

}

