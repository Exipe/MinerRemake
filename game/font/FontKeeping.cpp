//
// Created by Ludwig on 2017-06-22.
//

#include <iostream>
#include "FontKeeping.h"
#include "Text.h"

FontKeeping::FontKeeping(std::string root) : m_root(root) {}

FontKeeping::~FontKeeping() {
    for(std::pair<std::string, sf::Font*> pair : fonts) {
        delete pair.second;
    }
}

Text *FontKeeping::text(std::string fontPath, std::string content, int size, sf::Color color) {
    if(fonts.find(fontPath) == fonts.end()) {
        sf::Font *font = new sf::Font();
        font->loadFromFile(m_root + "/" + fontPath);
        fonts[fontPath] = font;
    }

    return Text::create(*fonts[fontPath], content, size, color);
}
