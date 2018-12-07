#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"
#include <iostream>

class ball : public drawable{
public:

	ball(sf::Vector2f position, float size = 30.0);

	void draw(sf::RenderWindow & window) const override;

	void move(sf::Vector2f delta)  override;

	bool BallIntersects(sf::RectangleShape rect, float& xMovBall, float& yMovBall);

	void hitbox_update();

	//void color_hitboxes();
private:

	sf::Vector2f position;
	float size;
	sf::RectangleShape topCircle;
	sf::RectangleShape botCircle;
	sf::RectangleShape leftCircle;
	sf::RectangleShape rightCircle;
};

#endif
