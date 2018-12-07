#include "ball.hpp"

ball::ball(sf::Vector2f position, float size) :
	position( position ),
	size( size ),
	topCircle(sf::Vector2f{ (size * 2/3),size }),
	botCircle(sf::Vector2f{ (size * 2/3),size }),
	leftCircle(sf::Vector2f{ size,(size * 2/3) }),
	rightCircle(sf::Vector2f{ size,(size * 2/3) })
{}

void ball::draw(sf::RenderWindow & window) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
	window.draw(topCircle);
	window.draw(leftCircle);
	window.draw(botCircle);
	window.draw(rightCircle);
}

void ball::move(sf::Vector2f delta) {
	position += delta;
	hitbox_update();
}

bool ball::BallIntersects(sf::RectangleShape player, float &xMovBall, float& yMovBall)
{
	sf::CircleShape circle;
	circle.setPosition(position);
	circle.setRadius(size);
	sf::FloatRect rectObj = player.getGlobalBounds();
	sf::FloatRect top = topCircle.getGlobalBounds();
	sf::FloatRect bot = botCircle.getGlobalBounds();
	sf::FloatRect left = leftCircle.getGlobalBounds();
	sf::FloatRect right = rightCircle.getGlobalBounds();
	sf::FloatRect circleObj = circle.getGlobalBounds();

	if (top.intersects(rectObj)){
		yMovBall = 3 ;
	}
	if (bot.intersects(rectObj)) {
		yMovBall = -3;
	}

	if (left.intersects(rectObj)) {
		xMovBall = 3;
	}
	if (right.intersects(rectObj)) {
		xMovBall = -3;
	}

	return (circleObj.intersects(rectObj) || top.intersects(rectObj) || bot.intersects(rectObj) || left.intersects(rectObj) || right.intersects(rectObj));
}

void ball::hitbox_update()
{
	topCircle.setPosition(position.x + (size * 2 / 3), position.y);
	leftCircle.setPosition(position.x, position.y + (size * 2 / 3));
	botCircle.setPosition(position.x + (size * 2 / 3), position.y + size);
	rightCircle.setPosition(position.x + size, position.y + (size * 2 / 3));
	color_hitboxes();
}

void ball::color_hitboxes()
{
	topCircle.setFillColor(sf::Color::Yellow);
	leftCircle.setFillColor(sf::Color::Green);
	botCircle.setFillColor(sf::Color::Red);
	rightCircle.setFillColor(sf::Color::White);

}

