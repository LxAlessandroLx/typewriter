#ifndef TYPEWRITER_H
#define TYPEWRITER_H

#include <SFML/Graphics.hpp>

enum SPOT { LEFT, RIGHT, CENTER };

class Typewriter
{
    private:
        sf::Text m_text;
        sf::Clock m_counter;
        sf::Time m_elapsedtime;

        std::string m_typedtext;

        bool m_stop;
        float m_speed;

        SPOT m_spot;

        void reset();

    public:
        Typewriter(
            std::string text, sf::Font & font, unsigned int size = 18U, 
            sf::Vector2f position = sf::Vector2f(0,0), float speed = 1, 
            sf::Color fillColor = sf::Color::Black, SPOT spot = LEFT
        );

        void setText(std::string text);
        void setPosition(sf::Vector2f position);
        void setSpeed(float speed) { m_speed = speed; }
        void setSpot(SPOT spot) { m_spot = spot; }

        void update();
        void draw(sf::RenderWindow & window);
};

#endif
