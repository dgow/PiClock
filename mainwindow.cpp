#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

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

    QDateTime time = QDateTime::currentDateTime();
    ui->timeLabel->setText(time.toString("hh:mm"));

    ui->dateLabel->setText(time.toString("dddd d. MMMM"));

    ui->weatherLabel->setText("-");


}

MainWindow::~MainWindow()
{
    delete ui;
}
