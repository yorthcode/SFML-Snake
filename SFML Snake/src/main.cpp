#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "Snake");
	Game g = Game();

	sf::Clock clock;

    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (auto keyEvent = event->getIf<sf::Event::KeyPressed>())
            {
                g.handleInput(keyEvent->code);
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 0.2f && !g.isGameOver())
        {

            g.getSnake().move();
            
            if (g.getSnake().checkCollision(g.getFood().getX(), g.getFood().getY(), COLLISION::FOOD))
            {
                g.increaseScore(g.getFood().isSpecial() ? 5 : 1);
                g.getSnake().grow();

                int newX = (rand() % 30) * 20;
                int newY = (rand() % 30) * 20;

                while (g.getSnake().checkCollision(newX, newY))
                {
                    newX = (rand() % 30) * 20;
                    newY = (rand() % 30) * 20;
                }
                g.getFood().setPosition(newX, newY);
				g.getFood().setSpecial((rand() % 5) == 0);
            }
            else if (g.getSnake().checkCollision(g.getSnake().getHeadX(), g.getSnake().getHeadY(), COLLISION::SELF) && g.getSnake().getSize() > 1)
            {
                g.setGameOver(true);
			}

            clock.restart();
		}

        window.clear();
        g.draw(window);
        window.display();
    }
	return 0;
}