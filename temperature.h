#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>

class Temperature : public QObject
{
    Q_OBJECT
public:
    float temp;
    float humidity;

    explicit Temperature(QObject *parent = nullptr);


signals:

public slots:
    void UpdateData();

    void SendHumidityCommand();
    void ReadHumididyData();
    void SendTemperatureCommand();
    void ReadTemperatureCommand();

private:
    int file;

    void OpenDevice();

};

#endif // TEMPERATURE_H
