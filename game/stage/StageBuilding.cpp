//
// Created by Ludwig on 2017-06-20.
//

#include "StageBuilding.h"
#include <array>
#include <iostream>
#include "Stage.h"
#include "StageIdentification.h"
#include "implement/MenuStage.h"
#include "implement/MineStage.h"
#include "../sprite/SpriteKeeping.h"
#include "../font/FontKeeping.h"
#include "implement/CasinoStage.h"

void buildStages(std::array<Stage *, STAGE_COUNT> &stages, SpriteKeeping &sprites, FontKeeping &fonts) {

    stages[0] = MenuStage::build(sprites, fonts);
    stages[1] = MineStage::build(sprites, fonts);
    stages[2] = CasinoStage::build(sprites, fonts);

}
