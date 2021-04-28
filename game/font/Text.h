//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_TEXT_H
#define MINER_TEXT_H

#include <SFML/Graphics.hpp>
#include <string>

class Rendering;

class Text {

private:
    sf::Text *m_base;

    Text(sf::Text *base);

public:
    static Text* create(sf::Font &font, std::string content, int size, sf::Color color);

    ~Text();

    int width();

    int height();

    void set(std::string content);

    std::string get();

    void write(Rendering &rendering, int x, int y);
};


#endif //MINER_TEXT_H
