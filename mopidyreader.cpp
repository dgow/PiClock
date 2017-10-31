#include "mopidyreader.h"
#include <QDebug>

MopidyReader::MopidyReader(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadMopidy(QNetworkReply*)));
}

void MopidyReader::Update()
{
    QString weatherLink = '{"jsonrpc": "2.0", "id": 1, "method": "core.playback.get_current_track"}';
    QUrl url(weatherLink);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void MopidyReader::ReadMopidy(QNetworkReply* reply)
{
    qDebug() << reply;
}
