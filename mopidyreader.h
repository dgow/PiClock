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

    void Update();

    QString title;
    QString artist;
    QString state;
    int length;

signals:

public slots:
    void ReadMopidyTitle(QNetworkReply* reply);
    void ReadMopidyState(QNetworkReply* reply);

private:
    QNetworkAccessManager *titleManager;
    QNetworkAccessManager *stateManager;

    QNetworkRequest getRequest();
    QByteArray getCurrentTrack();
    QByteArray getState();

};

#endif // MOPIDYREADER_H
