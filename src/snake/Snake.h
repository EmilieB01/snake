#pragma once
#include "Shape.h"
#include <random>

class Snake : public Shape
{
	std::vector<sf::Vector2f> snakeBody;
	sf::Vector2f snakeDirection;
	float currentTimer;
	float moveDelay;       
	bool gameover;

public:
	Snake();

	void Move(sf::Event& event);
	void Update(sf::Vector2f& foodPosition, float& deltaTime, std::mt19937& gen, Shape& shape);
	void Draw(sf::RenderWindow& window);

	const std::vector<sf::Vector2f>& getSnakeBody() const;

};

