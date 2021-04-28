#include "Ore.h"
#include "../Model.h"
#include <string>

Ore::Ore(std::string name, int levelReq, int xpYield, int goldYield) :
    m_name(name), m_levelReq(levelReq), m_xpYield(xpYield), m_goldYield(goldYield) {}

void Ore::mine(Model &model) {
    if(model.level() < m_levelReq) {
        model.message("You need a level of " + std::to_string(m_levelReq) + ".");
        return;
    }

    model.message("You mine some " + m_name + ".");
    model.experience(m_xpYield);
    model.giveCash(m_goldYield);
}
