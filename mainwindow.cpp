#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QColor>


#include <qglobal.h>

#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    ui->centralWidget->setStyleSheet("background-image: url(:/images/image.png)");
    ui->centralWidget->setStyleSheet("background-image: url(:/images/kurt.jpg)");

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
    timer->start(60000);

    UpdateTime();
    GetWeather();
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
    //    qDebug() << "YEAH";

    QDateTime time = QDateTime::currentDateTime();
    ui->timeLabel->setText(time.toString("hh:mm"));

    ui->dateLabel->setText(time.toString("dddd d. MMMM"));
}

void MainWindow::GetWeather()
{
    qDebug() << "download weather";

    manager = new QNetworkAccessManager(this);

    QString weatherLink = "http://api.openweathermap.org/data/2.5/weather?q=Nuremberg,uk&appid=25879e4404560e805fb4878ea5d57ae2&units=metric&mode=json";
    QUrl url(weatherLink);
    QNetworkRequest request;
    request.setUrl(url);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReadWeather(QNetworkReply*)));

    manager->get(request);

}

void MainWindow::ReadWeather(QNetworkReply* reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
        return;
    }

    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll(),&jsonError);

    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "ERROR!!!";
        qDebug() << jsonError.errorString();
    }

    QJsonObject root_object = json.object();
    QJsonObject main = root_object["main"].toObject();
    QString temp = QString::number(qRound( main["temp"].toDouble()));
    qDebug() << "Temperature: " << " " << temp;

    ui->weatherLabel->setText(temp + "°");

    QJsonObject weather = root_object["weather"].toArray().at(0).toObject();
    //    qDebug() << "Weather: " << " " << weather["icon"];
    QString icon = weather["icon"].toString();
    qDebug() << "Weather: " << " " << icon;

    ui->weatherIcon->setPixmap(":/weather/weatherIcons/" + icon + ".png");
}

MainWindow::~MainWindow()
{
    delete ui;
}
