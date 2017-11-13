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

    //this->Connect();

    connect(&m_webSocket, &QWebSocket::connected, this, &MopidyReader::onConnected);

    connectTimer = new QTimer(this);
    connect(connectTimer, SIGNAL(timeout()), this, SLOT(Connect()));
    connectTimer->start(1000);
}

void MopidyReader::Connect()
{
    qDebug() << "connecting to modipy ...";


    QString url = "ws://raspiclock:6680/mopidy/ws";

  /*  if( QHostInfo::localHostName() == "raspiclock")
    {
        url = "ws://localhost:6680/mopidy/ws";
    }
    else
    {

    }
    */
    m_webSocket.open(QUrl(url));
}

void MopidyReader::onConnected()
{
    qDebug() << "Connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MopidyReader::onTextMessageReceived);
    //m_webSocket.sendTextMessage(QString("{\"jsonrpc\": \"2.0\", \"id\": %1, \"method\": \"core.playback.get_time_position\"}").arg(Play));

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
            this->songProgress = (((float)this->position) / (float)this->length) * 100;
        }
        else
        {
            qDebug() << "Unknown messageId " << id;
        }
    }
    else
    {
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
    }

    emit DataChanged();
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
