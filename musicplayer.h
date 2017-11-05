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

    ~MusicPlayer();

signals:
   void GoBack();

public slots:
   void on_okButton_clicked();
   void on_chillOutButton_clicked();
   void on_HDMButton_clicked();
   void on_lightButton_clicked();

   void VolumeUp();
   void VolumeDown();
   void Mute();

   void StartProcess(QString command, QString argsString);

private:
    Ui::MusicPlayer *ui;

    int curentVolume;
};

#endif // MUSICPLAYER_H
