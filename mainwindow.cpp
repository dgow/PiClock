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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    qDebug() << "Constructor Main";

    currentLight = 80;
    sunRise = -1;

    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("background-image: url(:/images/kurt_face.jpg);");
 //ui->centralWidget->setStyleSheet("background-color: #000000");
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->weatherLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->dateLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->weatherIcon->setAttribute(Qt::WA_TranslucentBackground);



    SetShadow(ui->timeLabel);
    SetShadow(ui->weatherLabel);
    SetShadow(ui->dateLabel);
    SetShadow(ui->weatherIcon);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer->start(10000);

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
}

void MainWindow::GetWeather()
{
    qDebug() << "download weather";

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
    qDebug() << "Temperature: " << " " << temp;

    ui->weatherLabel->setText(temp + "°");

    QJsonObject weather = root_object["weather"].toArray().at(0).toObject();
    QString icon = weather["icon"].toString();
    qDebug() << "Weather icon: " << " " << icon;

    ui->weatherIcon->setPixmap(":/weather/weatherIcons/" + icon + ".png");

    QJsonObject jsonSys = root_object["sys"].toObject();
    QJsonObject jsonSunRise = jsonSys["sunrise"].toObject();

    sunRise = jsonSys["sunrise"].toInt();
    sunSet = jsonSys["sunset"].toInt();

    QDateTime time = QDateTime::currentDateTime();
    int64_t currentTime = time.currentMSecsSinceEpoch();
    qDebug() << "RISE:    " << sunRise;
    qDebug() << "SET:     " << sunSet;
    qDebug() << "CURRENT: " << currentTime << "TAG? " << (currentTime/1000 > sunRise);

    if(currentLight != TargetBrightness())
    {
        lightButtonTimer->start(1000);
    }
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
            QProcess *process = new QProcess(this);
            QStringList args;
            args << "sset" << "'Speaker'" << "5%+";
            process->start("amixer", args);
        } else {
            QProcess *process = new QProcess(this);
            QStringList args;
            args << "sset" << "'Speaker'" << "5%-";
            process->start("amixer", args);
        }
    }
    else if(event->y() < 240)
    {
        QProcess *process = new QProcess(this);
        QStringList args;
        args << "toggle";
        process->start("mpc", args);
    }
    else
    {
        if(event->x() < 240)
        {
            QProcess *process = new QProcess(this);
            QStringList args;
            args << "prev";
            process->start("mpc", args);
        } else {
            QProcess *process = new QProcess(this);
            QStringList args;
            args << "next";
            process->start("mpc", args);
        }
    }

    qDebug() << "YEAH " << event->x();

    ui->stackedWidget->setCurrentIndex(1);
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
    qDebug() << "YEAH ";
    ui->stackedWidget->setCurrentIndex(0);
}

/*
void MainWindow::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
*/
