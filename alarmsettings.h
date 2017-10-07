#ifndef ALARMSETTINGS_H
#define ALARMSETTINGS_H

#include <QObject>
#include <QWidget>





class AlarmSettings : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmSettings(QWidget *parent = nullptr);

signals:

public slots:

    void goBack();
    void on_backButton_clicked();
};

#endif // ALARMSETTINGS_H
