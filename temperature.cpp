#include "temperature.h"

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
 //   write(file, config, 1);
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

            // Output data to screen
            printf("Relative Humidity : %.2f RH \n", humidity);
    }

#endif

}
