//
// Created by Ludwig on 2017-06-22.
//

#include "TextModel.h"
#include "../../../font/Text.h"
#include "../../../font/FontKeeping.h"

TextModel::TextModel(Text *text) : m_text(text) {}

TextModel *TextModel::build(FontKeeping &fonts, std::string fontPath, std::string content, int size, sf::Color color) {
    Text *text = fonts.text(fontPath, content, size, color);
    return new TextModel(text);
}

TextModel::~TextModel() {
    delete m_text;
}

void TextModel::update(std::string content) {
    m_text->set(content);
}

std::string TextModel::content() {
    return m_text->get();
}

void TextModel::render(Rendering &rendering, int x, int y) {
    m_text->write(rendering, x, y);
}

int TextModel::width() {
    return m_text->width();
}

int TextModel::height() {
    return m_text->height();
}
