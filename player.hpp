#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "drawable.hpp"

class player : public drawable {
private:
	sf::Vector2f size;
	sf::Vector2f pos;

public:
	player(sf::Vector2f size, sf::Vector2f pos);
	void draw(sf::RenderWindow & window) const override;
	void move(sf::Vector2f delta) override;
	void jump(sf::Vector2f target);
	void jump(float x, float y);
	sf::RectangleShape getPlayer();

};

#endif // !PLAYER_HPP
