#ifndef VOLUMEKNOBTHREAD_H
#define VOLUMEKNOBTHREAD_H

#include <QObject>
#include <QThread>

enum KnobState { KnobInit, KnobRight, KnobLeft, KnobRZero, KnobLZero };

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

    void SwitchState(KnobState state);
};

#endif // VOLUMEKNOBTHREAD_H
