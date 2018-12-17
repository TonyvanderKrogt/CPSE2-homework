#include "ball.hpp"

ball::ball(sf::Vector2f position, sf::Color color, float size) :
	position(position),
	color(color),
	size(size)
{
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
}

void ball::draw(sf::RenderWindow & window) const {
	window.draw(circle);

}


void ball::jump(sf::Vector2f target) {
	sf::FloatRect bounds = circle.getGlobalBounds();
	if (this->selected){
		position = target;
		circle.setPosition(position);

	}
	
}

void ball ::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}

sf::FloatRect ball::get_hitbox()const {
	return circle.getGlobalBounds();
}

std::string ball::get_type() const {
	return std::string{ "CIRCLE" };
}
sf::Vector2f ball::get_position() const {
	return position;
}
sf::Color ball::get_color() const {
	return color;
}
sf::Vector2f ball::get_size() const {
	return sf::Vector2f(size, 0);
}
std::string ball::get_pathname() const {
	return std::string("");
}