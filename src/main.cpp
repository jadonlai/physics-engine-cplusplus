#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"
#include "converter.h"
#include "vector.h"

// Window size in 720p
#define WINDOW_X 1280
#define WINDOW_Y 720

int main()
{
    Converter converter;

    Vector vec1(3.f, 5.f);
    Vector normalized = normalize(vec1);

    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Physics Engine");
    sf::View view;
    view.setCenter(0, 0);
    view.setSize(WINDOW_X / 20, WINDOW_Y / 20);
    window.setView(view);

    // Circle example
    sf::CircleShape shape;
    shape.setRadius(1.f);
    shape.setPosition(0.f, 0.f);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(0.1f);

    // Line examples
    sf::VertexArray line1(sf::LineStrip, 2);
    line1[0].position = sf::Vector2f(0.f, 0.f);
    line1[1].position = converter.ToVector2f(vec1);

    sf::VertexArray line2(sf::LineStrip, 2);
    line2[0].position = sf::Vector2f(0.f, 0.f);
    line2[0].color = sf::Color::Green;
    line2[1].position = converter.ToVector2f(normalized);
    line2[1].color = sf::Color::Green;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(line1);
        window.draw(line2);
        window.display();
    }
}
