#include "CasinoStage.h"
#include "../../scene/node/implement/CasinoTableModel.h"
#include "../../font/FontKeeping.h"
#include "../../sprite/SpriteKeeping.h"
#include "../../Model.h"
#include "../../scene/node/implement/SpriteModel.h"
#include "../../scene/node/implement/TextModel.h"

#include <SFML/Graphics.hpp>

CasinoStage::CasinoStage(CasinoTableModel *casinoTable, Sprite &sign, TextModel *titleText, TextModel *exitText) :
    m_casinoTable(casinoTable), m_sign(sign), m_titleText(titleText), m_exitText(exitText) {}

CasinoStage *CasinoStage::build(SpriteKeeping &sprites, FontKeeping &fonts)
{
    CasinoTableModel *casinoTable = CasinoTableModel::build(sprites, fonts);
    Sprite &sign = sprites.get("sign3.png");
    TextModel *titleText = TextModel::build(fonts, "arial.ttf", "THE CASINO", 15, sf::Color::Black);
    TextModel *exitText = TextModel::build(fonts, "arial.ttf", "LEAVE --->", 15, sf::Color::Black);
    return new CasinoStage(casinoTable, sign, titleText, exitText);
}

CasinoStage::~CasinoStage() {
    delete m_casinoTable;
    delete m_titleText;
    delete m_exitText;
}

void CasinoStage::enter(Model &model) {
    model.setBackground(sf::Color(120, 50, 0));

    m_tableId = model.place(*m_casinoTable, Anchor::CENTER);

    model.place(m_sign, Anchor::TOP_RIGHT, -50, 0);
    int signHeight = m_sign.height();
    m_exitId = model.place(m_sign, Anchor::TOP_RIGHT, -50, signHeight);
    model.place(*m_titleText, Anchor::TOP_RIGHT, -55, 40);
    model.place(*m_exitText, Anchor::TOP_RIGHT, -60, signHeight + 40);
}

void CasinoStage::click(Model &model, int nodeID, int x, int y) {
    if(nodeID == m_tableId) {
        m_casinoTable->click(model, x, y);
    }

    if(nodeID == m_exitId) {
        model.giveCash(m_casinoTable->emptyBet());
        model.changeActiveStage(STAGE_ID::MENU);
    }
}
