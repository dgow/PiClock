#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>

namespace Ui {
class MusicPlayer;
}

class MusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = 0);
    ~MusicPlayer();

private:
    Ui::MusicPlayer *ui;
};

#endif // MUSICPLAYER_H
