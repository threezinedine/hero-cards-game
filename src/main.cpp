#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode({640, 480}), "SFML works");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({100, 200});

    while (window.isOpen())
    {
        // Process events
        while (const auto &event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                auto keyEvent = event->getIf<sf::Event::KeyPressed>();

                if (keyEvent->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
        }

        // Update

        // Draw
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}