//
// Created by Ludwig on 2017-06-20.
//

#include <string>
#include "Model.h"
#include "scene/Scene.h"
#include "scene/node/NodeModel.h"
#include "scene/node/Anchor.h"
#include "stage/StageHandler.h"
#include "Progress.h"
#include "MessageBox.h"

Model::Model(Scene &scene, StageHandler &stages, Progress &progress, MessageBox &messages, Mining &mining) :
        m_scene(scene), m_stages(stages), m_progress(progress), m_messages(messages), m_mining(mining) {}

void Model::setBackground(sf::Color color) {
    m_scene.setBackground(color);
}

int Model::place(NodeModel &model, Anchor anchor, int x, int y)
{
    return m_scene.place(model, anchor, x, y);
}

void Model::changeActiveStage(STAGE_ID id) {
    m_scene.clear();
    m_stages.changeActive(*this, id);
}

int Model::level() {
    return m_progress.level();
}

void Model::giveCash(int amount) {
    m_progress.giveCash(amount);
}

int Model::takeCash(int amount, bool requireAll) {
    return m_progress.takeCash(amount, requireAll);
}

void Model::experience(int amount) {
    m_progress.experience(amount);
}

void Model::message(std::string message) {
    m_messages.send(message);
}

void Model::mine(ORE_ID id) {
    m_mining.mine(*this, id);
}
