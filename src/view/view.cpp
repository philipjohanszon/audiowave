#include "view.h"
#include "../interfaces/BaseWave.h"
#include <cmath>
#include <cstdio>
#include <malloc/_malloc.h>

namespace View {
    BaseWave* audioWave = nullptr;

    void init(bool* viewCanStart, BaseWave* wave) {
        if (wave == nullptr) {
            return;
        }

        audioWave = wave;

        while (!(*viewCanStart)) {sf::sleep(sf::milliseconds(100));}

        printf("started");

        draw();
    }

    void draw() {
        sf::RenderWindow window(sf::VideoMode(1000, 1000), "AudioWave");

        window.setFramerateLimit(144);

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

            sf::VertexArray curve(sf::PrimitiveType::LineStrip, 100);
            double phase = audioWave->getPhase();
            double sampleRate = audioWave->getSampleRate();
            double frequency = audioWave->getFrequency();

            for (unsigned int i = 0; i < window.getSize().x; i++) {
                const sf::Vertex vertex = sf::Vertex(sf::Vector2f((float) i, audioWave->calculate(phase)*300 + 500), sf::Color::Black);

                phase += (frequency / sampleRate);
                if (phase >= 2.0f) phase -= 2.0f;

                curve.append(vertex);
            }


            // Clear the window
            window.clear(sf::Color::White);

            window.draw(curve);

            // Display the window
            window.display();
        }

    }

};
