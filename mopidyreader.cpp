#include "mopidyreader.h"
#include <QDebug>

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QJsonDocument>

MopidyReader::MopidyReader(QObject *parent) : QObject(parent)
{
    title = "-";
    artist = "-";
    state = "*";
    length = -1;

    titleManager = new QNetworkAccessManager(this);
    stateManager = new QNetworkAccessManager(this);
    positionManager = new QNetworkAccessManager(this);

    connect(titleManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadMopidyTitle(QNetworkReply*)));
    connect(stateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadMopidyState(QNetworkReply*)));
    connect(stateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadMopidyState(QNetworkReply*)));
}

void MopidyReader::Update()
{
    titleManager->post(this->getRequest(), getCurrentTrack() );
    stateManager->post(this->getRequest(), getState() );
    positionManager->post(this->getRequest(), getCurrentPos() );
}

QByteArray MopidyReader::getCurrentTrack()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = 1;
    json["method"] = "core.playback.get_current_track";
    QJsonDocument doc(json);

    return doc.toJson();
}

QByteArray MopidyReader::getCurrentPos()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = 1;
    json["method"] = "core.playback.get_time_position";
    QJsonDocument doc(json);

    return doc.toJson();
}

QByteArray MopidyReader::getState()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = 1;
    json["method"] = "core.playback.get_state";
    QJsonDocument doc(json);

    return doc.toJson();
}

QNetworkRequest MopidyReader::getRequest()
{
    QString host = "http://localhost:6680/mopidy/rpc";
    QNetworkRequest request;
    request.setUrl(QUrl(host));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    return request;
}

void MopidyReader::ReadMopidyTitle(QNetworkReply* reply)
{
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "Failed to parse json: " << jsonError.errorString();
    }

    qDebug() << json.toJson();

    title = json.object()["result"].toObject()["name"].toString();
    length = json.object()["result"].toObject()["length"].toInt();
    artist = json.object()["result"].toObject()["artists"].toArray()[0].toObject()["name"].toString();
}

void MopidyReader::ReadMopidyPosition(QNetworkReply* reply)
{
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "Failed to parse json: " << jsonError.errorString();
    }

    qDebug() << json.toJson();

    position = json.object()["result"].toInt();
}

void MopidyReader::ReadMopidyState(QNetworkReply* reply)
{
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "Failed to parse json: " << jsonError.errorString();
    }

    //qDebug() << json.toJson();

    this->state = json.object()["result"].toString();

    if(this->state == "playing")
    {
        this->state = "▶";
    }

    if(this->state == "paused")
    {
        this->state = "||";
    }
}
