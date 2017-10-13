#include "musicplayer.h"
#include "ui_musicplayer.h"

MusicPlayer::MusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}
