#include "food.hpp"

int Food::getX() const 
{ 
	return x; 
}

int Food::getY() const 
{ 
	return y; 
}

bool Food::isSpecial() const 
{ 
	return special; 
}

void Food::setPosition(int newX, int newY) 
{ 
	x = newX; y = newY; 
}

void Food::setSpecial(bool isSpecial) 
{ 
	special = isSpecial; 

}

void Food::draw(sf::RenderWindow& window) 
{
	sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));

	rectangle.setPosition(sf::Vector2f((float)(x), (float)(y)));

	if (special) 
		rectangle.setFillColor(sf::Color::Red);
	else
		rectangle.setFillColor(sf::Color::Yellow);

	window.draw(rectangle);
}