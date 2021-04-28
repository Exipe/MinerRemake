//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_RENDERING_H
#define MINER_RENDERING_H

#include <SFML/Graphics.hpp>

class Rendering {

private:
    sf::RenderWindow &m_base;

public:
    Rendering(sf::RenderWindow &base);

    void clear(const sf::Color &color);

    void draw(sf::Drawable &drawable);

};

#endif //MINER_RENDERING_H
