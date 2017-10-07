#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    currentLight = 80;

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

    UpdateTime();
    GetWeather();

    lightButtonTimer = new QTimer(this);
    connect(lightButtonTimer, SIGNAL(timeout()), this, SLOT(PressLightButton()));
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

    /*
    //sun rise
    QJsonObject sys = root_object["sys"].toObject();
    QString sunRise = sys["sunrise"].toString();
    int sunRiseTime = sys["sunrise"].toInt();
    qDebug() << "SunRise: " << " " << sunRiseTime;

    QString sunSet = sys["sunset"].toString();
    int sunSetTime = sys["sunset"].toInt();
    qDebug() << "SunSet: " << " " << sunSetTime;
*/

    QDateTime time = QDateTime::currentDateTime();
    qDebug() << time.isDaylightTime();


    if(time.isDaylightTime())
    {
        if(currentLight != 100)
        {
               lightButtonTimer->start(1000);
        }
    }
    else
    {
        if(currentLight != 0)
        {
               lightButtonTimer->start(1000);
        }
    }
}

void MainWindow::PressLightButton()
{
    QProcess *process = new QProcess(this);
    QStringList args;
    args << "prev";
    process->start("/home/pi/Desktop/pressBrightness.sh", args);

    currentLight+= 10;
    if(currentLight > 100)
    {
        currentLight = 0;
    }

    QDateTime time = QDateTime::currentDateTime();
    if(time.isDaylightTime())
    {
        if(currentLight == 100)
        {
               lightButtonTimer->stop();
        }
    }
    else
    {
        if(currentLight == 0)
        {
               lightButtonTimer->stop();
        }
    }
}

//void MainWindow::mousePressEvent(QMouseEvent *ev)
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->y() > 100)
    {
        if(event->x() < 240)
        {
            //amixer sset 'Speaker' 5%+

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
    else if(event->y() > 200)
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
    else
    {
        QProcess *process = new QProcess(this);
        QStringList args;
        args << "toggle";
        process->start("mpc", args);
    }

    qDebug() << "YEAH " << event->x();
}

MainWindow::~MainWindow()
{
    delete ui;
}
