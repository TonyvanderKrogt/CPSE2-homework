#include "wall.hpp"
#include <iostream>
wall::wall(sf::Vector2f size, sf::Vector2f pos,sf::Color color) :
	size(size),
	pos(pos),
	color(color)
{
	rect.setSize(size);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::Magenta);
}

void wall::draw(sf::RenderWindow & window) const
{
	window.draw(rect);
}

void wall::jump(sf::Vector2f target) {
	sf::FloatRect bounds = rect.getGlobalBounds();
	if (this ->selected) {
		pos = target;
		rect.setPosition(pos);
	}
}

void wall::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}
sf::FloatRect wall::get_hitbox()const {
	return rect.getGlobalBounds();
}
std::string wall::get_type() const {
	return std::string{ "WALL" };
}
sf::Vector2f wall::get_position() const {
	return pos;
}
sf::Color wall::get_color() const {
	return color;
}
sf::Vector2f wall::get_size() const {
	return size;
}

std::string wall::get_pathname() const {
	return std::string("");
}