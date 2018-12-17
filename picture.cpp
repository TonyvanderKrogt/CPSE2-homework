#include "picture.hpp"

picture::picture(sf::Vector2f pos, std::string image):
	image(image)
{
	if (!this ->texture.loadFromFile(image)) {
		throw unknown_file();
	}
	rect = sf::RectangleShape(sf::Vector2f(float(this->texture.getSize().x), float(this->texture.getSize().y)));
	rect.setPosition(pos);
	rect.setTexture(&this ->texture);
	
}

void picture::draw(sf::RenderWindow & window)const {

	window.draw(this->rect);
}

void picture::jump(sf::Vector2f target) {

	sf::FloatRect bounds = rect.getGlobalBounds();
	if (this->selected) {
		rect.setPosition(target);
	}
}

void picture::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}

sf::FloatRect picture::get_hitbox()const {
	return rect.getGlobalBounds();
}
std::string picture::get_type() const {
	return std::string{ "PICTURE" };
}
sf::Vector2f picture::get_position() const {
	return rect.getPosition();
}
sf::Color picture::get_color() const {
	return sf::Color::Transparent;
}
sf::Vector2f picture::get_size() const {
	return rect.getSize();
}

std::string picture::get_pathname() const {
	return std::string{image};
}