//
// Created by Ludwig on 2017-06-20.
//

#include "Node.h"
#include "NodeModel.h"
#include "Anchor.h"
#include "../../Model.h"
#include "../../stage/Stage.h"
#include <iostream>

Node::Node(NodeModel &model, Anchor anchor, int x, int y) :
        m_model(model), m_anchor(anchor),
        m_x(x), m_y(y), m_width(-1), m_height(-1) {}

void Node::render(Rendering &rendering, int width, int height) {
    int x = realX(m_anchor, m_x, getWidth(), width);
    int y = realY(m_anchor, m_y, getHeight(), height);
    m_model.render(rendering, x, y);
}

void Node::click(int clickX, int clickY, int width, int height, Model &model, Stage &stage, int id) {
    int x = realX(m_anchor, m_x, getWidth(), width);
    int y = realY(m_anchor, m_y, getHeight(), height);

    clickX -= x;
    clickY -= y;

    if(clickX >= 0 && clickX < getWidth() && clickY >= 0 && clickY <= getHeight()) {
        stage.click(model, id, clickX, clickY);
    }
}

int Node::getWidth() {
    return m_width >= 0 ? m_width : m_model.width();
}

int Node::getHeight() {
    return m_height >= 0 ? m_height : m_model.height();
}

void Node::setWidth(int width) {
    m_width = width;
}

void Node::setHeight(int height) {
    m_height = height;
}
