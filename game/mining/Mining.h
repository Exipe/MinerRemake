#ifndef MINING_H
#define MINING_H

#include "OreIdentification.h"
#include <array>

class Ore;
class Model;

class Mining
{
private:
    std::array<Ore *, ORE_COUNT> *m_ores;
    Mining(std::array<Ore *, ORE_COUNT> *ores);

public:
    static Mining *build();
    ~Mining();
    void mine(Model &model, ORE_ID id);

};

#endif // MINING_H
