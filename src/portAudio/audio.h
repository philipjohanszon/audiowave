#pragma once

#include "portaudio.h"

namespace Audio {
    void callback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);

    void init(bool* started, double sampleRate);

    void stop();
}
