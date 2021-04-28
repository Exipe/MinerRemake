//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_SPRITE_H
#define MINER_SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

class Rendering;

class Sprite {

private:
    sf::Sprite *m_sprite;
    sf::Texture *m_texture;
    int m_width, m_height;

    Sprite(sf::Sprite *sprite, sf::Texture *texture, int width, int height);

public:
    static Sprite *load(std::string path);

    ~Sprite();

    int width();

    int height();

    void render(Rendering &rendering, int x, int y);

};


#endif //MINER_SPRITE_H
