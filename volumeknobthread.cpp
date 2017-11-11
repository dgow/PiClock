#include "volumeknobthread.h"
#include <QDebug>
#include <WiringPi/wiringPi/wiringPi.h>

VolumeKnobThread::VolumeKnobThread()
{
#ifndef Q_OS_MACOS
    wiringPiSetup();
    pinMode (24, INPUT) ; //button
    pinMode (23, INPUT) ; //left/right
    pinMode (22, INPUT) ; //left/right
    pinMode (25, OUTPUT);
#endif

    this->SwitchState(KnobInit);

    pinA = 1;
    pinB = 1;
    pinC = 1;
}

void VolumeKnobThread::run()
{
    while(true)
    {
        unsigned long step = (unsigned long)0.3;
        QThread::sleep(step);

        int newPinA = 1;
        int newPinB = 1;
        int newPinC = 1;

#ifndef Q_OS_MACOS
        newPinA = digitalRead(23);
        newPinB = digitalRead(22);
        newPinC = digitalRead(24);
#endif

        bool pinCchanged = newPinC != pinC;

        if(newPinC == 1 && pinCchanged)
        {
            emit pressed();
            qDebug() << "C: " << newPinC;
            QThread::sleep((unsigned long)0.5);
        }

        bool pinAchanged = newPinA != pinA;
        bool pinBchanged = newPinB != pinB;

        switch (knobState) {
        case KnobInit:
        {
            if( pinAchanged )
            {
                if( newPinA == 0 && newPinB == 1 )
                {
                    this->SwitchState(KnobLeft);
                    break;
                }
            }

            if( pinBchanged )
            {
                if( newPinB == 0 && newPinA == 1 )
                {
                    this->SwitchState(KnobRight);
                    break;
                }
            }
            break;
        }

        case KnobLeft:
        {
            if( pinBchanged )
            {
                this->SwitchState(KnobLZero);
            }
            break;
        }

        case KnobRight:
        {
            if( pinAchanged )
            {
                this->SwitchState(KnobRZero);
            }
            break;
        }

        case KnobLZero:
        {
            if( pinAchanged )
            {
                emit up();
                this->SwitchState(KnobInit);
            }
            break;
        }

        case KnobRZero:
        {
            if( pinBchanged )
            {
                emit down();
                this->SwitchState(KnobInit);
            }
            break;
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
    if(knobState != state)
    {
       qDebug() << "STATE SWITCH: " << state;
    }

    knobState = state;
}
