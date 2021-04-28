//
// Created by Ludwig on 2017-06-20.
//

#include "Scene.h"
#include <vector>
#include "node/Node.h"
#include "../stage/Stage.h"
#include "../Model.h"
#include "../../window/Rendering.h"
#include <iostream>

Scene::Scene(int &width, int &height, std::array<Node*, 6> *overlay) :
        m_width(width), m_height(height), m_nodes(), m_overlay(overlay),
        m_background(sf::Color::White) {}

Scene::~Scene() {
    for(Node *node : *m_overlay) {
        delete node;
    }

    delete m_overlay;
}

Scene *Scene::build(NodeModel *cashModel, NodeModel *levelModel,
                    std::array<TextModel*, 4> &textModels,
                    int &width, int &height) {

    std::array<Node*, 6> *overlay = new std::array<Node*, 6>;
    (*overlay)[0] = new Node(*cashModel, Anchor::BOTTOM_LEFT, 70, -65);
    (*overlay)[1] = new Node(*levelModel, Anchor::BOTTOM_LEFT, 70, -40);

    for(int i = 0; i < 4; i++) {
        int y = -40 - i * 25;
        Node* text = new Node(*textModels[i], Anchor::BOTTOM_RIGHT, 0, y);
        text->setWidth(200);
        (*overlay)[i + 2] = text;
    }

    return new Scene(width, height, overlay);
}

int Scene::place(NodeModel &model, Anchor anchor, int x, int y) {
    int id = m_nodes.size();
    m_nodes.push_back(Node(model, anchor, x, y));
    return id;
}

void Scene::setBackground(sf::Color background) {
    m_background = background;
}

void Scene::clear() {
    m_background = sf::Color::White;
    m_nodes.clear();
}

void Scene::click(Model &model, Stage &stage, int x, int y) {
    int id = 0;
    for(Node &node : m_nodes) {
        node.click(x, y, m_width, m_height, model, stage, id++);
    }
}

void Scene::render(Rendering &rendering) {
    rendering.clear(m_background);

    for(Node &node : m_nodes) {
        node.render(rendering, m_width, m_height);
    }

    for(Node *overlay : *m_overlay) {
        overlay->render(rendering, m_width, m_height);
    }
}
