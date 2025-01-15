#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
    sf::Vector2f position; 
    sf::Color color; 
    sf::Vector2f size;

public:
    Shape(sf::Color color, sf::Vector2f size);

    void setPosition(const sf::Vector2f& newPosition);
    sf::Vector2f getPosition() const;

    void setColor(const sf::Color& newColor);
    sf::Color getColor() const;

    void setSize(const sf::Vector2f& newSize);
    sf::Vector2f getSize() const;

    void drawShape(sf::RenderWindow& window) const;
};

