#ifndef VOLUMEKNOBTHREAD_H
#define VOLUMEKNOBTHREAD_H

#include <QObject>
#include <QThread>

enum KnobState { KnobInit, KnobRight, KnobLeft, KnobZero };

class VolumeKnobThread : public QThread
{
public:
    VolumeKnobThread();

private:
    void run();

    KnobState knobState;

    /*bool InitState();
    bool RightState();
    bool LeftState();
    bool ZeroState();
*/
    int pinA;
    int pinB;
    int pinC;
};

#endif // VOLUMEKNOBTHREAD_H
