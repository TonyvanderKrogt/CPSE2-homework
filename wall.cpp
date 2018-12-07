#include "wall.hpp"
#include <iostream>
wall::wall(sf::Vector2f size , sf::Vector2f pos) :
	size(size),
	pos(pos)
{}

void wall::draw(sf::RenderWindow & window) const
{
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::Magenta);
	window.draw(rect);
}

void wall::move(sf::Vector2f delta)
{
	pos += delta;
}

sf::RectangleShape wall::getWall()
{
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	return rect;
}

