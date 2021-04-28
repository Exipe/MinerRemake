
#include "CasinoTableModel.h"
#include "../../../../window/Rendering.h"
#include "../../../sprite/Sprite.h"
#include "../../../sprite/SpriteKeeping.h"
#include "../../../font/FontKeeping.h"
#include "../../../font/Text.h"
#include "../../../Model.h"

#include <cmath>
#include <string>
#include <iostream>

int CasinoTableModel::value(int row, int column) {
    int value = 1;

    for(int i = 0; i < column; i++) {
        value *= 100;
    }

    for(int i = 0; i < row; i++) {
        value *= 5;
    }

    return value;
}

CasinoTableModel::CasinoTableModel(Sprite &table, Sprite &button1, Sprite &button2,
                                   Sprite &body, Sprite &faceWinning, Sprite &faceLosing,
                                   Text **gridText, Text *betText, Text *playText, Text *resultText) :
m_table(table), m_button1(button1), m_button2(button2),
m_body(body), m_faceWinning(faceWinning), m_faceLosing(faceLosing),
m_gridText(gridText), m_betText(betText), m_playText(playText), m_resultText(resultText),
m_distribution(1, 100)
{
    m_faceCurrent = &faceLosing;
    m_width = m_table.width();
    m_height = faceLosing.height() + body.height() + table.height();
    updateBetText();
}

CasinoTableModel *CasinoTableModel::build(SpriteKeeping &sprites, FontKeeping &fonts)
{
    Sprite
            &table = sprites.get("casino table.png"),
            &button1 = sprites.get("button1.png"),
            &button2 = sprites.get("button2.png"),
            &body = sprites.get("body.png"),
            &faceWinning = sprites.get("winning.png"),
            &faceLosing = sprites.get("losing.png");

    Text **gridText = new Text*[9];
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            int val = value(y, x);

            std::string textContent = (x < 2 || y < 2) ? "+ " + std::to_string(val) : "RESET";
            Text *text = fonts.text("arial.ttf", textContent, 12, sf::Color::Black);
            gridText[x * 3 + y] = text;
        }
    }

    sf::Color yellow(255, 255, 0);

    Text *betText = fonts.text("arial.ttf", "", 16, yellow);
    Text *playText = fonts.text("arial.ttf", "PLAY 60x2", 16, sf::Color::Black);
    Text *resultText = fonts.text("arial.ttf", "Place your bet.", 16, yellow);

    return new CasinoTableModel(table, button1, button2, body, faceWinning, faceLosing, gridText, betText, playText, resultText);
}

void CasinoTableModel::updateBetText() {
    m_betText->set("Bet: " + std::to_string(m_bet));
}

CasinoTableModel::~CasinoTableModel() {
    for(int ix = 0; ix < 3; ix++) {
        for(int iy = 0; iy < 3; iy++) {
            delete m_gridText[ix * 3 + iy];
        }
    }

    delete m_gridText;
    delete m_betText;
    delete m_playText;
}

void CasinoTableModel::render(Rendering &rendering, int x, int y) {
    int center = x + m_table.width() / 2;
    int drawY = y;

    m_faceCurrent->render(rendering, center - m_faceCurrent->width() / 2, drawY);
    drawY += m_faceCurrent->height();

    m_body.render(rendering, center - m_body.width() / 2, drawY);
    drawY += m_body.height();

    m_table.render(rendering, x, drawY);

    for(int ix = 0; ix < 3; ix++) {
        for(int iy = 0; iy < 3; iy++) {
            int buttonX = x + GRID_X + ix * 65;
            int buttonY = y + GRID_Y + iy * 32;
            m_button1.render(rendering, buttonX, buttonY);

            Text *text = m_gridText[ix * 3 + iy];
            int textX = buttonX + m_button1.width() / 2 - text->width() / 2;
            int textY = buttonY + m_button1.height() / 2 - text->height() / 2;
            text->write(rendering, textX, textY);
        }
    }

    m_betText->write(rendering, x + 10, y + 170);

    int playX = x + 335;
    int playY = y + 170;
    m_button2.render(rendering, playX, playY);

    int playTextX = playX + m_button2.width() / 2 - m_playText->width() / 2;
    int playTextY = playY + m_button2.height() / 2 - m_playText->height() /2;
    m_playText->write(rendering, playTextX, playTextY);

    m_resultText->write(rendering, playX, playY + 100);
}

int CasinoTableModel::width() {
    return m_width;
}

int CasinoTableModel::height() {
    return m_height;
}

void CasinoTableModel::click(Model &model, int x, int y) {
    if(m_bet > 0 && x >= 335 && x < 335 + m_button2.width() && y >= 170 && y < 170 + m_button2.height()) {
        int rolled = m_distribution(m_generator);
        int bet = emptyBet();

        std::string message = " (" + std::to_string(rolled) + ")!";

        if(rolled >= 60) {
            message = "You win" + message;
            m_faceCurrent = &m_faceWinning;
            model.giveCash(bet * 2);
        } else {
            message = "You lose" + message;
            m_faceCurrent = &m_faceLosing;
        }

        m_resultText->set("Result: " + message);
        model.message(message);
        return;
    }

    x -= GRID_X;
    y -= GRID_Y;
    int buttonWidth = 65;
    int buttonHeight = 32;

    if(x < 0 || x >= buttonWidth * 3 || y < 0 || y >= buttonHeight * 3) {
        return;
    }

    x /= buttonWidth;
    y /= buttonHeight;

    if(x == 2 && y == 2) {
        model.giveCash(emptyBet());
        return;
    }

    int added = model.takeCash(value(y, x), false);
    m_bet += added;
    updateBetText();
}

int CasinoTableModel::emptyBet() {
    int previous = m_bet;
    m_bet = 0;
    updateBetText();
    return previous;
}
