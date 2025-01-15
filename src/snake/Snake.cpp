#include "Snake.h"
#include <iostream>
#include <random>

Snake::Snake() : Shape(sf::Color::Green, { 16.f, 16.f }), snakeDirection(0, 0), currentTimer(0), moveDelay(0.5f), gameover(false)
{
	snakeBody.push_back({ 0, 0 });
}

void Snake::Move(sf::Event& event)
{
	if (event.key.scancode == sf::Keyboard::Scancode::Left) {
		snakeDirection = {-1, 0};
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Right) {
		snakeDirection = {1, 0};
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Up) {
		snakeDirection = {0, -1};
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Down) {
		snakeDirection = {0, 1};
	}
}

void Snake::Update(sf::Vector2f& foodPosition, float& deltaTime, std::mt19937& gen, Shape& shape)
{

	if (gameover)
	{

	}
	else
	{
		if (currentTimer <= 0)
		{
			if (snakeDirection.x != 0 || snakeDirection.y != 0)
			{
				sf::Vector2f nextPosition = snakeBody[0] + snakeDirection; // Identifie la prochaine position du snake
				if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end())  // si la prochaine position est disponible
				{
					if (nextPosition == foodPosition) // si la prochaine position est celle de la food
					{
						if (nextPosition == foodPosition) {
							// Ajoute une nouvelle partie au corps
							snakeBody.push_back(snakeBody.back());

							// Repositionne la nourriture
							do {
								foodPosition = { static_cast<float>((gen() % 24) - 12), static_cast<float>((gen() % 18) - 9) };
							} while (std::find(snakeBody.begin(), snakeBody.end(), foodPosition) != snakeBody.end());
						}
						else {
							// Décale chaque segment du corps vers l'avant
							for (size_t i = snakeBody.size() - 1; i > 0; --i) {
								snakeBody[i] = snakeBody[i - 1];
							}
						}
					}
					for (int i = snakeBody.size() - 1; i > 0; --i)
					{
						snakeBody[i] = snakeBody[i - 1]; // parcours du snakebody, décale tout de 1 vers la fin
					}
					snakeBody[0] = nextPosition; // première partie du corps de snakebody = nextPosition
				}
				else
				{
					gameover = true;
				}

			}
			currentTimer += (moveDelay - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (moveDelay - 0.01f * snakeBody.size()); // + le snake est grand + le jeu est rapide
		}
		else
		{
			currentTimer -= deltaTime;
		}
	}
}

void Snake::Draw(sf::RenderWindow& window) 
{
	for (sf::Vector2f segment : snakeBody)
	{
		setPosition(segment * getSize().x);
		drawShape(window); 
	}
}

const std::vector<sf::Vector2f>& Snake::getSnakeBody() const 
{
	return snakeBody;
}