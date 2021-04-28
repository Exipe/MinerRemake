//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_WINDOW_H
#define MINER_WINDOW_H

#include <SFML/Graphics.hpp>
#include "Rendering.h"

class Game;

class Window {
private:
    sf::RenderWindow &m_base;
    Game &m_game;
    Rendering m_rendering;

public:
    Window(sf::RenderWindow &base, Game &game);

    void update();

    bool isOpen();
};


#endif //MINER_WINDOW_H
