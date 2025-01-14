#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

#include "Snake.h"
#include "Food.h"

int main()
{
	std::mt19937 gen;
	gen.seed(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake"); // Création de la fenêtre

	sf::RectangleShape shape(sf::Vector2f(32, 32)); // Création shape de food + body

	Snake snake;
	std::vector<sf::Vector2f> snakeBody; // Création de liste de snakebody
	snakeBody.push_back(sf::Vector2f(0, 0)); //pushback dans snakebody
	sf::Vector2f snakeDirection(0, 0); // Direction du snake

	sf::Vector2f foodPosition; // création de la position de food

	bool found;
	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8); // création d'une position aléatoire tmpPosition
		if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) // si la position aléatoire est disponible
		{
			found = true;	//found == true
		}
		foodPosition = tmpPosition; // food prend la position aléatoire
	} while (found); // recommence tant que la position aléatoire est disponible


	sf::View v = window.getDefaultView(); // création de la view v
	v.setCenter(0, 0); // view set au centre

	window.setView(v); // view initialisée


	float time_between_move = 0.5f; // temps entre les mouvements 0.5
	float current_timer_between_move = 0.f; // temps actuel entre les mouvements : 0

	bool gameover = false;

	sf::Clock c;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		float deltaTime = c.restart().asSeconds();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) 
			{
				snake.Move(event);
			}
		}

		window.clear(sf::Color::Black);
		if (gameover) 
		{

		}
		else
		{
			if (current_timer_between_move <= 0) // ??
			{
				if (snakeDirection.x != 0 || snakeDirection.y != 0) 
				{
					sf::Vector2f nextPosition = snakeBody[0] + snakeDirection; // Identifie la prochaine position du snake
					if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end())  // si la prochaine position est disponible
					{
						if (nextPosition == foodPosition) // si la prochaine position est celle de la food
						{
							do
							{
								found = false;
								sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
								if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end() && nextPosition != tmpPosition)	// Positionner de nouveau la food aléatoirement
								{
									found = true;
								}
								foodPosition = tmpPosition;
							} while (found);
							snakeBody.push_back(snakeBody[snakeBody.size() - 1]); // pushback une nouvelle partie du corps du snake
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
				current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size()); // + le snake est grand + le jeu est rapide
			}
			else 
			{
				current_timer_between_move -= deltaTime;
			}

			for (sf::Vector2f p : snakeBody) 
			{
				shape.setPosition(p * shape.getSize().x);
				shape.setFillColor(sf::Color::Green);		// set position et couleur du snake
				window.draw(shape);
			}

			shape.setPosition(foodPosition * shape.getSize().x);
			shape.setFillColor(sf::Color::Red);			// set position et couleur de la food
			window.draw(shape);
		}

		window.display();
	}

	return 0;
}
