#pragma once
#include "Shape.h"

class Snake : public Shape
{
	std::vector<sf::Vector2f> snakeBody;
	sf::Vector2f snakeDirection;

public:
	Snake();

	void Move(sf::Event& event);
};

