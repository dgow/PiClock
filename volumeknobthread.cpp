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

    knobState = KnobInit;

    int pinA = 1;
    int pinB = 1;
    int pinC = 1;
}

void VolumeKnobThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();

    while(true)
    {
        unsigned long step = (unsigned long)0.05;
        QThread::sleep(step);


        int newPinA = 1;
        int newPinB = 1;
        int newPinC = 1;

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


        switch (knobState) {
        case KnobInit:
        {
            if(pinA != newPinA)
            {
                knobState = KnobRight;
            }
            if(pinB != newPinB)
            {
                knobState = KnobLeft;
            }
        }
            break;
        default:
            break;
        }


        pinA = newPinA;
        pinB = newPinB;
        pinC = newPinC;

        switch (knobState) {
        case KnobInit:
            qDebug() << "Init";
            break;
        case KnobRight:
            qDebug() << "Right";
            break;
        case KnobLeft:
            qDebug() << "Left";
            break;
        case KnobZero:
            qDebug() << "Zero";
            break;
        default:
            break;
        }
    }
}
/*
KnobState VolumeKnobThread::InitState()
{
    KnobState state
    return pinA == 1 && pinB == 1;
}

bool VolumeKnobThread::RightState()
{
    return pinA == 1 && pinB == 0;
}

bool VolumeKnobThread::LeftState()
{
    return pinA == 0 && pinB == 1;
}

bool VolumeKnobThread::ZeroState()
{
    return pinA == 0 && pinB == 0;
}
*/
