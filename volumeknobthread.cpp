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

    pinA = 1;
    pinB = 1;
    pinC = 1;
}

void VolumeKnobThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();

    while(true)
    {
        unsigned long step = (unsigned long)1;
        QThread::sleep(step);


        int newPinA = 1;
        int newPinB = 1;
        int newPinC = 1;

#ifndef Q_OS_MACOS
        newPinC = digitalRead(24);
        newPinA = digitalRead(23);
        newPinB = digitalRead(22);
#endif
        /*
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
        */


        switch (knobState) {
        case KnobInit:
        {
            if(newPinA == 0)
            {
                this->SwitchState(KnobRight);
            }
            if(newPinB == 0)
            {
                this->SwitchState(KnobLeft);
            }
        }
        case KnobRight:
        {
            if(pinA == 0 && pinB == 0)
            {
                this->SwitchState(KnobRZero);
            }
        }
        case KnobLeft:
        {
            if(pinA == 0 && pinB == 0)
            {
                this->SwitchState(KnobLZero);
            }
        }

        case KnobRZero:
        {
            if(pinA == 0 && pinB == 1)
            {
                qDebug() << "Louder!!!";
                this->SwitchState(KnobLZero);
            }
        }

        case KnobLZero:
        {
            if(pinA == 1 && pinB == 0)
            {
                qDebug() << "Leiser!!!";
                this->SwitchState(KnobLZero);
            }
        }



        default:
            break;
        }

        pinA = newPinA;
        pinB = newPinB;
        pinC = newPinC;
    }
}

void VolumeKnobThread::SwitchState(KnobState state)
{
    knobState = state;

    qDebug() << "STATE SWITCH: " << state;
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
