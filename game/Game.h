//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_GAME_H
#define MINER_GAME_H

class Model;
class SpriteKeeping;
class FontKeeping;
class Progress;
class MessageBox;
class Scene;
class StageHandler;
class Rendering;
class Mining;

class Game {

private:
    Game(Model *model, SpriteKeeping *sprites, FontKeeping *fonts,
         Progress *progress, MessageBox *messages, Mining *mining,
         Scene *scene, StageHandler *stages, int *width, int *height);
    Model *m_model;
    SpriteKeeping *m_sprites;
    FontKeeping *m_fonts;
    Progress *m_progress;
    MessageBox *m_messages;
    Mining *m_mining;
    Scene *m_scene;
    StageHandler *m_stages;
    int *m_width, *m_height;

public:
    static Game* build(int width, int height);

    ~Game();

    void click(int x, int y);

    void size(int width, int height);

    void save();

    void render(Rendering &rendering);
};

#endif //MINER_GAME_H
