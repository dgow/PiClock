#ifndef MOPIDYREADER_H
#define MOPIDYREADER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>


class MopidyReader : public QObject
{
    Q_OBJECT
public:
    explicit MopidyReader(QObject *parent);



    QString title;
    QString artist;
    QString state;
    int length;
    int position;
    int songProgress;

    int currentUpdate;

signals:
    void DataChanged();

public slots:
    void ReadMopidyTitle(QNetworkReply* reply);
    void ReadMopidyState(QNetworkReply* reply);
    void ReadMopidyPosition(QNetworkReply* reply);

    void Update();

    void UpdateSong();
    void UpdateState();
    void UpdatePosition();


private:
    QNetworkAccessManager *titleManager;
    QNetworkAccessManager *stateManager;
    QNetworkAccessManager *positionManager;

    QNetworkRequest getRequest();
    QByteArray getCurrentTrack();
    QByteArray getState();
    QByteArray getCurrentPos();

};

#endif // MOPIDYREADER_H
