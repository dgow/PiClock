#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QLabel>

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

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

    void SetShadow(QLabel *label);

};

#endif // MAINWINDOW_H
