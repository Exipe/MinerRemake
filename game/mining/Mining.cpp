#include "Mining.h"
#include "OreIdentification.h"
#include "Ore.h"

Mining *Mining::build() {
    auto ores = new std::array<Ore *, ORE_COUNT>();

    (*ores)[0] = new Ore("iron", 0, 5, 2);
    (*ores)[1] = new Ore("gold", 10, 10, 10);
    (*ores)[2] = new Ore("diamond", 20, 70, 50);

    return new Mining(ores);
}

Mining::Mining(std::array<Ore *, ORE_COUNT> *ores) : m_ores(ores) {}

Mining::~Mining() {
    for(int i = 0; i < ORE_COUNT; i++) {
        delete (*m_ores)[i];
    }

    delete m_ores;
}

void Mining::mine(Model &model, ORE_ID oreId) {
    Ore ore = *(*m_ores)[oreId];
    ore.mine(model);
}
