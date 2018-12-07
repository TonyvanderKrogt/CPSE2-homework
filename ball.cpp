#include "ball.hpp"

ball::ball(sf::Vector2f position, float size) :
	position( position ),
	size( size )
{}

void ball::draw(sf::RenderWindow & window) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
}

void ball::move(sf::Vector2f delta) {
	position += delta;
}

bool ball::BallIntersects(sf::RectangleShape rect, float &xMovBall, float& yMovBall)
{
	sf::CircleShape circle;
	circle.setPosition(position);
	circle.setRadius(size);
	sf::FloatRect rectObj = rect.getGlobalBounds();
	sf::FloatRect circleObj = circle.getGlobalBounds();
	if (circleObj.intersects(rectObj)) {
		sf::Vector2f topCircle(circleObj.left+ (circleObj.width / 2), circleObj.top);
		sf::Vector2f rightCircle(circleObj.left + circleObj.width, circleObj.top + (circleObj.height / 2));
		sf::Vector2f botCircle(circleObj.left + (circleObj.width/2), circleObj.top + circleObj.height);
		sf::Vector2f leftCircle(circleObj.left, circleObj.top + (circleObj.height / 2));
		
		// topside of player 
		if (botCircle.y > rectObj.top
			&& botCircle.y < rectObj.top + rectObj.height
			&& botCircle.x > rectObj.left 
			&& botCircle.x < rectObj.left + rectObj.width )
		{
			std::cout << "TOP "<< botCircle.y << "\n\n";
			yMovBall *= -1;
		}	
		// bottomside of player
		else if (topCircle.y < rectObj.top +rectObj.height
			&& topCircle.y > rectObj.top
			&& topCircle.x > rectObj.left 
			&& topCircle.x < rectObj.left + rectObj.width )
		{
			std::cout << "BOT\n\n";
			yMovBall *= -1;
		}
		// rightside of player
		else if (leftCircle.x > rectObj.left 
			&& leftCircle.x < rectObj.left + rectObj.width
			&& leftCircle.y > rectObj.top 
			&& leftCircle.y < rectObj.top + rectObj.height 
			)
		{
			std::cout << "RIGHT\n\n";
			xMovBall *= -1;
		}
		// leftside of player
		else if (rightCircle.x > rectObj.left 
			&& rightCircle.x < rectObj.left + rectObj.width
			&& rightCircle.y > rectObj.top 
			&& rightCircle.y < rectObj.top + rectObj.height 
			)
		{
			std::cout << "LEFT\n\n";
			xMovBall *= -1;
		}
		else {
			std::cout << "CORNERS\n\n";
			if (botCircle.y + 1 > rectObj.top || topCircle.y - 1 < rectObj.top + rectObj.height) {
				yMovBall *= -1;
			}
			else if (rightCircle.x + 1 > rectObj.left || leftCircle.x - 1 < rectObj.left + rectObj.width) {
				xMovBall *= -1;
			}
			else {
				xMovBall *= -1;
				yMovBall *= -1;
			}
		}
		
	}

	return (circleObj.intersects(rectObj));
}

