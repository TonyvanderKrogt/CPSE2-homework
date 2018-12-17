#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"


class ball : public drawable {
public:
	ball(sf::Vector2f position, sf::Color color, float size);
	void draw(sf::RenderWindow & window) const override;
	void jump(sf::Vector2f target);
	void jump(float x, float y) override;
	sf::FloatRect get_hitbox()const override;
	std::string get_type() const override;
	sf::Vector2f get_position() const override;
	sf::Color get_color() const override;
	sf::Vector2f get_size() const override;
	std::string get_pathname() const override;
private:

	sf::Vector2f position;
	sf::Color color;
	float size;
	sf::CircleShape circle;
};

#endif
