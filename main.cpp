#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "player.hpp"

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

int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-05 array of actions\n";
	float playerSizeX = 80.0, playerSizeY = 80.0;
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 },30 };
	wall left_wall{ sf::Vector2f{20.0, 480.0}, sf::Vector2f{0.0, 0.0} };
	wall top_wall{sf::Vector2f{ 640.0, 20.0 }, sf::Vector2f{0.0, 0.0} };
	wall right_wall{sf::Vector2f{ 20.0, 480.0 }, sf::Vector2f{620.0, 0.0} };
	wall bottom_wall{sf::Vector2f{ 640.0, 20.0 }, sf::Vector2f{0.0, 460.0} };
	player player1{ sf::Vector2f{playerSizeX, playerSizeY}, sf::Vector2f{20.0,20.0} };
	
	float xMovBall = -3.0, yMovBall = -3.0, xMovPlayer = 0.0, yMovPlayer = 0.0;
	action actions[] = {
		action([&] { return my_ball.BallIntersects(top_wall.getWall(),xMovBall, yMovBall); },					[&]() {my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action([&] { return my_ball.BallIntersects(left_wall.getWall(),xMovBall, yMovBall); },					[&]() {my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action([&] { return my_ball.BallIntersects(right_wall.getWall(),xMovBall, yMovBall); },				[&]() {my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action([&] { return my_ball.BallIntersects(bottom_wall.getWall(),xMovBall, yMovBall); },				[&]() {my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action([&] { return my_ball.BallIntersects(player1.getPlayer(), xMovBall, yMovBall); },	[&]() { my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action([&] { return true; }, [&]() { my_ball.move(sf::Vector2f(xMovBall,yMovBall)); }),
		action(sf::Keyboard::Left,  [&]() { xMovPlayer = -3.0; yMovPlayer = 0.0; player1.move( sf::Vector2f(xMovPlayer, yMovPlayer)); }),
		action(sf::Keyboard::Right, [&]() { xMovPlayer = +3.0; yMovPlayer = 0.0; player1.move(sf::Vector2f(xMovPlayer,  yMovPlayer)); }),
		action(sf::Keyboard::Up,    [&]() { xMovPlayer = 0.0; yMovPlayer = -3.0; player1.move(sf::Vector2f(xMovPlayer,  yMovPlayer)); }),
		action(sf::Keyboard::Down,  [&]() { xMovPlayer = 0.0; yMovPlayer = +3.0; player1.move(sf::Vector2f(xMovPlayer,  yMovPlayer)); }),
		action(sf::Mouse::Left,     [&]() { player1.jump(sf::Mouse::getPosition(window).x - (playerSizeX / 2),sf::Mouse::getPosition(window).y - (playerSizeY / 2)); })
	};

	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}

		window.clear();
		player1.draw(window);
		my_ball.draw(window);
		left_wall.draw(window);
		top_wall.draw(window);
		right_wall.draw(window);
		bottom_wall.draw(window);
		window.display();

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}

