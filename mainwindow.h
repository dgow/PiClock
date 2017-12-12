#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QLabel>
#include <QTimer>

#include "mopidyreader.h"
#include "weekdaybutton.h"
#include <temperature.h>

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

    void UpdateVolume();
    void UpdateSong();

private slots:
    void on_alarmButton_clicked();
    void on_stopAlarmButton_clicked();
    void on_soundButton_clicked();

private:

    int currentLight;
    QTimer *lightButtonTimer;

    int sunRise;
    int sunSet;

    int lastMinute;

    WeekDayButton *currentWeekDayButton;

    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

    void SetShadow(QWidget *label);
    int TargetBrightness();

    void mousePressEvent (QMouseEvent *event);



    MopidyReader *mopidyReader;

    Temperature *temp;
};

#endif // MAINWINDOW_H
