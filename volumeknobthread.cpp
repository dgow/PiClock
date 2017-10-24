#include "volumeknobthread.h"
#include <QDebug>
#include <WiringPi/wiringPi/wiringPi.h>

VolumeKnobThread::VolumeKnobThread()
{
#ifndef Q_OS_MACOS
    wiringPiSetup();
    pinMode (24, INPUT) ; //knopf
    pinMode (23, INPUT) ; //links/rechts
    pinMode (22, INPUT) ; //links/rechts
    pinMode (25, OUTPUT) ;
#endif
}

void VolumeKnobThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();

    while(true)
    {
        unsigned long step = (unsigned long)0.05;
        QThread::sleep(step);


        int newPinA = -1;
        int newPinB = -1;
        int newPinC = -1;

#ifndef Q_OS_MACOS
        newPinC = digitalRead(24);
        newPinA = digitalRead(23);
        newPinB = digitalRead(22);
#endif
        if(newPinA != pinA)
        {
            qDebug() << "A: " << newPinA;
        }

        if(newPinB != pinB)
        {
            qDebug() << "B: " << newPinB;
        }

        if(newPinC != pinC)
        {
            qDebug() << "C: " << newPinC;
        }

        pinA = newPinA;
        pinB = newPinB;
        pinC = newPinC;
    }
}
