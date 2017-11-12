#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QDebug>
#include <QProcess>

#include <WiringPi/wiringPi/wiringPi.h>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    curentVolume = 10;

    //StartProcess("amixer", QString("sset 'Speaker' '1%'"));
    StartProcess("amixer", QString("sset 'Speaker' \%1%").arg(curentVolume));

#ifndef Q_OS_MACOS
    wiringPiSetup();
    pinMode (24, INPUT) ; //knopf
    pinMode (23, INPUT) ; //links/rechts
    pinMode (22, INPUT) ; //links/rechts
    pinMode (25, OUTPUT) ;
#endif

    StartProcess("mpc", "random on");
}

void MusicPlayer::SetupVolumeKnob()
{
    volThread = new VolumeKnobThread();
    volThread->start();

    connect(volThread, SIGNAL(up()), this, SLOT(VolumeUp()));
    connect(volThread, SIGNAL(down()), this, SLOT(VolumeDown()));
    connect(volThread, SIGNAL(pressed()), this, SLOT(Mute()));
}

void MusicPlayer::VolumeUp()
{   
    curentVolume += 2;
    StartProcess("amixer", QString("sset 'Speaker' \%1%").arg(curentVolume));
    if(curentVolume >100)
    {
        curentVolume = 100;
    }
}

void MusicPlayer::VolumeDown()
{
    curentVolume -= 2;
    StartProcess("amixer", QString("sset 'Speaker' \%1%").arg(curentVolume));
    if(curentVolume < 0 )
    {
        curentVolume = 0;
    }
}

void MusicPlayer::Mute()
{
    StartProcess("mpc", "toggle");
    emit StateChanged();
}

void MusicPlayer::Stop()
{
    StartProcess("mpc", "stop");
    emit StateChanged();
}

void MusicPlayer::NextSong()
{
    StartProcess("mpc", "next");
    emit SongChanged();
}

void MusicPlayer::PrevSong()
{
    StartProcess("mpc", "prev");
    emit SongChanged();
}

void MusicPlayer::on_okButton_clicked()
{
    emit this->GoBack();
}

void MusicPlayer::on_chillOutButton_clicked()
{
    StartProcess("mpc", "clear");
    StartProcess("mpc", "load ChillOut++");
}

void MusicPlayer::on_HDMButton_clicked()
{   
    StartProcess("mpc", "clear");
    StartProcess("mpc", "load HDM");
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

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::on_gongButton_clicked()
{
    StartProcess("mpc", "clear");
    StartProcess("mpc", "load Gong");
}
