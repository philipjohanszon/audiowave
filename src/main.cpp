#include "baseWaves/SineWave.h"
#include "filters/HighpassFilter.h"
#include "interfaces/BaseWave.h"
#include "view/view.h"
#include "portAudio/audio.h"
#include <thread>
#define SAMPLE_RATE (44100)
#define FREQUENCY (440.0f)

void audio(bool* started, BaseWave* wave) { 
    Audio::init(started, SAMPLE_RATE, wave);
}

int main()
{
    SineWave* wave = new SineWave(SAMPLE_RATE, FREQUENCY);
    HighpassFilter* highpass = new HighpassFilter(0.4f);
    wave->addFilter(highpass);

    bool audioStarted = false;

    std::thread audioThread(audio, &audioStarted, wave);

    View::init(&audioStarted, wave);

    Pa_Terminate();

    audioThread.join();
    
    return 0;
}
