//
// Created by Ludwig on 2017-06-25.
//

#ifndef MINER_PROGRESS_H
#define MINER_PROGRESS_H

class TextModel;
class Text;
class FontKeeping;

#include <string>

class Progress {

private:
    Progress(TextModel *cashModel, TextModel *levelModel, int level, int experience, int reqExp, int cash);

    TextModel *m_cashModel, *m_levelModel;
    int m_level, m_experience, m_requiredExperience, m_cash;

    static std::string updateCashText(int cash);

    static std::string
    updateLevelText(int level, int experience, int required);

    void levelUp();

public:
    static Progress *load(FontKeeping &fonts);

    ~Progress();

    TextModel *cashModel();

    TextModel *levelModel();

    int level();

    void giveCash(int amount);

    int takeCash(int amount, bool requireAll);

    void experience(int amount);

    void save();

};


#endif //MINER_PROGRESS_H
