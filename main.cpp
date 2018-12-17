#include <iostream>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "picture.hpp"
#include "operators.hpp"
#include "line.hpp"
#include "exceptions.hpp"
#include <string>

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
		std::function< bool() > condition,
		std::function< void() > work
	) : condition(condition),
		work(work)
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[key]()->bool { return sf::Keyboard::isKeyPressed(key); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition([button]()->bool { return sf::Mouse::isButtonPressed(button); }),
		work(work)
	{}



	void operator()() {
		if (condition()) {
			work();
		}
	}
};

drawable * make_drawable(std::ifstream & input) {
	sf::Vector2f position = { 0,0 };
	std::string name = "";
	input >> position >> name;

	if (name == "CIRCLE") {
		float size;
		sf::Color color;
		input >> color >> size;
		return new ball(position, color, size);
	}
	else if (name == "WALL") {
		sf::Vector2f size;
		sf::Color color;
		input >> color >> size;
		return new wall(size, position, color);
	}
	else if (name == "PLAYER") {
		sf::Vector2f size;
		sf::Color color;
		input >> color >> size;
		return new player(size, position, color);
	}
	else if (name == "PICTURE") {
		std::string image;
		sf::Vector2f size;
		input >> image;
		return new picture(position, image);
	}
	else if (name == "LINE") {
		sf::Vector2f size;
		sf::Color color;
		input >> color >> size;
		return new line(position, color , size);
	}
	else if (name == "") {
		throw end_of_file();
	}
	else {
		throw unknown_shape(name);
	}
}
void screen_object_write(std::ofstream & output, drawable* object) {
	std::string name = object->get_type();
	std::cout << name << '\n';
	if (name == "CIRCLE") {
		output << object->get_position() << ' ' << name;
		output << ' ';
		output << object->get_color() << ' ' << object->get_size().x;
	}
	else if (name == "WALL") {
		output << object->get_position() << ' ';
		output << object->get_type() << ' ';
		output << object->get_color() << ' ';
		output << object->get_size();
	}
	else if (name == "PICTURE") {
		output << object->get_position() << ' ' << object->get_type() << ' ';
		output << object->get_pathname();
	}
	else if (name == "LINE") {
		output << object->get_position() << ' ' << object->get_type() << ' ';
		output << object->get_color() << ' ';
		output << object->get_size();
	}
	else if (name == "PLAYER") {
		output << object->get_position() << ' ' << object->get_type() << ' ';
		output << object->get_color() << ' ';
		output << object->get_size();
	}
	output << '\n';
}
/*(320,240) CIRCLE blue 30
(0.0,0.0) WALL red (20,480)
(110, 50) PICTURE OkHand.jpg
(100,100) LINE blue ( 80 ,20)*/


int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-05 array of actions\n";
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	std::ifstream input("obj.txt");
	std::vector<drawable *> shapes;
	
	try {
		for (;;) {
			shapes.push_back(make_drawable(input));
		}
		std::cout << "TEST\n";
		input.close();
	}
	catch (end_of_file) {
		input.close();
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
		input.close();
		return -1;
	}
	auto my_ball = shapes[0];
	auto wall = shapes[1];
	auto picture = shapes[2];
	auto line = shapes[3];


	action actions[] = {
		action(sf::Mouse::Left,    [&] {for (drawable * object : shapes) object->jump(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y); }),
		action(sf::Mouse::Right,    [&] {for (drawable* object : shapes) object->get_hitbox().contains(sf::Vector2f(sf::Mouse::getPosition(window))) ? object->select() : object->deselect(); }),
	};
	
	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}

		window.clear();
		my_ball->draw(window);
		wall->draw(window);
		picture->draw(window);
		line->draw(window);

		window.display();

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				std::ofstream output("obj.txt");
				for (drawable * object : shapes) {
					screen_object_write(output,object);
				}
				std::cout << "TEST\n";
				output.close();
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}


