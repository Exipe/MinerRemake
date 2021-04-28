//
// Created by Ludwig on 2017-06-22.
//

#include "Sprite.h"

#include "../../window/Rendering.h"

Sprite::Sprite(sf::Sprite *sprite, sf::Texture *texture, int width, int height) :
        m_sprite(sprite), m_texture(texture), m_width(width), m_height(height) {}

Sprite *Sprite::load(std::string path) {
    sf::Sprite *sprite = new sf::Sprite();
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(path);
    sprite->setTexture(*texture);
    sf::Vector2u size = texture->getSize();

    return new Sprite(sprite, texture, size.x, size.y);
}

Sprite::~Sprite() {
    delete m_sprite;
    delete m_texture;
}

int Sprite::width() {
    return m_width;
}

int Sprite::height() {
    return m_height;
}

void Sprite::render(Rendering &rendering, int x, int y) {
    m_sprite->setPosition(x, y);
    rendering.draw(*m_sprite);
}
