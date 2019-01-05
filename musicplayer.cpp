#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QDebug>
#include <QProcess>
#include <QTimer>

#include <WiringPi/wiringPi/wiringPi.h>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    curentVolume = 25;
    this->SetVolume(curentVolume);

#ifndef Q_OS_MACOS
    wiringPiSetup();
    pinMode (24, INPUT) ; //knopf
    pinMode (23, INPUT) ; //links/rechts
    pinMode (22, INPUT) ; //links/rechts
    pinMode (25, OUTPUT) ;
#endif

}

void MusicPlayer::SetupVolumeKnob()
{
    volThread = new VolumeKnobThread();
    volThread->start();

    connect(volThread, SIGNAL(up()), this, SLOT(VolumeUp()));
    connect(volThread, SIGNAL(down()), this, SLOT(VolumeDown()));
    connect(volThread, SIGNAL(pressed()), this, SLOT(Mute()));
}

void MusicPlayer::SetVolume(int volume)
{
    curentVolume = volume;
    StartProcess("amixer", QString("sset 'Speaker' \%1%").arg(curentVolume));

    emit VolumeChanged();
}

void MusicPlayer::VolumeUp()
{   
    curentVolume += 2;

    if(curentVolume >100)
    {
        curentVolume = 100;
    }
    SetVolume(curentVolume);
}

void MusicPlayer::VolumeDown()
{
    curentVolume -= 2;
    if(curentVolume < 0 )
    {
        curentVolume = 0;
    }
    SetVolume(curentVolume);
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
    StartProcess("mpc", "load ChillOut++\ \(by\ 1126702738\)");
    emit this->GoBack();
}

void MusicPlayer::on_HDMButton_clicked()
{   
    StartProcess("mpc", "clear");
    StartProcess("mpc", "load HDM\ \(by\ 1126702738\)");
    emit this->GoBack();
}

void MusicPlayer::on_lightButton_clicked()
{
    QProcess *process = new QProcess(this);
    process->start("/home/pi/Desktop/pressBrightness.sh");
}

void MusicPlayer::StartProcess(QString command, QString argsString, bool wait)
{
    QStringList args = argsString.split(' ');
    QProcess *process = new QProcess(this);

    if(wait)
    {
        process->waitForFinished(1000);
    }

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
    emit this->GoBack();
}


void MusicPlayer::on_mixTapeButton_clicked()
{
    StartProcess("mpc", "clear");
    StartProcess("mpc", "load MixTape");
    emit this->GoBack();
}
