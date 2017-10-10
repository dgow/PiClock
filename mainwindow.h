#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QLabel>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void UpdateTime();
    void GetWeather();
    void ReadWeather(QNetworkReply* reply);
    void PressLightButton();

    void GoBack();

private slots:


private:

    int currentLight;
    QTimer *lightButtonTimer;

    int sunRise;
    int sunSet;

    int lastMinute;

    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

    void SetShadow(QLabel *label);
    int TargetBrightness();

    void mousePressEvent (QMouseEvent *event);

};

#endif // MAINWINDOW_H
