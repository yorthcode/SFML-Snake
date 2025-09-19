#include "game.hpp"

void Game::increaseScore(int amount) 
{
	score += amount;
}

void Game::setGameOver(bool state) 
{
	gameOver = state;
}

void Game::draw(sf::RenderWindow& window) 
{
	food.draw(window);
	snake.draw(window);
}

bool Game::isGameOver() const 
{
	return gameOver;
}

int Game::getScore() const 
{
	return score;

}

Game::Game() : score(0), gameOver(false), snake(Snake(100, 100)), food(Food(100,200, false)) {}

void Game::handleInput(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Key::Up || key == sf::Keyboard::Key::W)
		snake.changeDirection(0);
    else if (key == sf::Keyboard::Key::Down || key == sf::Keyboard::Key::S)
        snake.changeDirection(2);
    else if (key == sf::Keyboard::Key::Left || key == sf::Keyboard::Key::A)
        snake.changeDirection(3);
    else if (key == sf::Keyboard::Key::Right || key == sf::Keyboard::Key::D)
        snake.changeDirection(1);
}

Snake& Game::getSnake() 
{
	return snake;
}

Food& Game::getFood() 
{
	return food;
}