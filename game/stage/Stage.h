//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_STAGE_H
#define MINER_STAGE_H

class Model;

class Stage {
public:
    virtual ~Stage() {}

    virtual void enter(Model &model) {}

    virtual void click(Model &model, int nodeID, int x, int y) {}

    virtual void leave(Model &model) {}

};

#endif //MINER_STAGE_H
