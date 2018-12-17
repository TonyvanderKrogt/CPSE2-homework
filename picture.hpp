#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"
#include "exceptions.hpp"

class picture : public drawable {
private:
	std::string image;
	sf::Texture texture;
	sf::RectangleShape rect;
public:

	picture(sf::Vector2f pos,std::string image);
	void draw(sf::RenderWindow & window) const override;
	void jump(sf::Vector2f target);
	void jump(float x, float y) override;
	sf::FloatRect get_hitbox()const override;
	std::string get_type() const override;
	sf::Vector2f get_position() const override;
	sf::Color get_color() const override;
	sf::Vector2f get_size() const override;
	std::string get_pathname() const override;

};


#endif // !PICTURE_HPP