#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <iostream>
#include <string>
#include <exception>
#include "exceptions.hpp"
#include <SFML/Graphics.hpp>

class drawable {
protected:
	bool selected = false;

public:

	virtual void draw(sf::RenderWindow & window) const = 0;
	virtual void jump(float x, float y) = 0;
	virtual sf::FloatRect get_hitbox() const = 0;
	virtual void select() {
		selected = true;
	};
	virtual void deselect() {
		selected = false;
	};
	virtual std::string get_type() const = 0;
	virtual sf::Vector2f get_position() const = 0;
	virtual sf::Color get_color() const = 0;
	virtual sf::Vector2f get_size() const = 0;
	virtual std::string get_pathname() const = 0;

};


#endif //DRAWABLE_HPP