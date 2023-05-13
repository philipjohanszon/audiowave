#include "baseWaves/SineWave.h"
#include <chrono>
#include <malloc/_malloc.h>
#include <ratio>
#include <thread>
#include "view/view.h"
#include "portAudio/audio.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <portaudio.h>
#include <queue>
#include <thread>
#define sleepms(val) std::this_thread::sleep_for(val##ms)
#define SAMPLE_RATE (44100)
#define FREQUENCY (440.0f)

SineWave* wave = new SineWave(SAMPLE_RATE, FREQUENCY);

int callback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData) {
    return wave->PaStreamCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags, userData);
}

void render(bool* viewCanStart) {
    View::init(viewCanStart, wave);
}

void audio(bool* started) { 
    Audio::init(started, SAMPLE_RATE, wave);
}

int main()
{
    bool* audioStarted = (bool*)malloc(sizeof(bool));

    std::thread audioThread(audio, audioStarted);

    render(audioStarted);
    
    return 0;
}
