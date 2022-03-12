#include "Typewriter.h"
#include <iostream>

Typewriter::Typewriter(std::string text, sf::Font & font, unsigned int size, sf::Vector2f position, float speed, sf::Color fillColor, SPOT spot)
    : m_typedtext(text), m_stop(false), m_speed(speed), m_spot(spot)
{
    m_text.setFont(font);
    m_text.setPosition(position);
    m_text.setCharacterSize(size);
    m_text.setFillColor(fillColor);

    reset();
}

void Typewriter::setText(std::string text)
{
    m_typedtext = text;
    reset();
}

void Typewriter::reset()
{
    m_text.setString("");
    m_stop = false;
    m_elapsedtime = sf::Time::Zero;
    m_counter.restart();
}

void Typewriter::setPosition(sf::Vector2f position)
{
    m_text.setPosition(position);
}

void Typewriter::update()
{
    if (!m_stop)
    {
        m_elapsedtime += m_counter.restart();

        if (m_elapsedtime >= sf::seconds(m_speed))
        {
            m_elapsedtime -= sf::seconds(m_speed);
            if (m_typedtext.length() > 0)
            {
                m_text.setString(m_text.getString() + m_typedtext[0]);

                switch (m_spot)
                {
                    case RIGHT:
                        m_text.setOrigin((int)(m_text.getGlobalBounds().width), 0);
                        break;
                    case CENTER:
                        m_text.setOrigin((int)(m_text.getGlobalBounds().width/2), 0);
                    default: break;
                }

                m_typedtext = m_typedtext.substr(1);
            }
            else
            {
                m_stop = true;
            }
        }
    }
}

void Typewriter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}
