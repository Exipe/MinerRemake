//
// Created by Ludwig on 2017-06-20.
//

#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../game/Game.h"
#include "Rendering.h"

Window::Window(sf::RenderWindow &base, Game &game) :
        m_base(base), m_game(game), m_rendering(base) {}

void Window::update() {
    sf::Event event;

    while(m_base.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::MouseButtonPressed: {
                sf::Vector2i position = sf::Mouse::getPosition(m_base);
                m_game.click(position.x, position.y);
                break;
            }

            case sf::Event::Resized: {
                int width = event.size.width;
                int height = event.size.height;
                m_base.setView(sf::View(sf::FloatRect(0, 0, width, height)));
                m_game.size(width, height);
                break;
            }

            case sf::Event::Closed:
                m_game.save();
                m_base.close();
                break;
        }
    }

    m_game.render(m_rendering);
    m_base.display();
}

bool Window::isOpen() {
    return m_base.isOpen();
}

