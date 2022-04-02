#ifndef TYPEWRITER_H
#define TYPEWRITER_H

#include <SFML/Graphics.hpp>

/// Possible text alignments 
enum SPOT { LEFT, RIGHT, CENTER };

/// @brief Class to simulate typewriter effect
class Typewriter : public sf::Drawable
{
    private:
        /// Text to write
        sf::Text m_text;
        sf::Clock m_counter;
        sf::Time m_elapsedtime;

        /// Text still to be written
        std::string m_typedtext;

        /// Boolean to indicate if it finished to write
        bool m_stop;
        /// Every how many seconds a letter is written
        float m_speed;

        /// The text alignment
        SPOT m_spot;

        /// Function to reset the typewriter
        void reset();

        /** 
         * @brief Draw function inherited from sf::Drawable to draw the typewriter's typed text
         * @param target Render target to draw to
         * @param states Current render state
        */
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    public:
        /**
         * @brief Typewriter constructor
         * @param text Text to write
         * @param font Font to use
         * @param size Text size
         * @param position Text position
         * @param speed Typing speed
         * @param fillColor Text color
         * @param spot Text alignment
        */
        Typewriter(
            std::string text, sf::Font & font, unsigned int size = 18U, 
            sf::Vector2f position = sf::Vector2f(0,0), float speed = 1, 
            sf::Color fillColor = sf::Color::Black, SPOT spot = LEFT
        );

        /**
         * @brief Set the typewriter text and reset it
         * @param text New text
        */
        void setText(std::string text);

        /**
         * @brief Set the text position
         * @param position Text position
        */
        void setPosition(sf::Vector2f position);

        /**
         * @brief Set the typewriter's typing speed
         * @param text Typing speed
        */
        void setSpeed(float speed) { m_speed = speed; }

        /**
         * @brief Set the typewriter text alignment
         * @param text Text alignment
        */
        void setSpot(SPOT spot) { m_spot = spot; }

        /// @brief Update the typewriter
        void update();
};

#endif // TYPEWRITER_H
