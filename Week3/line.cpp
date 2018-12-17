#include "line.hpp"

line::line(sf::Vector2f pos1, sf::Color color, sf::Vector2f pos2) :
	pos1(pos1),
	color(color),
	pos2(pos2),
	lineInfo(sf::Lines, 2)
{
	lineInfo[0].color = color;
	lineInfo[0].position = pos1;
	lineInfo[1].color = color;
	lineInfo[1].position = pos2;
	diff_pos_x = pos2.x - pos1.x;
	diff_pos_y = pos2.y - pos1.y;
}
void line::draw(sf::RenderWindow & window) const
{	
	window.draw(lineInfo);
}

void line::jump(sf::Vector2f target) {
	if (this->selected) {
		pos1 = target;
		pos2 = sf::Vector2f(target.x + diff_pos_x, target.y + diff_pos_y);
		lineInfo[0].position = pos1;
		lineInfo[1].position = pos2;
	}
}

sf::FloatRect line::get_hitbox() const{
	return sf::FloatRect(pos1.x,pos1.y, diff_pos_x, diff_pos_y);
}

void line::jump(float x, float y) {
	jump(sf::Vector2f(
		static_cast<float>(x),
		static_cast<float>(y)
	));
}

std::string line::get_type() const {
	return std::string{ "LINE" };
}
sf::Vector2f line::get_position() const {
	return pos1;
}
sf::Color line::get_color() const {
	return color;
}
sf::Vector2f line::get_size() const {
	return pos2;
}
std::string line::get_pathname() const {
	return std::string("");
}