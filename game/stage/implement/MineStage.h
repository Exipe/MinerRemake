//
// Created by Ludwig on 2017-06-25.
//

#ifndef MINER_MINESTAGE_H
#define MINER_MINESTAGE_H

#include "../Stage.h"
#include "../../scene/node/implement/SpriteModel.h"

class TextModel;
class FontKeeping;
class SpriteKeeping;
class Sprite;

class MineStage : public Stage {

private:
    SpriteModel m_sign, m_iron, m_gold, m_pebble1, m_pebble2, m_pebble3;
    TextModel *m_exitText;
    int m_exitID, m_ironID, m_goldID;
    MineStage(Sprite &sign, Sprite &iron, Sprite &gold,
              Sprite &pebble1, Sprite &pebble2, Sprite &pebble3,
              TextModel *exitText);

public:
    static MineStage *build(SpriteKeeping &sprites, FontKeeping &fonts);

    ~MineStage();

    void enter(Model &model);

    void click(Model &model, int nodeID, int x, int y);

};


#endif //MINER_MINESTAGE_H
