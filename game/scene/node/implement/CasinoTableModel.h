#ifndef CASINOTABLEMODEL_H_INCLUDED
#define CASINOTABLEMODEL_H_INCLUDED

#include <random>

#include "../NodeModel.h"
#include "../../../sprite/Sprite.h"

class Rendering;
class FontKeeping;
class SpriteKeeping;
class Text;
class Model;

class CasinoTableModel : public NodeModel {

private:
    static int value(int row, int column);

    const static int GRID_X = 10, GRID_Y = 225;

    Sprite m_table, m_button1, m_button2, m_body, m_faceWinning, m_faceLosing;
    Sprite *m_faceCurrent;

    Text **m_gridText;
    Text *m_betText;
    Text *m_playText;
    Text *m_resultText;

    std::default_random_engine m_generator;
    std::uniform_int_distribution<int> m_distribution;

    int m_bet = 0;

    int m_width, m_height;

    CasinoTableModel(Sprite &table, Sprite &button1, Sprite &button2, Sprite &body, Sprite &faceWinning, Sprite &faceLosing,
                     Text **gridText, Text *betText, Text *playText, Text *resultText);

    void updateBetText();
public:
    static CasinoTableModel *build(SpriteKeeping &sprites, FontKeeping &fonts);

    ~CasinoTableModel();

    void render(Rendering &rendering, int x, int y);

    int width();

    int height();

    void click(Model &model, int x, int y);

    int emptyBet();

};

#endif // CASINOTABLEMODEL_H_INCLUDED
