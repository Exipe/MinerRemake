//
// Created by Ludwig on 2017-06-20.
//

#include "Rendering.h"
#include <SFML/Graphics.hpp>

Rendering::Rendering(sf::RenderWindow &base) :
        m_base(base) {}

void Rendering::clear(const sf::Color &color) {
    m_base.clear(color);
}

void Rendering::draw(sf::Drawable &drawable) {
    m_base.draw(drawable);
}
