#include "view.h"
#include "../interfaces/BaseWave.h"

namespace View {

    void init(bool* viewCanStart, baseWave wave) {
        while (!(*viewCanStart)) {sf::sleep(sf::milliseconds(100));}

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


            // Clear the window
            window.clear(sf::Color::White);

            // Display the window
            window.display();
        }

    }

};