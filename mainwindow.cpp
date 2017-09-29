#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
   // ui->mainWidget->setStyleSheet("background-image: url(:/images/image.png)");
    ui->centralWidget->setStyleSheet("background-image: url(:/images/image.png)");
    //ui->mainWidget->setStyleSheet("background-color: black");


    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->weatherLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->dateLabel->setAttribute(Qt::WA_TranslucentBackground);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer->start(1000);

}

void MainWindow::UpdateTime()
{
    qDebug() << "YEAH";

    QDateTime time = QDateTime::currentDateTime();
    ui->timeLabel->setText(time.toString("hh:mm"));

    ui->dateLabel->setText(time.toString("dddd d. MMMM"));

    ui->weatherLabel->setText("-");
}

MainWindow::~MainWindow()
{
    delete ui;
}
