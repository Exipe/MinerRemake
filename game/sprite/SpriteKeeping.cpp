//
// Created by Ludwig on 2017-06-22.
//

#include "SpriteKeeping.h"
#include "Sprite.h"
#include <iostream>

SpriteKeeping::SpriteKeeping(std::string root) : m_root(root) {}

SpriteKeeping::~SpriteKeeping() {
    for(std::pair<std::string, Sprite*> pair : m_sprites) {
        delete pair.second;
    }
}

Sprite &SpriteKeeping::get(std::string path) {
    if(m_sprites.find(path) == m_sprites.end()) {
        m_sprites[path] = Sprite::load(m_root + "/" + path);
    }

    return *m_sprites[path];
}
