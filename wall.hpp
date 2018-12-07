#ifndef WALL_HPP
#define WALL_HPP

#include "drawable.hpp"

class wall : public drawable {
private:
	sf::Vector2f size;
	sf::Vector2f pos;
public:
	
	wall(sf::Vector2f size, sf::Vector2f pos);
	void draw(sf::RenderWindow & window) const override;
	void move(sf::Vector2f delta) override;
	sf::RectangleShape getWall();
};


#endif // !WALL_HPP
