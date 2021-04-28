//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_TEXTMODEL_H
#define MINER_TEXTMODEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include "../NodeModel.h"

class Text;
class FontKeeping;

class TextModel : public NodeModel {

private:
    TextModel(Text *text);
    Text *m_text;

public:
    static TextModel *build(FontKeeping &fonts, std::string fontPath, std::string content, int size, sf::Color color);

    ~TextModel();

    void update(std::string content);

    std::string content();

    void render(Rendering &rendering, int x, int y);

    int width();

    int height();
};


#endif //MINER_TEXTMODEL_H
