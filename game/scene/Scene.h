//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_SCENE_H
#define MINER_SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "node/Anchor.h"
#include "node/Node.h"
#include "node/NodeModel.h"
#include "node/implement/TextModel.h"

class Model;
class Stage;
class Rendering;

class Scene {

private:
    Scene(int &width, int &height, std::array<Node*, 6> *overlay);

    int &m_width, &m_height;
    std::vector<Node> m_nodes;
    std::array<Node*, 6> *m_overlay;
    sf::Color m_background;

public:
    static Scene *build(NodeModel *cashModel, NodeModel *levelModel,
                        std::array<TextModel*, 4> &textModels,
                        int &width, int &height);

    ~Scene();

    void setBackground(sf::Color background);

    int place(NodeModel &model, Anchor anchor, int x, int y);

    void clear();

    void click(Model &model, Stage &stage, int x, int y);

    void render(Rendering &rendering);

};

#endif //MINER_SCENE_H
