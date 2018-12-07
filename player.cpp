#include "player.hpp"
#include <iostream>

player::player(sf::Vector2f size, sf::Vector2f pos) :
	size(size),
	pos(pos)
{}

void player::draw(sf::RenderWindow & window) const
{

	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::Red);
	window.draw(rect);
}

void player::move(sf::Vector2f delta) {
	pos += delta;
}

void player::jump(sf::Vector2f target) {
	pos = target;
}

void player::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}

sf::RectangleShape player::getPlayer()
{
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	return rect;
}
