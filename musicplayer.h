#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <volumeknobthread.h>

namespace Ui {
class MusicPlayer;
}

class MusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = 0);

    VolumeKnobThread *volThread;
    void SetupVolumeKnob();
    int curentVolume;

    ~MusicPlayer();

    void SetVolume(int volume);
signals:
   void GoBack();

   void SongChanged();
   void StateChanged();

public slots:
   void on_okButton_clicked();
   void on_chillOutButton_clicked();
   void on_HDMButton_clicked();
   void on_lightButton_clicked();

   void VolumeUp();
   void VolumeDown();
   void Mute();

   void Stop();

   void NextSong();
   void PrevSong();

   void StartProcess(QString command, QString argsString, bool wait = false);

private slots:
   void on_gongButton_clicked();


   void on_mixTapeButton_clicked();

private:
    Ui::MusicPlayer *ui;


};

#endif // MUSICPLAYER_H
