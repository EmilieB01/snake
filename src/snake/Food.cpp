#include "Food.h"
#include "Snake.h"

Food::Food() : Shape(sf::Color::Red, {16.f, 16.f}) 
{
}


sf::Vector2f Food::GetFoodPosition()
{
	return foodPosition;
}