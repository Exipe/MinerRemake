//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_TEXTUREDNODE_H
#define MINER_TEXTUREDNODE_H

#include "../NodeModel.h"
#include <string>

class Sprite;
class Rendering;

class SpriteModel : public NodeModel {

private:
    Sprite &m_sprite;

public:
    SpriteModel(Sprite &sprite);

    void render(Rendering &rendering, int x, int y);

    int width();

    int height();

};


#endif //MINER_TEXTUREDNODE_H
