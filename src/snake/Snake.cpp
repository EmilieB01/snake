#include "Snake.h"

Snake::Snake() : Shape(sf::Color::Green)
{
	snakeDirection.x = 0;
	snakeDirection.y = 0;
}

void Snake::Move(sf::Event& event)
{
	if (event.key.scancode == sf::Keyboard::Scancode::Left) {
		snakeDirection = sf::Vector2f(-1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Right) {
		snakeDirection = sf::Vector2f(1, 0);				
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Up) {
		snakeDirection = sf::Vector2f(0, -1);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Down) {
		snakeDirection = sf::Vector2f(0, 1);
	}
}