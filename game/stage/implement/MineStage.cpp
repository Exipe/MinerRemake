//
// Created by Ludwig on 2017-06-25.
//

#include "MineStage.h"
#include "../../scene/node/implement/SpriteModel.h"
#include "../../scene/node/implement/TextModel.h"
#include "../../sprite/SpriteKeeping.h"
#include "../../sprite/Sprite.h"
#include "../../Model.h"
#include "OreIdentification.h"

MineStage::MineStage(Sprite &sign, Sprite &iron, Sprite &gold,
                     Sprite &pebble1, Sprite &pebble2, Sprite &pebble3,
                     TextModel *exitText) :
        m_sign(sign), m_iron(iron), m_gold(gold),
        m_pebble1(pebble1), m_pebble2(pebble2), m_pebble3(pebble3),
        m_exitText(exitText) {}

MineStage *MineStage::build(SpriteKeeping &sprites, FontKeeping &fonts) {
    Sprite
            &sign = sprites.get("sign.png"),
            &iron = sprites.get("iron ore.png"),
            &gold = sprites.get("gold ore.png"),
            &pebble1 = sprites.get("pebble1.png"),
            &pebble2 = sprites.get("pebble2.png"),
            &pebble3 = sprites.get("pebble3.png");

    int size = 20;
    std::string font = "arial.ttf";
    sf::Color color = sf::Color::Black;
    TextModel *exitText = TextModel::build(fonts, font, "Exit --->", size, color);

    return new MineStage(sign, iron, gold, pebble1, pebble2, pebble3, exitText);
}

MineStage::~MineStage() {
    delete m_exitText;
}

void MineStage::enter(Model &model) {
    model.setBackground(sf::Color(65, 65, 65));

    model.place(m_pebble1, Anchor::TOP_LEFT, 100, 150);
    model.place(m_pebble2, Anchor::BOTTOM_RIGHT, -200, -200);
    model.place(m_pebble3, Anchor::BOTTOM_LEFT, 150, -100);

    m_ironID = model.place(m_iron, Anchor::CENTER, 100, -100);
    m_goldID = model.place(m_gold, Anchor::CENTER, -100, 100);

    m_exitID = model.place(m_sign, Anchor::TOP_RIGHT, -50, 50);
    model.place(*m_exitText, Anchor::TOP_RIGHT, -65, 70);
}

void MineStage::click(Model &model, int nodeID, int x, int y) {
    if(nodeID == m_exitID) {
        model.changeActiveStage(STAGE_ID::MENU);
    }

    if(nodeID == m_ironID) {
        model.mine(ORE_ID::IRON);
    }

    if(nodeID == m_goldID) {
        model.mine(ORE_ID::GOLD);
    }
}

