//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_STAGEBUILDING_H
#define MINER_STAGEBUILDING_H

#include <array>
#include "StageIdentification.h"
#include "../font/FontKeeping.h"

class Stage;
class SpriteKeeping;

void buildStages(std::array<Stage *, STAGE_COUNT> &stages, SpriteKeeping &sprites, FontKeeping &keeping);

#endif //MINER_STAGEBUILDING_H
