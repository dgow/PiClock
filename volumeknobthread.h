#ifndef VOLUMEKNOBTHREAD_H
#define VOLUMEKNOBTHREAD_H

#include <QObject>
#include <QThread>

class VolumeKnobThread : public QThread
{
public:
    VolumeKnobThread();

private:
    void run();

    int pinA;
    int pinB;
    int pinC;
};

#endif // VOLUMEKNOBTHREAD_H
