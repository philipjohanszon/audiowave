#ifndef BASEWAVE_H
#define BASEWAVE_H

#include <portaudio.h>
#include "Filter.h"

class BaseWave {
    public:
        virtual ~BaseWave() {}
        virtual int PaStreamCallback(const void *inputBuffer, void *outputBuffer,
                unsigned long framesPerBuffer,
                const PaStreamCallbackTimeInfo *timeInfo,
                PaStreamCallbackFlags statusFlags,
                void *userData) = 0;
        virtual double getSampleRate() = 0;
        virtual float calculate(double phase) = 0;
        virtual float getPhase() = 0;
        virtual float getFrequency() = 0;
        virtual void addFilter(Filter* filter) = 0;
};

#endif

