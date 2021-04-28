//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_NODE_H
#define MINER_NODE_H

#include "Anchor.h"

class NodeModel;
class Rendering;
class Model;
class Stage;

class Node {

private:
    NodeModel &m_model;
    Anchor m_anchor;
    int m_x, m_y, m_width, m_height;

    int getWidth();

    int getHeight();

public:
    Node(NodeModel &model, Anchor anchor, int x, int y);

    void render(Rendering &rendering, int width, int height);

    void click(int clickX, int clickY, int width, int height, Model &model, Stage &stage, int id);

    void setWidth(int width);

    void setHeight(int height);

};

#endif //MINER_NODE_H
