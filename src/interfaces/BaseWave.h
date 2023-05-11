#ifndef BASEWAVE_H
#define BASEWAVE_H

#include <portaudio.h>

class BaseWave {
public:
    virtual ~BaseWave() {}
    virtual int PaStreamCallback(const void *inputBuffer, void *outputBuffer,
                               unsigned long framesPerBuffer,
                               const PaStreamCallbackTimeInfo *timeInfo,
                               PaStreamCallbackFlags statusFlags,
                               void *userData) = 0;
    virtual double getSampleRate() = 0;
};

#endif

