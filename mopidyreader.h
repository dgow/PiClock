#ifndef MOPIDYREADER_H
#define MOPIDYREADER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QtWebSockets/QWebSocket>
#include <QMetaEnum>

enum MessageId {
        Play = 666,
        Next = 777
};

class MopidyReader : public QObject
{
    Q_OBJECT
    Q_ENUM(MessageId)

public:
    explicit MopidyReader(QObject *parent);



    //

    QString title;
    QString artist;
    QString state;
    int length;
    int position;
    int songProgress;

    int currentUpdate;

    void Test();
    void onConnected();
    void onTextMessageReceived(QString message);
signals:
    void DataChanged();

public slots:

    void Update();

    void UpdateSong();
    void UpdateState();
    void UpdatePosition();


private:

    QNetworkRequest getRequest();
    QByteArray getCurrentTrack();
    QByteArray getState();
    QByteArray getCurrentPos();

    QWebSocket m_webSocket;

};

#endif // MOPIDYREADER_H
