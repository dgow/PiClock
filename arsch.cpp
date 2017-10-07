#include "arsch.h"
#include "ui_arsch.h"

#include <QDebug>

Arsch::Arsch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arsch)
{
    ui->setupUi(this);

    qDebug() << "fotze fotze" << parent;

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

