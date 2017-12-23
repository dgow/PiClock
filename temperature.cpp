#include "temperature.h"
#include <QDebug>

#ifndef Q_OS_MACOS
#include <linux/i2c-dev.h>
#else
#define I2C_SLAVE 0x00 //fake
#endif

#include <stdio.h>
#include <stdlib.h>

//#ifdef Q_OS_MACOS
#include <unistd.h>
//#endif

#include <sys/ioctl.h>
#include <fcntl.h>
#include <QTimer>

//fake function
#ifdef Q_OS_MACOS
void write(int a, int b, char c) {a = b; a = c;}
#endif


Temperature::Temperature(QObject *parent) : QObject(parent)
{
    OpenDevice();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateData()));
    timer->start(10000);

    UpdateData();
}

void Temperature::OpenDevice()
{
#ifndef Q_OS_MACOS

    char *bus = (char *)"/dev/i2c-1";

    if((file = open(bus, O_RDWR)) < 0)
    {
            printf("Failed to open the bus. \n");
            exit(1);
    }

    // Get I2C device, SI7021 I2C address is 0x40(64)
    ioctl(file, I2C_SLAVE, 0x40);
#endif

}

void Temperature::SendHumidityCommand()
{
    char config[1] = {static_cast<char>(0xF5)};
    write(file, config, 1);
}

void Temperature::ReadHumididyData()
{
    // Read 2 bytes of humidity data
    // humidity msb, humidity lsb
    char data[2] = {0};
    if(read(file, data, 2) != 2)
    {
            printf("Error : Input/output Error \n");
    }
    else
    {
            // Convert the data
            float humidity = (((data[0] * 256 + data[1]) * 125.0) / 65536.0) - 6;

            this->humidity = humidity;

            // Output data to screen
            qDebug() << "Relative Humidity : " << humidity;
    }
}

void Temperature::SendTemperatureCommand()
{
    char config[1] = {static_cast<char>(0xF3)};
    write(file, config, 1);
}

void Temperature::ReadTemperatureCommand()
{
    // Read 2 bytes of temperature data
    // temp msb, temp lsb

    char data[2] = {0};

    if(read(file, data, 2) != 2)
    {
            printf("Error : Input/output Error \n");
    }
    else
    {
            // Convert the data
            float cTemp = (((data[0] * 256 + data[1]) * 175.72) / 65536.0) - 46.85;
            float fTemp = cTemp * 1.8 + 32;

            // Output data to screen
            printf("Temperature in Celsius : %.2f C \n", cTemp);

            this->temp = cTemp;
            qDebug() << "Temperatur : " << this->temp;

            printf("Temperature in Fahrenheit : %.2f F \n", fTemp);
    }

}

void Temperature::UpdateData()
{
    qDebug() << "Update Temerature data";
    printf("Failed to open the bus. neeee luku \n");

    SendHumidityCommand();
    QTimer::singleShot(1000, this, SLOT(ReadHumididyData()));
    QTimer::singleShot(2000, this, SLOT(SendTemperatureCommand()));
    QTimer::singleShot(3000, this, SLOT(ReadTemperatureCommand()));

    return;

#ifndef Q_OS_MACOS



    // Send humidity measurement command(0xF5)
    char config[1] = {0xF5};
    write(file, config, 1);
    sleep(1);

    // Read 2 bytes of humidity data
    // humidity msb, humidity lsb
    char data[2] = {0};
    if(read(file, data, 2) != 2)
    {
            printf("Error : Input/output Error \n");
    }
    else
    {
            // Convert the data
            float humidity = (((data[0] * 256 + data[1]) * 125.0) / 65536.0) - 6;

            this->humidity = humidity;

            // Output data to screen
            qDebug() << "Relative Humidity : " << humidity;
    }

    // Send temperature measurement command(0xF3)
    config[0] = 0xF3;
    write(file, config, 1);
    sleep(1);

    // Read 2 bytes of temperature data
    // temp msb, temp lsb
    if(read(file, data, 2) != 2)
    {
            printf("Error : Input/output Error \n");
    }
    else
    {
            // Convert the data
            float cTemp = (((data[0] * 256 + data[1]) * 175.72) / 65536.0) - 46.85;
            float fTemp = cTemp * 1.8 + 32;

            // Output data to screen
            printf("Temperature in Celsius : %.2f C \n", cTemp);

            this->temp = cTemp;
            qDebug() << "Temperatur : " << this->temp;


            this->temp = cTemp;

            printf("Temperature in Fahrenheit : %.2f F \n", fTemp);
    }

#endif

}
