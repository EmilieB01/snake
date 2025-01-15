#pragma once
#include "Shape.h"

class Food : public Shape
{
	sf::Vector2f foodPosition;
public:
	Food();

	sf::Vector2f GetFoodPosition();
};

