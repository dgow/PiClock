#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    ui->timeLabel->setText("10:01");
    ui->weatherLabel->setText("10°");
}

MainWindow::~MainWindow()
{
    delete ui;
}
