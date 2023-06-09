#include "audio.h"
#include "../interfaces/BaseWave.h"
#include <cstdio>
#include <iostream>
#include <malloc/_malloc.h>
#include <portaudio.h>

namespace Audio {
    BaseWave *audioWave = nullptr;

    void init(bool *started, double sampleRate, BaseWave *wave) {
        if (wave == nullptr) {
            return;
        }

        audioWave = wave;

        Pa_Initialize();

        PaStream *stream;
        PaError err;

        err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, sampleRate, 256, callback, nullptr);

        if (err != paNoError) {
            std::cout << "Could not load audio: " << Pa_GetErrorText(err);
            return;
        }

        Pa_StartStream(stream);

        *started = true;

        while (true) {
            Pa_Sleep(2000);
        }
    }

    int callback(const void *inputBuffer, void *outputBuffer,
            unsigned long framesPerBuffer,
            const PaStreamCallbackTimeInfo *timeInfo,
            PaStreamCallbackFlags statusFlags, void *userData) {

        return audioWave->PaStreamCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags, userData);
    }

} 
