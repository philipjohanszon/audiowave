#include "audio.h"
#include <iostream>
#include "../interfaces/BaseWave.h"

namespace Audio {
    void init(bool* started, BaseWave* wave) {
        Pa_Initialize();

        PaStream *stream;
        PaError err;

        err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, wave, 256, callback, nullptr);

        if( err != paNoError ) {
            std::cout << "Could not load audio: " << Pa_GetErrorText(err);
            return;
        }


        Pa_StartStream(stream);



        *started = true;
    }

    void callback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData) {

        ()
    }


}
