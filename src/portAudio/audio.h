#pragma once

#include "portaudio.h"
#include "../interfaces/BaseWave.h"

namespace Audio {
    int callback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);

    void init(bool* started, double sampleRate, BaseWave* wave);

    void stop();
}
