//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_STAGEHANDLER_H
#define MINER_STAGEHANDLER_H

#include <array>
#include "StageIdentification.h"

class Stage;
class Model;
class Scene;
class SpriteKeeping;
class FontKeeping;

class StageHandler {

private:
    std::array<Stage *, STAGE_COUNT> *m_stages;
    Stage* m_active;

    StageHandler(std::array<Stage *, STAGE_COUNT> *stages);

public:
    static StageHandler *build(SpriteKeeping &sprites, FontKeeping &fonts);

    ~StageHandler();

    void changeActive(Model& model, STAGE_ID id);

    void click(Model &model, Scene &scene, int x, int y);

};

#endif //MINER_STAGEBUILDER_H
