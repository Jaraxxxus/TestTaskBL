#include "Game.h"



void Game::run() {
	mechanic meh(p, e, entities);
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Test Game", sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(60);
	font.loadFromFile("fonts/arial.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Red);
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close(); 
				break;
			}
		}
		





		meh.tick(entities);
		//std::cout << entities.size() << " Ent size" << std::endl;
		// Отрисовка окна
		window.clear(sf::Color(250, 220, 100, 0));
		for (auto a : entities)
		{
			window.draw(a->getSprite());

		}




		text.setString(meh.getScore());
		window.draw(text);





		window.display();

	}


}




