#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QDebug>
#include <QProcess>

#include <WiringPi/wiringPi/wiringPi.h>
#include <volumeknobthread.h>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    qDebug() << "MusicPlayer";

#ifndef Q_OS_MACOS
    wiringPiSetup();
    pinMode (24, INPUT) ; //knopf
    pinMode (23, INPUT) ; //links/rechts
    pinMode (22, INPUT) ; //links/rechts
    pinMode (25, OUTPUT) ;
#endif

    VolumeKnobThread *volThread = new VolumeKnobThread();
    volThread->start();

    connect(volThread, SIGNAL(up()), this, SLOT(VolumeUp()));
    connect(volThread, SIGNAL(down()), this, SLOT(VolumeDown()));
    connect(volThread, SIGNAL(pressed()), this, SLOT(Mute()));
}

void MusicPlayer::VolumeUp()
{
    qDebug() << "vol +";
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "sset" << "'Speaker'" << "1%+";
    process->start("amixer", args);
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
}

void MusicPlayer::VolumeDown()
{
    qDebug() << "vol -";
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "sset" << "'Speaker'" << "1%-";
    process->start("amixer", args);
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
}

void MusicPlayer::Mute()
{
    /*
    qDebug() << "mute toggle";
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "toggle";
    process->start("mpc", args);
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
*/

    StartProcess("mpc", "toggle");
}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::on_okButton_clicked()
{
    emit this->GoBack();
}

void MusicPlayer::on_chillOutButton_clicked()
{
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "clear";
    process->start("mpc", args);
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));


    QProcess *processLoad = new QProcess(this);
    args.clear();
    args << "load" << "ChillOut++";
    processLoad->start("mpc", args);
    connect(processLoad, SIGNAL(finished(int)), processLoad, SLOT(deleteLater()));
}

void MusicPlayer::on_HDMButton_clicked()
{
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "clear";
    process->start("mpc", args);

    QProcess *processLoad = new QProcess(this);
    args.clear();
    args << "load" << "HDM";
    processLoad->start("mpc", args);
}

void MusicPlayer::on_lightButton_clicked()
{
    QProcess *process = new QProcess(this);
    process->start("/home/pi/Desktop/pressBrightness.sh");
}

void MusicPlayer::StartProcess(QString command, QString argsString)
{
    QStringList args = argsString.split(' ');
    QProcess *process = new QProcess(this);
    process->start(command, args);
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
}


