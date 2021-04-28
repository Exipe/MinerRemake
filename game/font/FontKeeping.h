//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_FONTKEEPER_H
#define MINER_FONTKEEPER_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class Text;

class FontKeeping {
private:
    std::map<std::string, sf::Font*> fonts;
    std::string m_root;

public:
    FontKeeping(std::string root);
    ~FontKeeping();

    Text* text(std::string fontPath, std::string content, int size, sf::Color color);

};


#endif //MINER_FONTKEEPER_H
