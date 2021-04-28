//
// Created by Ludwig on 2017-06-20.
//

#include <iostream>
#include "Game.h"
#include "Model.h"
#include "sprite/SpriteKeeping.h"
#include "scene/Scene.h"
#include "stage/StageHandler.h"
#include "font/FontKeeping.h"
#include "Progress.h"
#include "MessageBox.h"
#include "scene/node/NodeModel.h"
#include "scene/node/implement/TextModel.h"

Game::Game(Model *model, SpriteKeeping *sprites, FontKeeping *fonts,
           Progress *progress, MessageBox *messages, Mining *mining,
           Scene *scene, StageHandler *stages,
           int *width, int *height) :
        m_model(model), m_sprites(sprites), m_fonts(fonts),
        m_progress(progress), m_messages(messages), m_mining(mining),
        m_scene(scene), m_stages(stages),
        m_width(width), m_height(height) {}

Game *Game::build(int width, int height) {
    int *width_pointer = new int;
    int *height_pointer = new int;
    *width_pointer = width;
    *height_pointer = height;

    SpriteKeeping *sprites = new SpriteKeeping("sprite");
    FontKeeping *fonts = new FontKeeping("font");

    Progress *progress = Progress::load(*fonts);
    MessageBox *messages = MessageBox::build(*fonts);
    Mining *mining = Mining::build();

    Scene *scene = Scene::build(
            progress->cashModel(), progress->levelModel(), messages->textModels(),
            *width_pointer, *height_pointer);
    StageHandler *stages = StageHandler::build(*sprites, *fonts);
    Model *model = new Model(*scene, *stages, *progress, *messages, *mining);

    stages->changeActive(*model, STAGE_ID::MENU);

    return new Game(model, sprites, fonts, progress, messages, mining,
                    scene, stages, width_pointer, height_pointer);
}

Game::~Game() {
    delete m_model;
    delete m_sprites;
    delete m_fonts;
    delete m_progress;
    delete m_messages;
    delete m_mining;
    delete m_scene;
    delete m_stages;
    delete m_width;
    delete m_height;
}

void Game::click(int x, int y) {
    m_stages->click(*m_model, *m_scene, x, y);
}

void Game::size(int width, int height) {
    *m_width = width;
    *m_height = height;
}

void Game::save() {
    m_progress->save();
}

void Game::render(Rendering &rendering) {
    m_scene->render(rendering);
}

