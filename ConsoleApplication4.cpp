// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "figures.h"

void draw_figure(int size_of_facet, int count_of_angle) 
{   
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(size_of_facet, count_of_angle);
    sf::CircleShape shape1(size_of_facet);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (count_of_angle != 0) 
        { 
            window.draw(shape); 
        }
        else window.draw(shape1);
        window.display();
    }
}


int main()
{
    int mode=0;
    std::cout << "input mode of draw: 1 - polygon, 2 - regular shape, 3 - circle: ";
    std::cin >> mode;

    switch (mode) {

    case 1:
        figures figure;
        int count_of_angle;
        std::cout << "input count of angle: ";
        std::cin >> count_of_angle;
        figure.set_count_of_angle(count_of_angle);
        figure.create_figure();
        break;

    case 2:
        int count_of_angle1;
        int size_of_facet;
        std::cout << "input count of angle: ";
        std::cin >> count_of_angle1;
        std::cout << "input size of facet: ";
        std::cin >> size_of_facet;
        if ((size_of_facet > 0) && (count_of_angle1 > 2))
        {
            draw_figure(size_of_facet, count_of_angle1);
        }
        else std::cout << "u can't create polygon whitch have zero size of facet or less than 3 count of angle!";
        break;

    case 3:
        int radius;
        std::cout << "input radius of circle: ";
        std::cin >> radius;
        if (radius > 0)
        {
            draw_figure(radius, 0);
        }
        else std::cout << "u can't create circle with zero radius!";
        break;

    default:
        std::cout << "I dont know that command :c";
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
