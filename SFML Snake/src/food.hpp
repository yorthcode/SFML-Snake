#include <SFML/Graphics.hpp>

class Food {
	int x, y;
	bool special;
public:
	Food(int x, int y, bool special) : x(x), y(y), special(special) {}
	int getX() const;
	int getY() const;
	bool isSpecial() const;
	void setPosition(int newX, int newY);
	void setSpecial(bool isSpecial);
	void draw(sf::RenderWindow& window);
};