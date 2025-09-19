#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
	int startX, startY;
	int direction, nextDirection;
	int size;
	std::vector<sf::Vector2i> body;
public:
	Snake(int x, int y) : startX(x), startY(y), direction(0), size(1), body(1, sf::Vector2i(x, y)) {}
	void move();
	void changeDirection(int newDirection);
	void grow();
	void draw(sf::RenderWindow& window);
	bool checkCollision(int x, int y, int collision_type = 0);
	int getHeadX();
	int getHeadY();
	int getSize();
};

enum COLLISION {
	FOOD, SELF
};