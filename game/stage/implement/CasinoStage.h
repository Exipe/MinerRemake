#ifndef CASINOSTAGE_H
#define CASINOSTAGE_H

#include "../Stage.h"
#include "../../scene/node/implement/SpriteModel.h"

class CasinoTableModel;
class SpriteKeeping;
class FontKeeping;
class TextModel;

class CasinoStage : public Stage
{

private:
    CasinoTableModel *m_casinoTable;
    SpriteModel m_sign;
    TextModel *m_titleText;
    TextModel *m_exitText;
    int m_tableId, m_exitId;

    CasinoStage(CasinoTableModel *casinoTable, Sprite &sign, TextModel *titleText, TextModel *exitText);

public:
    static CasinoStage *build(SpriteKeeping &sprites, FontKeeping &fonts);

    ~CasinoStage();

    void enter(Model &model);

    void click(Model &model, int nodeID, int x, int y);

};

#endif // CASINOSTAGE_H
