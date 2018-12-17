#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "drawable.hpp"

class player : public drawable {
private:
	sf::Vector2f size;
	sf::Vector2f pos;
	sf::Color color;
	sf::RectangleShape rect;

public:
	player(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	void draw(sf::RenderWindow & window) const override;
	void jump(sf::Vector2f target) ;
	void jump(float x, float y) override;
	sf::FloatRect get_hitbox()const override;
	std::string get_type() const override;
	sf::Vector2f get_position() const override;
	sf::Color get_color() const override;
	sf::Vector2f get_size() const override;
	std::string get_pathname() const override;

};

#endif // !PLAYER_HPP
