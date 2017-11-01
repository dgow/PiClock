#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QHostInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << QHostInfo::localHostName();

    if( QHostInfo::localHostName() == "raspiclock")
    {
        w.setWindowState(Qt::WindowFullScreen);
    }
    w.show();

    return a.exec();
}
