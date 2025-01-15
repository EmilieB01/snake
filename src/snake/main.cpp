#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

#include "Snake.h"
#include "Food.h"

int main()
{
	std::mt19937 gen;
	gen.seed(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake"); // Cr�ation de la fen�tre

	//sf::RectangleShape shape(sf::Vector2f(32, 32)); // Cr�ation shape de food + body

	Snake snake;
	Food food;

	sf::Vector2f foodPosition = food.GetFoodPosition(); // cr�ation de la position de food
	bool found;
	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8); // cr�ation d'une position al�atoire tmpPosition
		if (std::find(snake.getSnakeBody().begin(), snake.getSnakeBody().end(), tmpPosition) != snake.getSnakeBody().end()) // si la position al�atoire est disponible
		{
			found = true;	//found == true
		}
		foodPosition = tmpPosition; // food prend la position al�atoire
	} while (found); // recommence tant que la position al�atoire est disponible


	sf::View v = window.getDefaultView(); // cr�ation de la view v
	v.setCenter(0, 0); // view set au centre
	window.setView(v); // view initialis�e

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
		
		// Mise � jour de l'�tat du jeu
		snake.Update(foodPosition, deltaTime, gen, food);

		// Dessin des �l�ments
		window.clear(sf::Color::Black);
		snake.Draw(window); // Dessin du serpent
		food.drawShape(window); // Dessin de la nourriture
		window.display();
	}

	return 0;
}

//Help �a ne marche pas, mais bon, au moins le code se lance, ce qui n'�tait vraiment pas le cas quand j'ai commenc� � tout modifier il y a des heures...

//Pas termin�, j'ai fait tout ce que j'ai pu maintenant il faut que j'aille dormir