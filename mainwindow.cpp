#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <arsch.h>

#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QColor>
#include <QMouseEvent>
#include <qglobal.h>
#include <QProcess>
#include <QGraphicsDropShadowEffect>

/*
 * curl -d '{"jsonrpc": "2.0", "id": 1, "method": "core.get_version"}' http://localhost:6680/mopidy/rpc
 *
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mopidyReader = new MopidyReader(this);
    mopidyReader->Update();

    currentLight = 80;
    sunRise = -1;
    lastMinute = -1;

    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("background-image: url(:/images/kurt_face.jpg);");
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->weatherLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->dateLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->weatherIcon->setAttribute(Qt::WA_TranslucentBackground);
    ui->songLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->line->setAttribute(Qt::WA_TranslucentBackground);
    ui->playStateLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->volumeLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->volumeIcon->setAttribute(Qt::WA_TranslucentBackground);


    SetShadow(ui->timeLabel);
    SetShadow(ui->weatherLabel);
    SetShadow(ui->dateLabel);
    SetShadow(ui->weatherIcon);
    SetShadow(ui->songLabel);
    SetShadow(ui->volumeLabel);
    SetShadow(ui->volumeIcon);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer->start(500);

    QTimer *weatherTimer = new QTimer(this);
    connect(weatherTimer, SIGNAL(timeout()), this, SLOT(GetWeather()));
    weatherTimer->start(60000);

    lightButtonTimer = new QTimer(this);
    connect(lightButtonTimer, SIGNAL(timeout()), this, SLOT(PressLightButton()));

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadWeather(QNetworkReply*)));

    UpdateTime();
    GetWeather();

    connect(ui->arschPage, SIGNAL(GoBack()), this, SLOT(GoBack()));
    connect(ui->musicPlayer, SIGNAL(GoBack()), this, SLOT(GoBack()));

    ui->stackedWidget->setCurrentIndex(0);

    ui->musicPlayer->SetupVolumeKnob();
    connect(ui->musicPlayer->volThread, SIGNAL(up()),   this, SLOT(UpdateVolume()));
    connect(ui->musicPlayer->volThread, SIGNAL(down()), this, SLOT(UpdateVolume()));

    connect(ui->musicPlayer, SIGNAL(SongChanged()), mopidyReader,   SLOT(UpdateSong()));
    connect(ui->musicPlayer, SIGNAL(StateChanged()), mopidyReader,  SLOT(UpdateState()));

    connect(mopidyReader, SIGNAL(DataChanged()), this,  SLOT(UpdateSong()));

    ui->volumeBar->setValue(mopidyReader->songProgress);
}

void MainWindow::UpdateVolume()
{
    QString volume = QString("%1").arg(ui->musicPlayer->curentVolume);
    ui->volumeLabel->setText(volume);
}

void MainWindow::SetShadow(QLabel *label)
{
    QGraphicsDropShadowEffect *sh = new QGraphicsDropShadowEffect();
    sh->setColor(QColor(0,0,0));
    sh->setBlurRadius(20);
    sh->setOffset(6,6);
    label->setGraphicsEffect(sh);
}

void MainWindow::UpdateTime()
{
    QDateTime time = QDateTime::currentDateTime();
    ui->timeLabel->setText(time.toString("hh:mm"));
    ui->dateLabel->setText(time.toString("dddd d. MMMM"));

    int hour = time.toString("h").toInt();
    int minute = time.toString("m").toInt();
    QDate date = time.date();
    int day = date.dayOfWeek();

    if( hour == ui->arschPage->hour && minute == ui->arschPage->minute && ui->arschPage->isButtonActive(day))
    {
        if(minute != lastMinute)
        {
            lastMinute = minute;
            qDebug() << "ARLARM";

            QProcess *processSpeaker = new QProcess(this);
            QStringList argsSpeaker;
            argsSpeaker << "sset" << "'Speaker'" << "40%";
            processSpeaker->start("amixer", argsSpeaker);

            QProcess *process = new QProcess(this);
            QStringList args;
            args << "play";
            process->start("mpc", args);

            ui->stackedWidget->setCurrentIndex(2);
        }
    }

    UpdateSong();
}

void MainWindow::UpdateSong()
{
    QString song = mopidyReader->artist + " - " + mopidyReader->title;
    ui->songLabel->setText(song);
    ui->playStateLabel->setText(mopidyReader->state);
    ui->volumeBar->setValue(mopidyReader->songProgress);
}

void MainWindow::GetWeather()
{
    QString weatherLink = "http://api.openweathermap.org/data/2.5/weather?q=Nuremberg,uk&appid=25879e4404560e805fb4878ea5d57ae2&units=metric&mode=json";
    QUrl url(weatherLink);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void MainWindow::ReadWeather(QNetworkReply* reply)
{
    if(reply->error())
    {
        qDebug() << "Failed to get weather: " << reply->errorString();
        return;
    }

    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "Failed to parse json: " << jsonError.errorString();
    }

    QJsonObject root_object = json.object();
    QJsonObject main = root_object["main"].toObject();
    QString temp = QString::number(qRound( main["temp"].toDouble()));
    //qDebug() << "Temperature: " << " " << temp;

    ui->weatherLabel->setText(temp + "°");

    QJsonObject weather = root_object["weather"].toArray().at(0).toObject();
    QString icon = weather["icon"].toString();
    //qDebug() << "Weather icon: " << " " << icon;

    ui->weatherIcon->setPixmap(":/weather/weatherIcons/" + icon + ".png");

    QJsonObject jsonSys = root_object["sys"].toObject();
    QJsonObject jsonSunRise = jsonSys["sunrise"].toObject();

    sunRise = jsonSys["sunrise"].toInt() + 60 * 60; //give me one more hour :)
    sunSet = jsonSys["sunset"].toInt();

    //QDateTime time = QDateTime::currentDateTime();
    //int64_t currentTime = time.currentMSecsSinceEpoch() / 1000;
    //qDebug() << "RISE:    " << sunRise;
    //qDebug() << "SET:     " << sunSet;

    //bool day = (currentTime > sunRise) && (currentTime < sunSet); //Day
    //qDebug() << "CURRENT: " << currentTime << "DAY? " << day;

    if(currentLight != TargetBrightness())
    {
        lightButtonTimer->start(1000);
    }

    reply->deleteLater();
}

void MainWindow::PressLightButton()
{
    QProcess *process = new QProcess(this);
    process->start("/home/pi/Desktop/pressBrightness.sh");

    currentLight += 10;
    if(currentLight > 100)
    {
        currentLight = 0;
    }

    if(currentLight == TargetBrightness())
    {
        lightButtonTimer->stop();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->y() < 150)
    {
        if(event->x() > 240)
        {
            ui->musicPlayer->VolumeUp();
        }
        else
        {
            ui->musicPlayer->VolumeDown();
        }
    }
    else if(event->y() < 240)
    {
        ui->musicPlayer->StartProcess("mpc", "toggle");
    }
    else
    {
        if(event->x() < 240)
        {
            ui->musicPlayer->PrevSong();
            mopidyReader->Update();
            UpdateSong();
        } else {
            ui->musicPlayer->NextSong();
            mopidyReader->Update();
            UpdateSong();
        }
    }
}

int MainWindow::TargetBrightness()
{
    QDateTime time = QDateTime::currentDateTime();
    int64_t currentTime = time.currentMSecsSinceEpoch() / 1000;

    int target = 0; //night
    if((currentTime > sunRise) && (currentTime < sunSet)) //Day
    {
        target = 100;
    }
    return target;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GoBack()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_alarmButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_stopAlarmButton_clicked()
{
    ui->musicPlayer->Stop();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_soundButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
