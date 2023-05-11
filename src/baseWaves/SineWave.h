#pragma once

#include "../interfaces/BaseWave.h"
#include <portaudio.h>
#include <queue>

class SineWave : public BaseWave {
public:
    SineWave(double sampleRate, float frequency);

    int PaStreamCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                         void *userData) override;
    double getSampleRate() override;
    float calculate();
    float getPhase();
    float getFrequency();

private: 
    double m_sampleRate;
    float m_phase;
    float m_frequency;
};
