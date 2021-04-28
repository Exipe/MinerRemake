//
// Created by Ludwig on 2017-06-25.
//

#include "Progress.h"
#include "font/FontKeeping.h"
#include "scene/node/implement/TextModel.h"
#include "font/Text.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>

Progress::Progress(TextModel *cashModel, TextModel *levelModel,
                   int level, int experience, int reqExp, int cash) :
m_cashModel(cashModel), m_levelModel(levelModel),
m_level(level), m_experience(experience), m_requiredExperience(reqExp), m_cash(cash) {}

Progress *Progress::load(FontKeeping &fonts) {
    using namespace std;

    ifstream file("save.dat", ios::in | ios::binary);

    int level = 0, experience = 0, requiredExperience = 10, cash = 0;

    if(file.good())
    while(true) {
        char op;
        file.read(&op, 1);

        if(op < 0) {
            break;
        }

        if(op == 0) {
            file.read((char*) &level, 4);
        }

        else if(op == 1) {
            file.read((char*) &experience, 4);
        }

        else if(op == 2) {
            file.read((char*) &requiredExperience, 4);
        }

        else if(op == 3) {
            file.read((char*) &cash, 4);
        }
    }

    file.close();

    std::string font = "arial.ttf";
    std::string levelString = updateLevelText(level, experience, requiredExperience);
    sf::Color levelColor(0, 255, 0);
    std::string cashString = updateCashText(cash);
    sf::Color cashColor(255, 255, 0);
    int size = 15;

    TextModel* levelModel = TextModel::build(fonts, font, levelString, size, levelColor);
    TextModel* cashModel = TextModel::build(fonts, font, cashString, size, cashColor);

    return new Progress(cashModel, levelModel, level, experience, requiredExperience, cash);
}

Progress::~Progress() {
    delete m_cashModel;
    delete m_levelModel;
}

std::string Progress::updateCashText(int cash) {
    return "Cash: " + std::to_string(cash);
}

std::string
Progress::updateLevelText(int level, int experience, int required) {
    std::string slevel = std::to_string(level),
                sexperience = std::to_string(experience),
                srequired = std::to_string(required);

    std::string text = "Level: " + slevel + " (" + sexperience;
    if(level < 50) {
        text += " / " + srequired;
    }
    text += ")";

    return text;
}

TextModel *Progress::cashModel() {
    return m_cashModel;
}

TextModel *Progress::levelModel() {
    return m_levelModel;
}

int Progress::level() {
    return m_level;
}

void Progress::giveCash(int amount) {
    m_cash += amount;
    m_cashModel->update(updateCashText(m_cash));
}

int Progress::takeCash(int amount, bool requireAll) {
    bool enough = !requireAll || amount <= m_cash;

    if(!enough) {
        return 0;
    }

    int taken = std::min(amount, m_cash);

    m_cash -= taken;
    m_cashModel->update(updateCashText(m_cash));

    return taken;
}

void Progress::experience(int amount) {
    m_experience += amount;

    if(m_level < 50 && m_experience >= m_requiredExperience) {
        levelUp();
    }

    std::string levelText =
            updateLevelText(m_level, m_experience, m_requiredExperience);
    m_levelModel->update(levelText);
}

void Progress::levelUp() {
    m_level++;
    m_experience = 0;

    int y = m_level % 10;
    int x = (m_level - y) / 10 + 1;

    m_requiredExperience = 1;
    int additional = y;
    for(int i = 0; i < x; i++) {
        m_requiredExperience *= 10;
        additional *= 5;
    }

    m_requiredExperience += additional;
}

void Progress::save() {
    using namespace std;

    ofstream file("save.dat", ios::out | ios::binary | ios::trunc);

    char op = 0;
    file.write(&op, 1);
    file.write((char*) &m_level, 4);

    op = 1;
    file.write(&op, 1);
    file.write((char*) &m_experience, 4);

    op = 2;
    file.write(&op, 1);
    file.write((char*) &m_requiredExperience, 4);

    op = 3;
    file.write(&op, 1);
    file.write((char*) &m_cash, 4);

    op = -1;
    file.write(&op, 1);

    file.close();
}
