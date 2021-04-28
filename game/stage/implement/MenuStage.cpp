//
// Created by Ludwig on 2017-06-25.
//

#include "../../scene/node/implement/SpriteModel.h"
#include "../../scene/node/implement/TextModel.h"
#include "MenuStage.h"
#include "../../sprite/SpriteKeeping.h"
#include "../../sprite/Sprite.h"
#include "../../Model.h"

MenuStage::MenuStage(
        Sprite &sign, Sprite &pickaxe, Sprite &pouches,
        TextModel *mineText, TextModel *casinoText) :
        m_sign(sign), m_pickaxe(pickaxe), m_pouches(pouches),
        m_mineText(mineText), m_casinoText(casinoText) {}

MenuStage *MenuStage::build(SpriteKeeping &sprites, FontKeeping &fonts) {
    Sprite
            &sign = sprites.get("sign.png"),
            &pickaxe = sprites.get("pickaxe.png"),
            &pouches = sprites.get("pouches.png");

    int size = 30;
    std::string font = "arial.ttf";
    sf::Color color = sf::Color::Black;
    TextModel
            *mineText = TextModel::build(fonts, font, "Mine", size, color),
            *casinoText = TextModel::build(fonts, font, "Casino", size, color);
    return new MenuStage(sign, pickaxe, pouches, mineText, casinoText);
}

MenuStage::~MenuStage() {
    delete m_mineText;
    delete m_casinoText;
}

void MenuStage::enter(Model &model) {
    model.setBackground(sf::Color(40, 130, 0));

    model.place(m_pouches, Anchor::TOP, 0, 10);
    model.place(m_pouches, Anchor::RIGHT, -10, 0);
    model.place(m_pouches, Anchor::BOTTOM, 0, -10);
    model.place(m_pouches, Anchor::LEFT, 10, 0);

    model.place(m_pickaxe, Anchor::CENTER, 135, 35);
    m_mineID = model.place(m_sign, Anchor::CENTER, 100, 0);
    model.place(*m_mineText, Anchor::CENTER, 100, -30);

    m_casinoID = model.place(m_sign, Anchor::CENTER, -100, 0);
    model.place(*m_casinoText, Anchor::CENTER, -100, -30);
}

void MenuStage::click(Model &model, int nodeID, int x, int y) {
    if(nodeID == m_mineID) {
        model.changeActiveStage(STAGE_ID::MINE);
    }

    if(nodeID == m_casinoID) {
        model.changeActiveStage(STAGE_ID::CASINO);
    }
}
