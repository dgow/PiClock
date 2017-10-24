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


   // for (;;)
   // {
        /*
      digitalWrite (25, HIGH) ;	// On
      delay (500) ;		// mS
      digitalWrite (25, LOW) ;	// Off
      delay (500) ;

      int button = digitalRead(24);
      qDebug() << "Button " << button;
      */

        /*
        int button = digitalRead(23);
        if( button == 0)
        {
            qDebug() << "= " << button;
        }

        int button2 = digitalRead(23);
        if( button2 == 0)
        {
            qDebug() << "/ " << button2;
        }
        */

        //delay (10) ;
    //}

    connect(volThread, SIGNAL(up()), this, SLOT(VolumeUp()));
    connect(volThread, SIGNAL(down()), this, SLOT(VolumeDown()));
    connect(volThread, SIGNAL(pressed()), this, SLOT(Mute()));
}

void MusicPlayer::VolumeUp()
{
    qDebug() << "vol up";
}

void MusicPlayer::VolumeDown()
{
    qDebug() << "vol down";
}

void MusicPlayer::Mute()
{
    qDebug() << "mute toggle";
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

    QProcess *processLoad = new QProcess(this);
    args.clear();
    args << "load" << "ChillOut++";
    processLoad->start("mpc", args);
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
