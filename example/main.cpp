#include "Typewriter.h"

int main()
{
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Typewriter");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("res/font.ttf");

    Typewriter typewriter("This is an example text", font, 32, {screenWidth/2,100}, .05f, sf::Color::White, CENTER);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        typewriter.update();

        window.clear(sf::Color::Black);
        window.draw(typewriter);
        window.display();
    }
}
