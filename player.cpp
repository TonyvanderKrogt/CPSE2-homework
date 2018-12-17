#include "player.hpp"
#include <iostream>

player::player(sf::Vector2f size, sf::Vector2f pos,sf::Color color) :
	size(size),
	pos(pos),
	color(color)
{
	rect.setSize(size);
	rect.setPosition(pos);
	rect.setFillColor(color);
}

void player::draw(sf::RenderWindow & window) const
{
	window.draw(rect);
}

void player::jump(sf::Vector2f target) {
	sf::FloatRect bounds = rect.getGlobalBounds();
	if ( this->selected) {
		pos = target;
		rect.setPosition(pos);
	}
}

void player::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}

sf::FloatRect player::get_hitbox()const {
	return rect.getGlobalBounds();
}

std::string player::get_type() const {
	return std::string{ "PLAYER" };
}
sf::Vector2f player::get_position() const {
	return pos;
}
sf::Color player::get_color() const {
	return color;
}
sf::Vector2f player::get_size() const {
	return size;
}
std::string player::get_pathname() const {
	return std::string("");
}