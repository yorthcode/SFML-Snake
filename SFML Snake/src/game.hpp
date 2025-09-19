#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "food.hpp"

class Game {
	int score;
	bool gameOver;
	Snake snake;
	Food food;
public:
	Game();
	void increaseScore(int amount);
	void setGameOver(bool state);
	void draw(sf::RenderWindow& window);
	bool isGameOver() const;
	int getScore() const;
	void handleInput(sf::Keyboard::Key key);
	Snake& getSnake();
	Food& getFood();
};