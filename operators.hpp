#include <fstream>
#include <SFML/Graphics.hpp>
#include "exceptions.hpp"
#include <string>

std::ifstream & operator>>(std::ifstream& input, sf::Color & rhs) {
	std::string s;
	input >> s;
	const struct { const char * name; sf::Color color; }colors[]{
		{"black", sf::Color::Black},
		{"white", sf::Color::White},
		{"red", sf::Color::Red},
		{"green", sf::Color::Green},
		{"blue", sf::Color::Blue},
		{"yellow", sf::Color::Yellow},
		{"magenta", sf::Color::Magenta},
		{"cyan", sf::Color::Cyan},
		{"transparent", sf::Color::Transparent}
	};
	for (auto const & color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) {
		throw end_of_file(); 
	}   
	if (c != '(') {
		throw invalid_position(std::string{ c });
	}   
	if (!(input >> rhs.x)) {
		throw invalid_position(std::string{ c });
	}   
	if (!(input >> c)) {
		throw invalid_position(std::string{ c });
	}
	if (!(input >> rhs.y)) {
		throw invalid_position(std::string{ c });
	}
	if (!(input >> c)) {
		throw invalid_position(std::string{ c });
	}   
	if (c != ')') { 
		throw invalid_position(std::string{ c });
	}   
	return input; 
}

std::ofstream & operator<<(std::ofstream & output, const sf::Color & rhs) {
	const struct { const char * name; sf::Color color; } colors[]{
		{ "black",        sf::Color::Black },
		{ "blue",        sf::Color::Blue },
		{ "cyan",        sf::Color::Cyan },
		{ "green",        sf::Color::Green },
		{ "magenta",    sf::Color::Magenta },
		{ "red",        sf::Color::Red },
		{ "transparent",sf::Color::Transparent },
		{ "white",        sf::Color::White },
		{ "yellow",        sf::Color::Yellow }
	};
	for (auto const & color : colors) {
		if (color.color == rhs) {
			output << color.name;
		}
	}
	return output;
}

std::ofstream & operator<<(std::ofstream & output, const sf::Vector2f & rhs) {
	output << '(' << rhs.x << ',' << rhs.y << ')';

	return output;
}

