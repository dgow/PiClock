#include "mopidyreader.h"
#include <QDebug>

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QJsonDocument>
#include <QHostInfo>

MopidyReader::MopidyReader(QObject *parent) : QObject(parent)
{
    currentUpdate = 0;

    title = "-";
    artist = "-";
    state = "XXX";
    length = -1;
    songProgress = 0;

    connect(&m_webSocket, &QWebSocket::connected, this, &MopidyReader::onConnected);
    connect(&m_webSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)) );
    connect(&m_webSocket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));

    connectTimer = new QTimer(this);
    connect(connectTimer, SIGNAL(timeout()), this, SLOT(Connect()));
   // connectTimer->start(1000);

    QTimer::singleShot(1000,this, SLOT(Connect()));
}

void MopidyReader::Connect()
{
    qDebug() << "connecting to modipy ...";
    this->state = "connecting";
    emit DataChanged();

    QString url = "ws://raspiclock:6680/mopidy/ws";
    m_webSocket.open(QUrl(url));
}

void MopidyReader::onConnected()
{
    qDebug() << "Connected";
    state = "connected";

    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MopidyReader::onTextMessageReceived);
    connectTimer->stop();
}

void MopidyReader::onTextMessageReceived(QString message)
{
//    qDebug() << "Message received:" << message;

    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(message.toUtf8(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "ARSCH: " << jsonError.errorString();
    }

    //qDebug() << json.toJson(QJsonDocument::Indented);

    MessageId id = (MessageId)json.object()["id"].toInt();

    if(json.object()["event"].isNull())
    {
        if(id == Play)
        {
            qDebug() << "YEAH you hit play";
        }
        else if(id == Position)
        {
            this->position = json.object()["result"].toInt();
            this->songProgress = (((float)this->position) / (float)this->length) * 100 + 1;
        }
        else
        {
            qDebug() << "Unknown messageId " << id;
        }
    }
    else
    {

     //   qDebug() << "Message received:" << message;

        QString event = json.object()["event"].toString();

        if( event == "playback_state_changed")
        {
            this->state = json.object()["new_state"].toString();

            if(this->state == "playing")
            {
                this->state = "▶";
            }

            if(this->state == "paused")
            {
                this->state = "||";
            }
        }
        else if(event == "track_playback_started")
        {
            this->title = json.object()["tl_track"].toObject()["track"].toObject()["name"].toString();
            this->artist = json.object()["tl_track"].toObject()["track"].toObject()["artists"].toArray()[0].toObject()["name"].toString();
            this->length = json.object()["tl_track"].toObject()["track"].toObject()["length"].toInt();
        }
        else if(event == "stream_title_changed")
        {
            this->artist = json.object()["title"].toString();
            this->state = "▶";
        }
    }

    emit DataChanged();
}

void MopidyReader::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "ERROR - trying to reconnect";
    qDebug() << error;

    QTimer::singleShot(2000,this, SLOT(Connect()));
}

void MopidyReader::PlaySong()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = Next;
    json["method"] = "core.playback.play";
    QJsonDocument doc(json);
    QString jstring = doc.toJson();
    m_webSocket.sendTextMessage(jstring);
}

void MopidyReader::Clear()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = Clear;
    json["method"] = "core.tracklist.clear";
    QJsonDocument doc(json);
    QString jstring = doc.toJson();
    m_webSocket.sendTextMessage(jstring);
}

void MopidyReader::NextSong()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = Next;
    json["method"] = "core.playback.next";
    QJsonDocument doc(json);
    QString jstring = doc.toJson();
    m_webSocket.sendTextMessage(jstring);
}

void MopidyReader::PrevSong()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = Next;
    json["method"] = "core.playback.previous";
    QJsonDocument doc(json);
    QString jstring = doc.toJson();

    m_webSocket.sendTextMessage(jstring);
}

void MopidyReader::UpdateSong()
{
    //titleManager->post(this->getRequest(), getCurrentTrack() );
}

void MopidyReader::UpdateState()
{
    //stateManager->post(this->getRequest(), getState() );
}

void MopidyReader::UpdatePosition()
{
    //positionManager->post(this->getRequest(), getCurrentPos() );
    m_webSocket.sendTextMessage(this->getCurrentPos());

}

void MopidyReader::onDisconnect()
{
    qDebug() << "DISCONNECTED";
    this->state = "disconnected";
    emit DataChanged();
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

QString MopidyReader::getCurrentPos()
{
    QJsonObject json;
    json["jsonrpc"] = "2.0";
    json["id"] = Position;
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
