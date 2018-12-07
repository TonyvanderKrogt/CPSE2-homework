build:
	g++ -std=c++17 player.cpp wall.cpp ball.cpp main.cpp -o Week2 -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

run:
	./Week2
clean:
	rm -f *.o