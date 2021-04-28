//
// Created by Ludwig on 2017-06-25.
//

#include <iostream>
#include "MessageBox.h"

MessageBox::MessageBox(std::array<TextModel *, 4> *messages) : m_messages(messages) {}

MessageBox *MessageBox::build(FontKeeping &fonts) {
    std::array<TextModel*, 4> *messages = new std::array<TextModel*, 4>();
    int size = 15;
    for(int i = 0; i < 4; i++) {
        int alpha = 255 / 4 * (4 - i);
        sf::Color color = sf::Color(255, 0, 0, alpha);
        (*messages)[i] =  TextModel::build(fonts, "arial.ttf", "", size, color);
    }

    return new MessageBox(messages);
}

MessageBox::~MessageBox() {
    for(TextModel *message : *m_messages) {
        delete message;
    }

    delete m_messages;
}

std::array<TextModel *, 4> &MessageBox::textModels() {
    return *m_messages;
}

void MessageBox::send(std::string message) {
    for(int i = 3; i > 0; i--) {
        std::string before = (*m_messages)[i - 1]->content();
        (*m_messages)[i]->update(before);
    }

    (*m_messages)[0]->update(message);
}
