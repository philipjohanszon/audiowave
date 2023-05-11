#include "baseWaves/SineWave.h"
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

SineWave* sinewave = new SineWave(SAMPLE_RATE, FREQUENCY);

int callback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData) {
    return sinewave->PaStreamCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags, userData);
}

void render(bool* viewCanStart) {
    View::init(viewCanStart);
}

void audio(bool* started, double sampleRate) { 
    Audio::init(started, sampleRate);
}

int main()
{
    bool audioStarted = false;

    std::thread renderThread(render, &audioStarted);
    std::thread audioThread(audio, &audioStarted, SAMPLE_RATE);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "AudioWave");
        while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        // Clear the window
        window.clear(sf::Color::White);

        sf::VertexArray points(sf::Points);
        float x = 0;

        while(!queue->empty()) {
            printf("Queue length: %lu \n", queue->size());
            printf("X: %.2f \n", x);
            printf("Y: %.2f \n", queue->front()*100 + 200);
            points.append(sf::Vertex(sf::Vector2f(x, queue->front() * 100), sf::Color::Black));
            queue->pop();
            x += 1;
        }
            
        printf("\n\n\n\n\nVERTEX SIZE : %lu \n\n\n\n\n\n", points.getVertexCount());

        window.draw(points);
        
        // Display the window
        window.display();
    }

    return 0;
}
