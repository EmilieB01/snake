#include "Shape.h"

Shape::Shape(sf::Color color)
{
	shape.setSize(sf::Vector2f(32, 32));
	shape.setFillColor(color);
}