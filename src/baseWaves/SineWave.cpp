#include "SineWave.h"
#include <cmath>
#include <cstdio>
#include <queue>
#define TWO_PI (3.14159265f * 2.0f)


SineWave::SineWave(double sampleRate, float frequency) {
    this->m_sampleRate = sampleRate;
    this->m_phase = 0;
    this->m_frequency = frequency;
}

int SineWave::PaStreamCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                                void *userData) {
    (void)timeInfo;
    (void)inputBuffer;
    (void)statusFlags;
    (void)userData;

    float* out = (float*)outputBuffer;

    for (unsigned long i = 0; i < framesPerBuffer; i++)
    {
        *out++ = calculate(m_phase);

        m_phase += (m_frequency / m_sampleRate);
        if (m_phase >= 2.0f) m_phase -= 2.0f;
    }

    return paContinue;
    
}

double SineWave::getSampleRate() {
    return m_sampleRate;
}

float SineWave::calculate(double phase) {
    return sinf(phase * TWO_PI);
}

float SineWave::getPhase() {
    return m_phase;
}

float SineWave::getFrequency() {
    return m_frequency;
}
