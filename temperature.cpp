#include "temperature.h"
#include <QDebug>

#ifndef Q_OS_MACOS
#include <linux/i2c-dev.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

Temperature::Temperature(QObject *parent) : QObject(parent)
{

}

void Temperature::UpdateData()
{
    qDebug() << "Update Temerature data";
    printf("Failed to open the bus. neeee luku \n");

#ifndef Q_OS_MACOS
    int file;
    char *bus = "/dev/i2c-1";

    if((file = open(bus, O_RDWR)) < 0)
    {
            printf("Failed to open the bus. \n");
            exit(1);
    }

    // Get I2C device, SI7021 I2C address is 0x40(64)
    ioctl(file, I2C_SLAVE, 0x40);

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

            printf("Temperature in Fahrenheit : %.2f F \n", fTemp);
    }



#endif

}
