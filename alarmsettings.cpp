#include "alarmsettings.h"


#include <QDebug>

AlarmSettings::AlarmSettings(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Constructor AlarmSettings" << parent;


}

void AlarmSettings::goBack()
{

}

void AlarmSettings::on_backButton_clicked()
{
 qDebug() << "YES du arsch";
}
