#ifndef MOPIDYREADER_H
#define MOPIDYREADER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QtWebSockets/QWebSocket>
#include <QMetaEnum>
#include <QTimer>

class MopidyReader : public QObject
{
    Q_OBJECT

public:
    explicit MopidyReader(QObject *parent);

    enum MessageId {
            Play = 1,
            Next = 2,
            Prev = 3,
            Position = 4,
            ClearPlaylist = 5,
            Random = 6

    };
    Q_ENUMS(MessageId)

    QString title;
    QString artist;
    QString state;
    int length;
    int position;
    int songProgress;

    int currentUpdate;


    void onConnected();
    void onTextMessageReceived(QString message);

    void NextSong();
    void PrevSong();

    QTimer *connectTimer;

    void PlaySong();
    void Clear();
    QByteArray setRandom();
signals:
    void DataChanged();

public slots:
    void UpdateSong();
    void UpdateState();
    void UpdatePosition();

    void onDisconnect();
    void Connect();
    void onError(QAbstractSocket::SocketError error);

    void openUrl();
private:

    QNetworkRequest getRequest();
    QByteArray getCurrentTrack();
    QByteArray getState();
    QString getCurrentPos();

    QWebSocket m_webSocket;

};

#endif // MOPIDYREADER_H
