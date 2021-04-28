//
// Created by Ludwig on 2017-06-20.
//

#include "StageHandler.h"
#include <array>
#include <iostream>
#include "Stage.h"
#include "StageBuilding.h"
#include "../scene/Scene.h"
#include "../sprite/SpriteKeeping.h"

StageHandler::StageHandler(
        std::array<Stage *, STAGE_COUNT> *stages) :
        m_stages(stages), m_active(nullptr) {}

StageHandler * StageHandler::build(SpriteKeeping &sprites, FontKeeping &fonts) {
    const int count = STAGE_COUNT;
    std::array<Stage*, count>* stages = new std::array<Stage*, count>();

    buildStages(*stages, sprites, fonts);

    return new StageHandler(stages);
}

StageHandler::~StageHandler() {
    for (Stage *stage : *m_stages) {
        delete stage;
    }

    delete m_stages;
}

void StageHandler::changeActive(Model &model, STAGE_ID id) {
    if(m_active) {
        m_active->leave(model);
    }
    m_active = m_stages->at(id);
    m_active->enter(model);
}

void StageHandler::click(Model &model, Scene &scene, int x, int y) {
    if(!m_active) {
        return;
    }

    scene.click(model, *m_active, x, y);
}
