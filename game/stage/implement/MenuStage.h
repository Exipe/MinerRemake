//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_MENUSTAGE_H
#define MINER_MENUSTAGE_H

#include "../Stage.h"
#include "../../scene/node/implement/SpriteModel.h"

class TextModel;
class Model;
class FontKeeping;
class SpriteKeeping;
class Sprite;

class MenuStage : public Stage {

private:
    SpriteModel m_sign, m_pickaxe, m_pouches;
    TextModel *m_mineText, *m_casinoText;
    int m_mineID, m_casinoID;
    MenuStage(Sprite &sign, Sprite &pickaxe, Sprite &pouches,
              TextModel *mineText, TextModel *casinoText);

public:
    static MenuStage *build(SpriteKeeping &sprites, FontKeeping &fonts);

    ~MenuStage();

    void enter(Model &model);

    void click(Model &model, int nodeID, int x, int y);

};

#endif //MINER_MENUSTAGE_H
