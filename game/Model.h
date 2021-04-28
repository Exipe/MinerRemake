//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_MODEL_H
#define MINER_MODEL_H

#include "scene/node/Anchor.h"
#include "stage/StageIdentification.h"
#include "mining/OreIdentification.h"
#include "Mining.h"
#include <SFML/Graphics.hpp>

class Scene;
class StageHandler;
class Progress;
class MessageBox;
class NodeModel;

class Model {

private:
    Scene &m_scene;
    StageHandler &m_stages;
    Progress &m_progress;
    MessageBox &m_messages;
    Mining &m_mining;

public:
    Model(Scene &scene, StageHandler &stages, Progress &progress, MessageBox &messages, Mining &mining);

    void setBackground(sf::Color color);

    int place(NodeModel &model, Anchor anchor, int x = 0, int y = 0);

    void changeActiveStage(STAGE_ID id);

    int level();

    void giveCash(int amount);

    int takeCash(int amount, bool requireAll);

    void experience(int amount);

    void message(std::string message);

    void mine(ORE_ID id);

};

#endif //MINER_MODEL_H
