#include "Shape.h"

Shape::Shape(sf::Color color, sf::Vector2f size) : color(color), size(size), position(0.f, 0.f) {}

void Shape::setPosition(const sf::Vector2f& newPosition) 
{
    position = newPosition;
}

sf::Vector2f Shape::getPosition() const
{
    return position;
}

void Shape::setColor(const sf::Color& newColor) 
{
    color = newColor;
}

sf::Color Shape::getColor() const 
{
    return color;
}

void Shape::setSize(const sf::Vector2f& newSize) 
{
    size = newSize;
}

sf::Vector2f Shape::getSize() const 
{
    return size;
}

void Shape::drawShape(sf::RenderWindow& window) const 
{
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}