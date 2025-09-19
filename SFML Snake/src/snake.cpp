#include "snake.hpp"

void Snake::move() 
{
	direction = nextDirection;
	for (int i = size - 1; i > 0; --i) 
	{
		body[i] = body[i - 1];
	}

	switch (direction) 
	{
		case 0: body[0].y -= 20; 
			break;
		case 1: body[0].x += 20; 
			break;
		case 2: body[0].y += 20; 
			break;
		case 3: body[0].x -= 20; 
			break;
	}

	if (body[0].y < 0) 
		body[0].y = 580;
	if (body[0].y >= 600) 
		body[0].y = 0;
	if (body[0].x < 0) 
		body[0].x = 580;
	if (body[0].x >= 600) 
		body[0].x = 0;
}

void Snake::changeDirection(int newDirection) 
{

	if ((direction + 2) % 4 == newDirection && size > 1) 
		return;
	nextDirection = newDirection;
}

void Snake::grow() 
{
	body.push_back(body.back());
	size++;
}

void Snake::draw(sf::RenderWindow& window) 
{
	sf::RectangleShape segment(sf::Vector2f(20, 20));

	for (sf::Vector2i& part : body) 
	{
		if (part == body[0])
			segment.setFillColor(sf::Color::Magenta);
		else
			segment.setFillColor(sf::Color::Green);

		segment.setPosition(sf::Vector2f(part.x, part.y));
		window.draw(segment);
	}
}

bool Snake::checkCollision(int x, int y, int collision_type)
{
	for (size_t i = collision_type; i < body.size(); ++i) {
		if (body[i].x == x && body[i].y == y)
			return true;
	}
	return false;
}

int Snake::getHeadX() 
{
	return body[0].x;
}

int Snake::getHeadY() 
{
	return body[0].y;
}

int Snake::getSize() 
{
	return size;
}