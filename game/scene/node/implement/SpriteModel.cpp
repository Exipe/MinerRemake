//
// Created by Ludwig on 2017-06-22.
//

#include "SpriteModel.h"
#include "../../../../window/Rendering.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../sprite/Sprite.h"

SpriteModel::SpriteModel(Sprite &sprite) : m_sprite(sprite) {}

void SpriteModel::render(Rendering &rendering, int x, int y) {
    m_sprite.render(rendering, x, y);
}

int SpriteModel::width() {
    return m_sprite.width();
}

int SpriteModel::height() {
    return m_sprite.height();
}