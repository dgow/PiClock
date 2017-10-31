#include "mopidyreader.h"
#include <QDebug>

#include <QJsonObject>
#include <QString>
#include <QJsonDocument>

MopidyReader::MopidyReader(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadMopidy(QNetworkReply*)));
}

void MopidyReader::Update()
{
    QJsonObject json;
/*    json->insert("jsonrpc", "2.0");
    json->insert("id", 1);
    json->insert("method", "core.playback.get_current_track");
    */
    json["jsonrpc"] = "2.0";
    json["id"] = 1;
    json["method"] = "core.playback.get_current_track";

    QJsonDocument doc(json);

    QString host = "http://localhost:6680/mopidy/rpc";
    QNetworkRequest request;
    request.setUrl(QUrl(host));
    //"application/x-www-form-urlencoded";


    manager->post(request, doc.toJson());



    /*QString weatherLink = '{"jsonrpc": "2.0", "id": 1, "method": "core.playback.get_current_track"}';
    QUrl url(weatherLink);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
    */
}

void MopidyReader::ReadMopidy(QNetworkReply* reply)
{


    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "Failed to parse json: " << jsonError.errorString();
    }

    qDebug() << json.toJson();
    qDebug() << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

    QString title = json.object()["result"].toObject()["name"].toString();

    qDebug() << title;


}
