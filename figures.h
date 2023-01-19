#pragma once

class figures {
public:
	void set_count_of_angle(int count_of_angle_inp) 
	{
		count_of_angle = count_of_angle_inp;
	}
	void create_figure() 
	{	
		sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

		sf::ConvexShape convex;
		convex.setPointCount(count_of_angle);
		for (int i = 0; i < count_of_angle; i++)
		{
			std::cout << "input coordinate x of point: ";
			std::cin >> facet_x;
			std::cout << "input coordinate y of point: ";
			std::cin >> facet_y;
			convex.setPoint(i, sf::Vector2f(facet_x, facet_y));
		}
		convex.setFillColor(sf::Color(150, 50, 250));
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(convex);
			window.display();
		}
	}

	int count_of_angle;
	int facet_x;
	int facet_y;
};