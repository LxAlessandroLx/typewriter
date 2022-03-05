# Typewriter
A small C++/SFML class for typewriter effect

## Requirements
You need to install SFML
<pre>
sudo apt install libsfml-dev
</pre>

## Usage 
This is an example of how to use it
```c++
#include "Typewriter.h"

int main()
{
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Typewriter");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("path/to/font.ttf");

    Typewriter typewriter("This is an example text", font, 32, {screenWidth/2, 100}, .05f, sf::Color::White, CENTER);

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
        typewriter.draw(window);
        window.display();
    }
}
```
- "path/to/font.ttf" is your font path
- "This is an example text" is the text to display
- 32 is the fontsize
- {screenWidth/2, 100} is the text pos
- .05f (1/20 aka 20 characters per second) is the speed
- sf::Color::White is the text color
- CENTER is the text alignment

## Compile your project
<pre>
g++ -o [program name] [your script.cpp] src/Typewriter.cpp -I src -lsfml-system -lsfml-window -lsfml-graphics 
</pre>
Where "program name" is your program name and "your script.cpp" is your script path
