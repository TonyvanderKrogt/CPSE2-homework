#ifndef LINE_HPP
#define LINE_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class line : public drawable {
private:
	sf::Vector2f pos1;
	sf::Color color;
	sf::Vector2f pos2;
	sf::VertexArray lineInfo;
	float diff_pos_y, diff_pos_x;
public: 
	line(sf::Vector2f pos1, sf::Color color, sf::Vector2f pos2 );
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



#endif // !LINE_HPP
