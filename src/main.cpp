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
#define SAMPLE_RATE (44100)
#define FREQUENCY (440.0f)

SineWave* wave = new SineWave(SAMPLE_RATE, FREQUENCY);

void audio(bool* started) { 
    Audio::init(started, SAMPLE_RATE, wave);
}

int main()
{

    bool audioStarted = false;

    std::thread audioThread(audio, &audioStarted);

    View::init(&audioStarted, wave);

    Pa_Terminate();

    audioThread.join();
    
    return 0;
}
