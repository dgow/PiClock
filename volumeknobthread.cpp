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

    this->SwitchState(KnobInit);

    pinA = 1;
    pinB = 1;
    pinC = 1;
}

void VolumeKnobThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();

    while(true)
    {
        unsigned long step = (unsigned long)0.1;
        QThread::sleep(step);

        //qDebug() << "STATE: " << knobState;


        int newPinA = 1;
        int newPinB = 1;
        int newPinC = 1;

#ifndef Q_OS_MACOS
        newPinA = digitalRead(23);
        newPinB = digitalRead(22);
        newPinC = digitalRead(24);
#endif

        bool pinCchanged = newPinC != pinC;

        if(newPinC == 1)
        {
            //if(this->switchOn == true)
            {
                emit pressed();
                qDebug() << "C: " << newPinC;
                this->switchOn = newPinC;

                 QThread::sleep(0.5);
            }
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
       // qDebug() << "STATE SWITCH: " << state;
    }

    knobState = state;
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
