#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QDebug>
#include <QProcess>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    qDebug() << "MusicPlayer";

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
