//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_NODEMODEL_H
#define MINER_NODEMODEL_H

class Rendering;

class NodeModel {

public:

    virtual ~NodeModel() {}

    virtual void render(Rendering &rendering, int x, int y) = 0;

    virtual int width() = 0;

    virtual int height() = 0;

};

#endif //MINER_NODEMODEL_H
