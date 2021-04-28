//
// Created by Ludwig on 2017-06-22.
//

#include <iostream>
#include "Text.h"
#include "../../window/Rendering.h"

Text::Text(sf::Text *base) : m_base(base) {}

Text *Text::create(sf::Font &font, std::string content, int size, sf::Color color) {
    sf::Text *base = new sf::Text();
    base->setFont(font);
    base->setString(content);
    base->setCharacterSize(size);
    base->setFillColor(color);

    return new Text(base);
}

Text::~Text() {
    delete m_base;
}

int Text::width() {
    return m_base->getLocalBounds().width;
}

int Text::height() {
    return m_base->getLocalBounds().height;
}

void Text::set(std::string content) {
    m_base->setString(content);
}

std::string Text::get() {
    return m_base->getString();
}

void Text::write(Rendering &rendering, int x, int y) {
    m_base->setPosition(x, y);
    sf::FloatRect bounds = m_base->getLocalBounds();
    m_base->setOrigin(bounds.left, bounds.top);
    rendering.draw(*m_base);
}
