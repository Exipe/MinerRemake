//
// Created by Ludwig on 2017-06-25.
//

#ifndef MINER_MESSAGEBOX_H
#define MINER_MESSAGEBOX_H

#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include "font/FontKeeping.h"
#include "scene/node/implement/TextModel.h"

class MessageBox {

private:
    MessageBox(std::array<TextModel*, 4> *messages);
    std::array<TextModel*, 4> *m_messages;

public:
    static MessageBox *build(FontKeeping &fonts);

    ~MessageBox();

    std::array<TextModel*, 4> &textModels();;

    void send(std::string message);

};


#endif //MINER_MESSAGEBOX_H
